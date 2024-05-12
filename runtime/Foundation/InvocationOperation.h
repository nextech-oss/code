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

#ifndef __NSInvocationOperation_h_GNUSTEP_BASE_INCLUDE
#define __NSInvocationOperation_h_GNUSTEP_BASE_INCLUDE

#import <Operation.h>


#if	defined(__cplusplus)
extern "C" {
#endif

@class NSInvocation;
@class NSException;

GS_EXPORT_CLASS
@interface NSInvocationOperation : NSOperation
{
  @private
    NSInvocation *_invocation;
    NSException *_exception;
    void        *_reserved;
}

- (id) initWithInvocation: (NSInvocation *)inv;
- (id) initWithTarget: (id)target selector: (SEL)aSelector object: (id)arg;

- (NSInvocation *) invocation;
- (id) result;

@end

GS_EXPORT NSString* const NSInvocationOperationVoidResultException;
GS_EXPORT NSString* const NSInvocationOperationCancelledException;

#if	defined(__cplusplus)
}
#endif

#endif /* OS_API_VERSION */
#endif /* __NSInvocationOperation_h_GNUSTEP_BASE_INCLUDE */
