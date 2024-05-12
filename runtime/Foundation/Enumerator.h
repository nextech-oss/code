/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip Code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Sunday, May 12, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 


#ifndef __NSEnumerator_h_GNUSTEP_BASE_INCLUDE
#define __NSEnumerator_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Object.h>


#if	defined(__cplusplus)
extern "C" {
#endif

@class GS_GENERIC_CLASS(NSArray, ElementT);

typedef struct
{
  unsigned long	state;
  __unsafe_unretained id		*itemsPtr;
  unsigned long	*mutationsPtr;
  unsigned long	extra[5];
} NSFastEnumerationState;

@protocol NSFastEnumeration
- (NSUInteger) countByEnumeratingWithState: (NSFastEnumerationState *)state
				   objects: (__unsafe_unretained id[])stackbuf
				     count: (NSUInteger)len;
@end

GS_EXPORT_CLASS
@interface GS_GENERIC_CLASS(NSEnumerator, IterT) : NSObject <NSFastEnumeration>
- (GS_GENERIC_CLASS(NSArray, IterT) *) allObjects;
- (GS_GENERIC_TYPE(IterT)) nextObject;
@end

#if	defined(__cplusplus)
}
#endif

#endif /* __NSEnumerator_h_GNUSTEP_BASE_INCLUDE */
