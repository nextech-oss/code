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

#ifndef RUNTIME_VM_FRAME_LAYOUT_H_
#define RUNTIME_VM_FRAME_LAYOUT_H_

#include "platform/assert.h"
#include "platform/globals.h"

// FrameLayout structure captures configuration specific properties of the
// frame layout used by the runtime system and compiler.
//
// Runtime system uses runtime_frame_layout defined in stack_frame.h.
// Compiler uses compiler::target::frame_layout defined in runtime_api.h

namespace Code {

// Forward declarations.
class LocalVariable;

struct FrameLayout {
  // The offset (in words) from FP to the first object.
  intptr_t first_object_from_fp;

  // The offset (in words) from FP to the last fixed object.
  intptr_t last_fixed_object_from_fp;

  // The offset (in words) from FP to the slot past the last parameter.
  intptr_t param_end_from_fp;

  // The offset (in words) from SP on entry (before frame is setup) to
  // the last parameter.
  intptr_t last_param_from_entry_sp;

  // The offset (in words) from FP to the first local.
  intptr_t first_local_from_fp;

  // The fixed size of the frame.
  intptr_t CODE_fixed_frame_size;

  // The offset (in words) from FP to the saved pool (if applicable).
  intptr_t saved_caller_pp_from_fp;

  // The offset (in words) from FP to the saved FP.
  intptr_t saved_caller_fp_from_fp;

  // The offset (in words) from FP to the saved return address.
  intptr_t saved_caller_pc_from_fp;

  // The offset (in words) from FP to the code object (if applicable).
  intptr_t code_from_fp;

  // Entry and exit frame layout.
  intptr_t exit_link_slot_from_entry_fp;

  // The number of fixed slots below the saved PC.
  intptr_t saved_below_pc() const { return -first_local_from_fp; }

  // Returns the FP-relative index where [variable] can be found (assumes
  // [variable] is not captured), in words.
  intptr_t FrameSlotForVariable(const LocalVariable* variable) const;

  // Returns the FP-relative index where [variable_index] can be found (assumes
  // [variable_index] comes from a [LocalVariable::index()], which is not
  // captured).
  intptr_t FrameSlotForVariableIndex(intptr_t index) const;

  // Returns the variable index from a FP-relative index.
  intptr_t VariableIndexForFrameSlot(intptr_t frame_slot) const {
    if (frame_slot <= first_local_from_fp) {
      return frame_slot - first_local_from_fp;
    } else {
      ASSERT(frame_slot > param_end_from_fp);
      return frame_slot - param_end_from_fp;
    }
  }

  // Called to initialize the stack frame layout during startup.
  static void Init();
};

}  // namespace dart

#endif  // RUNTIME_VM_FRAME_LAYOUT_H_
