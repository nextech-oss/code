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

#ifndef RUNTIME_VM_STACK_FRAME_ARM_H_
#define RUNTIME_VM_STACK_FRAME_ARM_H_

#if !defined(RUNTIME_VM_STACK_FRAME_H_)
#error Do not include stack_frame_arm.h directly; use stack_frame.h instead.
#endif

namespace Code {

/* ARM Dart Frame Layout

               |                    | <- TOS
Callee frame   | ...                |
               | saved PP           |    (PP of current frame)
               | code object        |
               | saved FP           |    (FP of current frame)
               | saved LR           |    (PC of current frame)
               +--------------------+
Current frame  | ...               T| <- SP of current frame
               | first local       T|
               | caller's PP       T|
               | code object       T|    (current frame's code object)
               | caller's FP        | <- FP of current frame
               | caller's LR        |    (PC of caller frame)
               +--------------------+
Caller frame   | last parameter     | <- SP of caller frame
               |  ...               |

               T against a slot indicates it needs to be traversed during GC.
*/

static constexpr int kDartFrameFixedSize = 4;  // PP, FP, LR, PC marker.
static constexpr int kSavedPcSlotFromSp = -1;

static constexpr int kFirstObjectSlotFromFp =
    -1;  // Used by GC to traverse stack.
static constexpr int kLastFixedObjectSlotFromFp = -2;

static constexpr int kFirstLocalSlotFromFp = -3;
static constexpr int kSavedCallerPpSlotFromFp = -2;
static constexpr int kPcMarkerSlotFromFp = -1;
static constexpr int kSavedCallerFpSlotFromFp = 0;
static constexpr int kSavedCallerPcSlotFromFp = 1;
static constexpr int kParamEndSlotFromFp = 1;  // One slot past last parameter.
static constexpr int kCallerSpSlotFromFp = 2;
static constexpr int kLastParamSlotFromEntrySp = 0;

// Entry and exit frame layout.
#if defined(CODE_TARGET_OS_MACOS) || defined(CODE_TARGET_OS_MACOS_IOS)
static constexpr int kExitLinkSlotFromEntryFp = -27;
COMPILE_ASSERT(kAbiPreservedCpuRegCount == 6);
COMPILE_ASSERT(kAbiPreservedFpuRegCount == 4);
#else
static constexpr int kExitLinkSlotFromEntryFp = -28;
COMPILE_ASSERT(kAbiPreservedCpuRegCount == 7);
COMPILE_ASSERT(kAbiPreservedFpuRegCount == 4);
#endif

// For FFI native -> Dart callbacks, the number of stack slots between arguments
// passed on stack and arguments saved in callback prologue.
//
// 2 = return address (1) + saved frame pointer (1).
//
// If NativeCallbackTrampolines::Enabled(), then
// kNativeCallbackTrampolineStackDelta must be added as well.
constexpr intptr_t kCallbackSlotsBeforeSavedArguments = 2;

// For FFI calls passing in TypedData, we save it on the stack before entering
// a Dart frame. This denotes how to get to the backed up typed data.
//
// Note: This is not kCallerSpSlotFromFp on arm.
//
// [fp] holds callers fp, [fp+4] holds callers lr, [fp+8] is space for
// return address, [fp+12] is our pushed TypedData pointer.
static constexpr int kFfiCallerTypedDataSlotFromFp = kCallerSpSlotFromFp + 1;

}  // namespace dart

#endif  // RUNTIME_VM_STACK_FRAME_ARM_H_
