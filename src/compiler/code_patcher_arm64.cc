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

#include "src/globals.h"  // Needed here to get TARGET_ARCH_ARM64.
#if defined(TARGET_ARCH_ARM64)

#include "src/code_patcher.h"
#include "src/cpu.h"
#include "src/instructions.h"
#include "src/object.h"

namespace Code {

class PoolPointerCall : public ValueObject {
 public:
  PoolPointerCall(uword pc, const Code& code)
      : end_(pc), object_pool_(ObjectPool::Handle(code.GetObjectPool())) {
    // Last instruction: blr lr.
    ASSERT(*(reinterpret_cast<uint32_t*>(end_) - 1) == 0xd63f03c0);
    InstructionPattern::DecodeLoadWordFromPool(end_ - 2 * Instr::kInstrSize,
                                               &reg_, &index_);
  }

  intptr_t pp_index() const { return index_; }

  CodePtr Target() const {
    return static_cast<CodePtr>(object_pool_.ObjectAt(pp_index()));
  }

  void SetTarget(const Code& target) const {
    object_pool_.SetObjectAt(pp_index(), target);
    // No need to flush the instruction cache, since the code is not modified.
  }

 private:
  static constexpr int kCallPatternSize = 3 * Instr::kInstrSize;
  uword end_;
  const ObjectPool& object_pool_;
  Register reg_;
  intptr_t index_;
  DISALLOW_IMPLICIT_CONSTRUCTORS(PoolPointerCall);
};

CodePtr CodePatcher::GetStaticCallTargetAt(uword return_address,
                                           const Code& code) {
  ASSERT(code.ContainsInstructionAt(return_address));
  PoolPointerCall call(return_address, code);
  return call.Target();
}

void CodePatcher::PatchStaticCallAt(uword return_address,
                                    const Code& code,
                                    const Code& new_target) {
  PatchPoolPointerCallAt(return_address, code, new_target);
}

void CodePatcher::PatchPoolPointerCallAt(uword return_address,
                                         const Code& code,
                                         const Code& new_target) {
  ASSERT(code.ContainsInstructionAt(return_address));
  PoolPointerCall call(return_address, code);
  call.SetTarget(new_target);
}

void CodePatcher::InsertDeoptimizationCallAt(uword start) {
  UNREACHABLE();
}

CodePtr CodePatcher::GetInstanceCallAt(uword return_address,
                                       const Code& caller_code,
                                       Object* data) {
  ASSERT(caller_code.ContainsInstructionAt(return_address));
  ICCallPattern call(return_address, caller_code);
  if (data != nullptr) {
    *data = call.Data();
  }
  return call.TargetCode();
}

void CodePatcher::PatchInstanceCallAt(uword return_address,
                                      const Code& caller_code,
                                      const Object& data,
                                      const Code& target) {
  auto thread = Thread::Current();
  thread->isolate_group()->RunWithStoppedMutators([&]() {
    PatchInstanceCallAtWithMutatorsStopped(thread, return_address, caller_code,
                                           data, target);
  });
}

void CodePatcher::PatchInstanceCallAtWithMutatorsStopped(
    Thread* thread,
    uword return_address,
    const Code& caller_code,
    const Object& data,
    const Code& target) {
  ASSERT(caller_code.ContainsInstructionAt(return_address));
  ICCallPattern call(return_address, caller_code);
  call.SetData(data);
  call.SetTargetCode(target);
}

FunctionPtr CodePatcher::GetUnoptimizedStaticCallAt(uword return_address,
                                                    const Code& code,
                                                    ICData* ic_data_result) {
  ASSERT(code.ContainsInstructionAt(return_address));
  ICCallPattern static_call(return_address, code);
  ICData& ic_data = ICData::Handle();
  ic_data ^= static_call.Data();
  if (ic_data_result != nullptr) {
    *ic_data_result = ic_data.ptr();
  }
  return ic_data.GetTargetAt(0);
}

void CodePatcher::PatchSwitchableCallAt(uword return_address,
                                        const Code& caller_code,
                                        const Object& data,
                                        const Code& target) {
  auto thread = Thread::Current();
  // Ensure all threads are suspended as we update data and target pair.
  thread->isolate_group()->RunWithStoppedMutators([&]() {
    PatchSwitchableCallAtWithMutatorsStopped(thread, return_address,
                                             caller_code, data, target);
  });
}

void CodePatcher::PatchSwitchableCallAtWithMutatorsStopped(
    Thread* thread,
    uword return_address,
    const Code& caller_code,
    const Object& data,
    const Code& target) {
  if (FLAG_precompiled_mode) {
    BareSwitchableCallPattern call(return_address);
    call.SetData(data);
    call.SetTarget(target);
  } else {
    SwitchableCallPattern call(return_address, caller_code);
    call.SetData(data);
    call.SetTarget(target);
  }
}

uword CodePatcher::GetSwitchableCallTargetEntryAt(uword return_address,
                                                  const Code& caller_code) {
  if (FLAG_precompiled_mode) {
    BareSwitchableCallPattern call(return_address);
    return call.target_entry();
  } else {
    SwitchableCallPattern call(return_address, caller_code);
    return call.target_entry();
  }
}

ObjectPtr CodePatcher::GetSwitchableCallDataAt(uword return_address,
                                               const Code& caller_code) {
  if (FLAG_precompiled_mode) {
    BareSwitchableCallPattern call(return_address);
    return call.data();
  } else {
    SwitchableCallPattern call(return_address, caller_code);
    return call.data();
  }
}

void CodePatcher::PatchNativeCallAt(uword return_address,
                                    const Code& caller_code,
                                    NativeFunction target,
                                    const Code& trampoline) {
  Thread::Current()->isolate_group()->RunWithStoppedMutators([&]() {
    ASSERT(caller_code.ContainsInstructionAt(return_address));
    NativeCallPattern call(return_address, caller_code);
    call.set_target(trampoline);
    call.set_native_function(target);
  });
}

CodePtr CodePatcher::GetNativeCallAt(uword return_address,
                                     const Code& caller_code,
                                     NativeFunction* target) {
  ASSERT(caller_code.ContainsInstructionAt(return_address));
  NativeCallPattern call(return_address, caller_code);
  *target = call.native_function();
  return call.target();
}

}  // namespace dart

#endif  // defined TARGET_ARCH_ARM64
