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
#ifdef __i386__

#include <mach/vm_param.h>
	
.text
    .private_extern __a1a2_tramphead
    .private_extern __a1a2_firsttramp
    .private_extern __a1a2_nexttramp
    .private_extern __a1a2_trampend

.align PAGE_SHIFT
__a1a2_tramphead:
    popl %eax
    andl $0xFFFFFFF8, %eax
    subl $ PAGE_SIZE, %eax
    movl 4(%esp), %ecx // self -> ecx
    movl %ecx, 8(%esp) // ecx -> _cmd
    movl (%eax), %ecx // blockPtr -> ecx
    movl %ecx, 4(%esp) // ecx -> self
    jmp  *12(%ecx) // tail to block->invoke

.macro TrampolineEntry
    call __a1a2_tramphead
    nop
    nop
    nop
.endmacro

.align 5
__a1a2_firsttramp:
    TrampolineEntry
__a1a2_nexttramp: // used to calculate size of each trampoline
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry

__a1a2_trampend:

#endif
