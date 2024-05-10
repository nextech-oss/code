#include "src/native_entry.h"

#include "include/code_api.h"

#include "src/bootstrap.h"
#include "src/code_patcher.h"
#include "src/code_api_impl.h"
#include "src/code_api_state.h"
#include "src/heap/safepoint.h"
#include "src/native_symbol.h"
#include "src/object_store.h"
#include "src/reusable_handles.h"
#include "src/stack_frame.h"
#include "src/symbols.h"
#include "src/tags.h"

namespace Code {

void DartNativeThrowTypeArgumentCountException(int num_type_args,
                                               int num_type_args_expected) {
  const String& error = String::Handle(String::NewFormatted(
      "Wrong number of type arguments (%i), expected %i type arguments",
      num_type_args, num_type_args_expected));
  Exceptions::ThrowArgumentError(error);
}

void DartNativeThrowArgumentException(const Instance& instance) {
  const Array& __args__ = Array::Handle(Array::New(1));
  __args__.SetAt(0, instance);
  Exceptions::ThrowByType(Exceptions::kArgument, __args__);
}

NativeFunction NativeEntry::ResolveNative(const Library& library,
                                          const String& function_name,
                                          int number_of_arguments,
                                          bool* auto_setup_scope) {
  // Now resolve the native function to the corresponding native entrypoint.
  if (library.native_entry_resolver() == nullptr) {
    // Native methods are not allowed in the library to which this
    // class belongs in.
    return nullptr;
  }
  CODE_NativeFunction native_function = nullptr;
  {
    Thread* T = Thread::Current();
    Api::Scope api_scope(T);
    CODE_Handle api_function_name = Api::NewHandle(T, function_name.ptr());
    {
      CODE_NativeEntryResolver resolver = library.native_entry_resolver();
      TransitionVMToNative transition(T);
      native_function =
          resolver(api_function_name, number_of_arguments, auto_setup_scope);
    }
  }
  return reinterpret_cast<NativeFunction>(native_function);
}

const uint8_t* NativeEntry::ResolveSymbolInLibrary(const Library& library,
                                                   uword pc) {
  CODE_NativeEntrySymbol symbol_resolver =
      library.native_entry_symbol_resolver();
  if (symbol_resolver == nullptr) {
    // Cannot reverse lookup native entries.
    return nullptr;
  }
  return symbol_resolver(reinterpret_cast<CODE_NativeFunction>(pc));
}

const uint8_t* NativeEntry::ResolveSymbol(uword pc) {
  Thread* thread = Thread::Current();
  REUSABLE_GROWABLE_OBJECT_ARRAY_HANDLESCOPE(thread);
  GrowableObjectArray& libs = reused_growable_object_array_handle.Handle();
  libs = thread->isolate_group()->object_store()->libraries();
  ASSERT(!libs.IsNull());
  intptr_t num_libs = libs.Length();
  for (intptr_t i = 0; i < num_libs; i++) {
    REUSABLE_LIBRARY_HANDLESCOPE(thread);
    Library& lib = reused_library_handle.Handle();
    lib ^= libs.At(i);
    ASSERT(!lib.IsNull());
    const uint8_t* r = ResolveSymbolInLibrary(lib, pc);
    if (r != nullptr) {
      return r;
    }
  }
  return nullptr;
}

void NativeEntry::MaybePropagateError(NativeArguments* arguments) {
  Thread* thread = arguments->thread();

  // We must not access NativeArguments or the result's header under
  // the kThreadInNative state.
  ASSERT(thread->execution_state() == Thread::kThreadInGenerated);
  ObjectPtr retval = arguments->ReturnValue();
  if (UNLIKELY(retval->IsHeapObject() &&
               IsErrorClassId(retval->GetClassId()))) {
    thread->UnwindScopes(thread->top_exit_frame_info());

    TransitionGeneratedToVM transition(thread);

    // The thread->zone() is different here than before we unwound.
    const Object& error =
        Object::Handle(thread->zone(), arguments->ReturnValue());
    Exceptions::PropagateError(Error::Cast(error));
    UNREACHABLE();
  }
}

uword NativeEntry::BootstrapNativeCallWrapperEntry() {
  uword entry =
      reinterpret_cast<uword>(NativeEntry::BootstrapNativeCallWrapper);
#if defined(USING_SIMULATOR)
  entry = Simulator::RedirectExternalReference(
      entry, Simulator::kNativeCallWrapper,
      NativeEntry::kNumCallWrapperArguments);
#endif
  return entry;
}

void NativeEntry::BootstrapNativeCallWrapper(CODE_NativeArguments args,
                                             CODE_NativeFunction func) {
  CHECK_STACK_ALIGNMENT;
  if (func == LinkNativeCall) {
    func(args);
    return;
  }

  NativeArguments* arguments = reinterpret_cast<NativeArguments*>(args);
  // Tell MemorySanitizer 'arguments' is initialized by generated code.
  MSAN_UNPOISON(arguments, sizeof(*arguments));
  {
    Thread* thread = arguments->thread();
    ASSERT(thread == Thread::Current());
    TransitionGeneratedToVM transition(thread);
    StackZone zone(thread);
    // Be careful holding return_value_unsafe without a handle here.
    // A return of Object::sentinel means the return value has already
    // been set.
    ObjectPtr return_value_unsafe = reinterpret_cast<BootstrapNativeFunction>(
        func)(thread, zone.GetZone(), arguments);
    if (return_value_unsafe != Object::sentinel().ptr()) {
      ASSERT(return_value_unsafe->IsDartInstance());
      arguments->SetReturnUnsafe(return_value_unsafe);
    }
    DEOPTIMIZE_ALOT;
  }
}

uword NativeEntry::NoScopeNativeCallWrapperEntry() {
  uword entry = reinterpret_cast<uword>(NativeEntry::NoScopeNativeCallWrapper);
#if defined(USING_SIMULATOR)
  entry = Simulator::RedirectExternalReference(
      entry, Simulator::kNativeCallWrapper,
      NativeEntry::kNumCallWrapperArguments);
#endif
  return entry;
}

void NativeEntry::NoScopeNativeCallWrapper(CODE_NativeArguments args,
                                           CODE_NativeFunction func) {
  CHECK_STACK_ALIGNMENT;
  NoScopeNativeCallWrapperNoStackCheck(args, func);
}

void NativeEntry::NoScopeNativeCallWrapperNoStackCheck(
    CODE_NativeArguments args,
    CODE_NativeFunction func) {
  NativeArguments* arguments = reinterpret_cast<NativeArguments*>(args);
  // Tell MemorySanitizer 'arguments' is initialized by generated code.
  MSAN_UNPOISON(arguments, sizeof(*arguments));
  Thread* thread = arguments->thread();
  ASSERT(thread->execution_state() == Thread::kThreadInGenerated);
  {
    TransitionGeneratedToNative transition(thread);
    func(args);
  }
  MaybePropagateError(arguments);
  ASSERT(thread->execution_state() == Thread::kThreadInGenerated);
}

uword NativeEntry::AutoScopeNativeCallWrapperEntry() {
  uword entry =
      reinterpret_cast<uword>(NativeEntry::AutoScopeNativeCallWrapper);
#if defined(USING_SIMULATOR)
  entry = Simulator::RedirectExternalReference(
      entry, Simulator::kNativeCallWrapper,
      NativeEntry::kNumCallWrapperArguments);
#endif
  return entry;
}

void NativeEntry::AutoScopeNativeCallWrapper(CODE_NativeArguments args,
                                             CODE_NativeFunction func) {
  CHECK_STACK_ALIGNMENT;
  AutoScopeNativeCallWrapperNoStackCheck(args, func);
}

void NativeEntry::AutoScopeNativeCallWrapperNoStackCheck(
    CODE_NativeArguments args,
    CODE_NativeFunction func) {
  NativeArguments* arguments = reinterpret_cast<NativeArguments*>(args);
  // Tell MemorySanitizer 'arguments' is initialized by generated code.
  MSAN_UNPOISON(arguments, sizeof(*arguments));
  Thread* thread = arguments->thread();
  ASSERT(thread->execution_state() == Thread::kThreadInGenerated);
  {
    Isolate* isolate = thread->isolate();
    ApiState* state = isolate->group()->api_state();
    ASSERT(state != nullptr);
    TRACE_NATIVE_CALL("0x%" Px "", reinterpret_cast<uintptr_t>(func));
    thread->EnterApiScope();
    {
      TransitionGeneratedToNative transition(thread);
      func(args);
    }
    MaybePropagateError(arguments);
    thread->ExitApiScope();
    DEOPTIMIZE_ALOT;
  }
  ASSERT(thread->execution_state() == Thread::kThreadInGenerated);
}

static NativeFunction ResolveNativeFunction(Zone* zone,
                                            const Function& func,
                                            bool* is_bootstrap_native,
                                            bool* is_auto_scope) {
  const Class& cls = Class::Handle(zone, func.Owner());
  const Library& library = Library::Handle(zone, cls.library());

  *is_bootstrap_native =
      Bootstrap::IsBootstrapResolver(library.native_entry_resolver());

  const String& native_name = String::Handle(zone, func.native_name());
  ASSERT(!native_name.IsNull());

  const int num_params = NativeArguments::ParameterCountForResolution(func);
  NativeFunction native_function = NativeEntry::ResolveNative(
      library, native_name, num_params, is_auto_scope);
  if (native_function == nullptr) {
    FATAL("Failed to resolve native function '%s' in '%s'\n",
          native_name.ToCString(), func.ToQualifiedCString());
  }
  return native_function;
}

uword NativeEntry::LinkNativeCallEntry() {
  uword entry = reinterpret_cast<uword>(NativeEntry::LinkNativeCall);
  return entry;
}

void NativeEntry::LinkNativeCall(CODE_NativeArguments args) {
  CHECK_STACK_ALIGNMENT;
  NativeArguments* arguments = reinterpret_cast<NativeArguments*>(args);
  // Tell MemorySanitizer 'arguments' is initialized by generated code.
  MSAN_UNPOISON(arguments, sizeof(*arguments));
  TRACE_NATIVE_CALL("%s", "LinkNative");

  NativeFunction target_function = nullptr;
  bool is_bootstrap_native = false;
  bool is_auto_scope = true;

  {
    TransitionGeneratedToVM transition(arguments->thread());
    StackZone stack_zone(arguments->thread());
    Zone* zone = stack_zone.GetZone();

    DartFrameIterator iterator(arguments->thread(),
                               StackFrameIterator::kNoCrossThreadIteration);
    StackFrame* caller_frame = iterator.NextFrame();

    Code& code = Code::Handle(zone, caller_frame->LookupDartCode());
    Function& func = Function::Handle(zone, code.function());

    if (FLAG_trace_natives) {
      THR_Print("Resolving native target for %s\n", func.ToCString());
    }

    target_function =
        ResolveNativeFunction(arguments->thread()->zone(), func,
                              &is_bootstrap_native, &is_auto_scope);
    ASSERT(target_function != nullptr);

#if defined(DEBUG)
    NativeFunction current_function = nullptr;
    const Code& current_trampoline =
        Code::Handle(zone, CodePatcher::GetNativeCallAt(
                               caller_frame->pc(), code, &current_function));
    // Some other isolate(with code being shared in AOT) might have updated
    // target function/trampoline already.
    ASSERT(current_function ==
               reinterpret_cast<NativeFunction>(LinkNativeCall) ||
           current_function == target_function);
    ASSERT(current_trampoline.ptr() == StubCode::CallBootstrapNative().ptr() ||
           current_function == target_function);
#endif

    NativeFunction patch_target_function = target_function;
    Code& trampoline = Code::Handle(zone);
    if (is_bootstrap_native) {
      trampoline = StubCode::CallBootstrapNative().ptr();
    } else if (is_auto_scope) {
      trampoline = StubCode::CallAutoScopeNative().ptr();
    } else {
      trampoline = StubCode::CallNoScopeNative().ptr();
    }
    CodePatcher::PatchNativeCallAt(caller_frame->pc(), code,
                                   patch_target_function, trampoline);

    if (FLAG_trace_natives) {
      THR_Print("    -> %p (%s)\n", target_function,
                is_bootstrap_native ? "bootstrap" : "non-bootstrap");
    }
  }

  // Tail-call resolved target.
  if (is_bootstrap_native) {
    NativeEntry::BootstrapNativeCallWrapper(
        args, reinterpret_cast<CODE_NativeFunction>(target_function));
  } else if (is_auto_scope) {
    // Because this call is within a compilation unit, Clang doesn't respect
    // the ABI alignment here.
    NativeEntry::AutoScopeNativeCallWrapperNoStackCheck(
        args, reinterpret_cast<CODE_NativeFunction>(target_function));
  } else {
    // Because this call is within a compilation unit, Clang doesn't respect
    // the ABI alignment here.
    NativeEntry::NoScopeNativeCallWrapperNoStackCheck(
        args, reinterpret_cast<CODE_NativeFunction>(target_function));
  }
}

#if !defined(CODE_PRECOMPILED_RUNTIME)

// Note: not GC safe. Use with care.
NativeEntryData::Payload* NativeEntryData::FromTypedArray(TypedDataPtr data) {
  return reinterpret_cast<Payload*>(data->untag()->data());
}

MethodRecognizer::Kind NativeEntryData::kind() const {
  return FromTypedArray(data_.ptr())->kind;
}

void NativeEntryData::set_kind(MethodRecognizer::Kind value) const {
  FromTypedArray(data_.ptr())->kind = value;
}

MethodRecognizer::Kind NativeEntryData::GetKind(TypedDataPtr data) {
  return FromTypedArray(data)->kind;
}

NativeFunctionWrapper NativeEntryData::trampoline() const {
  return FromTypedArray(data_.ptr())->trampoline;
}

void NativeEntryData::set_trampoline(NativeFunctionWrapper value) const {
  FromTypedArray(data_.ptr())->trampoline = value;
}

NativeFunctionWrapper NativeEntryData::GetTrampoline(TypedDataPtr data) {
  return FromTypedArray(data)->trampoline;
}

NativeFunction NativeEntryData::native_function() const {
  return FromTypedArray(data_.ptr())->native_function;
}

void NativeEntryData::set_native_function(NativeFunction value) const {
  FromTypedArray(data_.ptr())->native_function = value;
}

NativeFunction NativeEntryData::GetNativeFunction(TypedDataPtr data) {
  return FromTypedArray(data)->native_function;
}

intptr_t NativeEntryData::argc_tag() const {
  return FromTypedArray(data_.ptr())->argc_tag;
}

void NativeEntryData::set_argc_tag(intptr_t value) const {
  FromTypedArray(data_.ptr())->argc_tag = value;
}

intptr_t NativeEntryData::GetArgcTag(TypedDataPtr data) {
  return FromTypedArray(data)->argc_tag;
}

TypedDataPtr NativeEntryData::New(MethodRecognizer::Kind kind,
                                  NativeFunctionWrapper trampoline,
                                  NativeFunction native_function,
                                  intptr_t argc_tag) {
  const TypedData& data = TypedData::Handle(
      TypedData::New(kTypedDataUint8ArrayCid, sizeof(Payload), Heap::kOld));
  NativeEntryData native_entry(data);
  native_entry.set_kind(kind);
  native_entry.set_trampoline(trampoline);
  native_entry.set_native_function(native_function);
  native_entry.set_argc_tag(argc_tag);
  return data.ptr();
}

#endif  // !defined(CODE_PRECOMPILED_RUNTIME)

}  // namespace dart
