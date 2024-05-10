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

#ifndef RUNTIME_VM_COMPILER_METHOD_RECOGNIZER_H_
#define RUNTIME_VM_COMPILER_METHOD_RECOGNIZER_H_

#include "src/allocation.h"
#include "src/compiler/recognized_methods_list.h"
#include "src/growable_array.h"
#include "src/token.h"

namespace Code {

// Forward declarations.
class Function;
class Library;
class Object;
class String;
class Zone;

// Class that recognizes the name and owner of a function and returns the
// corresponding enum. See RECOGNIZED_LIST above for list of recognizable
// functions.
class MethodRecognizer : public AllStatic {
 public:
  enum Kind {
    kUnknown,
#define DEFINE_ENUM_LIST(class_name, function_name, enum_name, fp) k##enum_name,
    RECOGNIZED_LIST(DEFINE_ENUM_LIST)
#undef DEFINE_ENUM_LIST
        kNumRecognizedMethods
  };

  static intptr_t NumArgsCheckedForStaticCall(const Function& function);

  // Try to find an annotation of the form
  //   @pragma("vm:exact-result-type", int)
  //   @pragma("vm:exact-result-type", "dart:core#_Smi")
  // and return the exact cid if found or kDynamicCid otherwise.
  //
  // See [result_type_pragma.md].
  static intptr_t ResultCidFromPragma(const Object& function_or_field);

  // Try to find an annotation of the form
  //   @pragma("vm:non-nullable-result-type")
  // and returns true iff `false` was specified in the annotation.
  //
  // See [pragmas.md].
  static bool HasNonNullableResultTypeFromPragma(
      const Object& function_or_field);

  static intptr_t MethodKindToReceiverCid(Kind kind);
  static const char* KindToCString(Kind kind);
  static const char* KindToFunctionNameCString(Kind kind);

  static bool IsMarkedAsRecognized(const Function& function,
                                   const char* kind = nullptr);
  static void InitializeState();

 private:
  static void Libraries(GrowableArray<Library*>* libs);
};

// Recognizes token corresponding to a method name.
class MethodTokenRecognizer : public AllStatic {
 public:
  static Token::Kind RecognizeTokenKind(const String& name);
};

// Class that recognizes factories and returns corresponding result cid.
class FactoryRecognizer : public AllStatic {
 public:
  // Return result cid of 'factory' if it is recognized.
  // Return kDynamicCid if factory is not recognized.
  static intptr_t ResultCid(const Function& factory);

  // Return result cid of 'function' called with 'argument_count' arguments,
  // if function is a recognized list factory constructor.
  // Return kDynamicCid if function is not recognized.
  static intptr_t GetResultCidOfListFactory(Zone* zone,
                                            const Function& function,
                                            intptr_t argument_count);
};

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_METHOD_RECOGNIZER_H_
