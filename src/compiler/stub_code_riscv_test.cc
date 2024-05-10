/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#include "src/globals.h"
#if defined(TARGET_ARCH_RISCV32) || defined(TARGET_ARCH_RISCV64)

#include "src/CODE_entry.h"
#include "src/isolate.h"
#include "src/native_entry.h"
#include "src/native_entry_test.h"
#include "src/object.h"
#include "src/runtime_entry.h"
#include "src/stub_code.h"
#include "src/symbols.h"
#include "src/unit_test.h"

#define __ assembler->

namespace Code {

static Function* CreateFunction(const char* name) {
  const String& class_name =
      String::Handle(Symbols::New(Thread::Current(), "ownerClass"));
  const Script& script = Script::Handle();
  const Library& lib = Library::Handle(Library::New(class_name));
  const Class& owner_class = Class::Handle(
      Class::New(lib, class_name, script, TokenPosition::kNoSource));
  const String& function_name =
      String::ZoneHandle(Symbols::New(Thread::Current(), name));
  const FunctionType& signature = FunctionType::ZoneHandle(FunctionType::New());
  Function& function = Function::ZoneHandle(Function::New(
      signature, function_name, UntaggedFunction::kRegularFunction, true, false,
      false, false, false, owner_class, TokenPosition::kNoSource));
  return &function;
}

// Test calls to stub code which calls into the runtime.
static void GenerateCallToCallRuntimeStub(compiler::Assembler* assembler,
                                          int length) {
  const int argc = 2;
  const Smi& smi_length = Smi::ZoneHandle(Smi::New(length));
  __ EnterDartFrame(0);
  __ PushObject(Object::null_object());  // Push Null obj for return value.
  __ PushObject(smi_length);             // Push argument 1: length.
  __ PushObject(Object::null_object());  // Push argument 2: type arguments.
  ASSERT(kAllocateArrayRuntimeEntry.argument_count() == argc);
  __ CallRuntime(kAllocateArrayRuntimeEntry, argc);
  __ addi(SP, SP, argc * kWordSize);
  __ PopRegister(A0);  // Pop return value from return slot.
  __ LeaveDartFrame();
  __ ret();
}

ISOLATE_UNIT_TEST_CASE(CallRuntimeStubCode) {
  extern const Function& RegisterFakeFunction(const char* name,
                                              const Code& code);
  const int length = 10;
  const char* kName = "Test_CallRuntimeStubCode";
  compiler::ObjectPoolBuilder object_pool_builder;
  compiler::Assembler assembler(&object_pool_builder);
  GenerateCallToCallRuntimeStub(&assembler, length);
  SafepointWriteRwLocker ml(thread, thread->isolate_group()->program_lock());
  const Code& code = Code::Handle(Code::FinalizeCodeAndNotify(
      *CreateFunction("Test_CallRuntimeStubCode"), nullptr, &assembler,
      Code::PoolAttachment::kAttachPool));
  const Function& function = RegisterFakeFunction(kName, code);
  Array& result = Array::Handle();
  result ^= DartEntry::InvokeFunction(function, Object::empty_array());
  EXPECT_EQ(length, result.Length());
}

// Test calls to stub code which calls into a leaf runtime entry.
static void GenerateCallToCallLeafRuntimeStub(compiler::Assembler* assembler,
                                              const char* str_value,
                                              intptr_t lhs_index_value,
                                              intptr_t rhs_index_value,
                                              intptr_t length_value) {
  const String& str = String::ZoneHandle(String::New(str_value, Heap::kOld));
  const Smi& lhs_index = Smi::ZoneHandle(Smi::New(lhs_index_value));
  const Smi& rhs_index = Smi::ZoneHandle(Smi::New(rhs_index_value));
  const Smi& length = Smi::ZoneHandle(Smi::New(length_value));
  __ EnterDartFrame(0);
  {
    compiler::LeafRuntimeScope rt(assembler,
                                  /*frame_size=*/0,
                                  /*preserve_registers=*/false);
    __ LoadObject(A0, str);
    __ LoadObject(A1, lhs_index);
    __ LoadObject(A2, rhs_index);
    __ LoadObject(A3, length);
    rt.Call(kCaseInsensitiveCompareUCS2RuntimeEntry, 4);
  }
  __ LeaveDartFrame();
  __ ret();  // Return value is in A0.
}

ISOLATE_UNIT_TEST_CASE(CallLeafRuntimeStubCode) {
  extern const Function& RegisterFakeFunction(const char* name,
                                              const Code& code);
  const char* str_value = "abAB";
  intptr_t lhs_index_value = 0;
  intptr_t rhs_index_value = 2;
  intptr_t length_value = 2;
  const char* kName = "Test_CallLeafRuntimeStubCode";
  compiler::ObjectPoolBuilder object_pool_builder;
  compiler::Assembler assembler(&object_pool_builder);
  GenerateCallToCallLeafRuntimeStub(&assembler, str_value, lhs_index_value,
                                    rhs_index_value, length_value);
  SafepointWriteRwLocker ml(thread, thread->isolate_group()->program_lock());
  const Code& code = Code::Handle(Code::FinalizeCodeAndNotify(
      *CreateFunction("Test_CallLeafRuntimeStubCode"), nullptr, &assembler,
      Code::PoolAttachment::kAttachPool));
  if (FLAG_disassemble) {
    OS::PrintErr("Disassemble:\n");
    code.Disassemble();
  }
  const Function& function = RegisterFakeFunction(kName, code);
  Instance& result = Instance::Handle();
  result ^= DartEntry::InvokeFunction(function, Object::empty_array());
  EXPECT_EQ(Bool::True().ptr(), result.ptr());
}

}  // namespace dart

#endif  // defined TARGET_ARCH_RISCV
