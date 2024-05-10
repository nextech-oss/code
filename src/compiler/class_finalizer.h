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

#ifndef RUNTIME_VM_CLASS_FINALIZER_H_
#define RUNTIME_VM_CLASS_FINALIZER_H_

#include <memory>

#include "src/allocation.h"
#include "src/growable_array.h"
#include "src/object.h"

namespace Code {

// Traverses all pending, unfinalized classes, validates and marks them as
// finalized.
class ClassFinalizer : public AllStatic {
 public:
  // Modes for finalization. The ordering is relevant.
  enum FinalizationKind {
    kFinalize,     // Finalize type and type arguments.
    kCanonicalize  // Finalize and canonicalize.
  };

  // Finalize given type.
  static AbstractTypePtr FinalizeType(
      const AbstractType& type,
      FinalizationKind finalization = kCanonicalize);

  // Return false if we still have classes pending to be finalized.
  static bool AllClassesFinalized();

#if !defined(CODE_PRECOMPILED_RUNTIME)
  // Useful for sorting classes to make dispatch faster.
  static void SortClasses();
  static void RemapClassIds(intptr_t* old_to_new_cid);
  static void RehashTypes();
  static void ClearAllCode(bool including_nonchanging_cids = false);
#endif  // !defined(CODE_PRECOMPILED_RUNTIME)

  // Return whether processing pending classes (ObjectStore::pending_classes_)
  // failed. The function returns true if the processing was successful.
  // If processing fails, an error message is set in the sticky error field
  // in the object store.
  static bool ProcessPendingClasses();

  // Finalize the types appearing in the declaration of class 'cls', i.e. its
  // type parameters and their upper bounds, its super type and interfaces.
  // Note that the fields and functions have not been parsed yet (unless cls
  // is an anonymous top level class).
  static void FinalizeTypesInClass(const Class& cls);

#if !defined(CODE_PRECOMPILED_RUNTIME)
  // Register class in the lists of direct subclasses and direct implementors.
  static void RegisterClassInHierarchy(Zone* zone, const Class& cls);

  // Mark [cls], its superclass and superinterfaces as can_be_future().
  static void MarkClassCanBeFuture(Zone* zone, const Class& cls);
#endif  // !defined(CODE_PRECOMPILED_RUNTIME)

  // Ensures members of the class are loaded, class layout is finalized and size
  // registered in class table.
  static void FinalizeClass(const Class& cls);

#if !defined(CODE_PRECOMPILED_RUNTIME)
  // Makes class instantiatable and usable by generated code.
  static ErrorPtr AllocateFinalizeClass(const Class& cls);

  // Completes loading of the class, this populates the function
  // and fields of the class.
  //
  // Returns Error::null() if there is no loading error.
  static ErrorPtr LoadClassMembers(const Class& cls);

  // Verify that the classes have been properly prefinalized. This is
  // needed during bootstrapping where the classes have been preloaded.
  static void VerifyBootstrapClasses();
#endif  // !defined(CODE_PRECOMPILED_RUNTIME)

 private:
  // Finalize given type argument vector.
  static TypeArgumentsPtr FinalizeTypeArguments(
      Zone* zone,
      const TypeArguments& type_args,
      FinalizationKind finalization = kCanonicalize);

  static void FinalizeTypeParameters(Zone* zone,
                                     const TypeParameters& type_params,
                                     FinalizationKind finalization);

#if !defined(CODE_PRECOMPILED_RUNTIME)
  static void FinalizeMemberTypes(const Class& cls);
  static void PrintClassInformation(const Class& cls);
#endif  // !defined(CODE_PRECOMPILED_RUNTIME)

  static void ReportError(const Error& error);
  static void ReportError(const char* format, ...) PRINTF_ATTRIBUTE(1, 2);

#if !defined(CODE_PRECOMPILED_RUNTIME)
  // Verify implicit offsets recorded in the VM for direct access to fields of
  // Dart instances (e.g: _TypedListView, _ByteDataView).
  static void VerifyImplicitFieldOffsets();
#endif  // !defined(CODE_PRECOMPILED_RUNTIME)
};

}  // namespace dart

#endif  // RUNTIME_VM_CLASS_FINALIZER_H_
