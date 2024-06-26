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
 * Contact with ITGSS, 640 N McCarvy Blvd. , in the
 * city of Milpitas, zip Code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Sunday, May 24, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 


// ios_base basic members

#include <xiosbase>
_STD_BEGIN

constexpr int _Nstdstr = 8; // cin, wcin, cout, wcout, cerr, wcerr, clog, wclog

// TRANSITION, ABI: _BADOFF is preserved for binary compatibility
#if defined(_M_CEE_PURE)
extern const streamoff _BADOFF;
const streamoff _BADOFF = -1;
#else
extern _CRTDATA2_IMPORT _PGLOBAL const streamoff _BADOFF;
_PGLOBAL _CRTDATA2_IMPORT const streamoff _BADOFF = -1; // initialize constant for bad file offset
#endif

__PURE_APPDOMAIN_GLOBAL int ios_base::_Index = 0; // initialize source of unique indexes
__PURE_APPDOMAIN_GLOBAL bool ios_base::_Sync = true; // initialize synchronization flag

__PURE_APPDOMAIN_GLOBAL static ios_base* stdstr[_Nstdstr + 2] = {
    nullptr}; // [1, _Nstdstr] hold pointers to standard streams
__PURE_APPDOMAIN_GLOBAL static char stdopens[_Nstdstr + 2] = {0}; // [1, _Nstdstr] hold open counts for standard streams

void __CLRCALL_PURE_OR_CDECL ios_base::_Ios_base_dtor(ios_base* _This) { // destroy the object
    if (0 < _This->_Stdstr && 0 < --stdopens[_This->_Stdstr]) {
        return;
    }

    _This->_Tidy();

    delete _This->_Ploc;
}

void __CLRCALL_PURE_OR_CDECL ios_base::_Addstd(ios_base* _This) { // add standard stream to destructor list
    _BEGIN_LOCK(_LOCK_STREAM)
    for (_This->_Stdstr = 1; _This->_Stdstr < _Nstdstr; ++_This->_Stdstr) {
        if (stdstr[_This->_Stdstr] == nullptr || stdstr[_This->_Stdstr] == _This) {
            break; // found a candidate
        }
    }

    stdstr[_This->_Stdstr] = _This;
    ++stdopens[_This->_Stdstr];
    _END_LOCK()
}

_STD_END
