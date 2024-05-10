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

#include "src/CODE_api_impl.h"
#include "src/CODE_api_state.h"
#include "src/object.h"
#include "src/symbols.h"
#include "src/unit_test.h"

namespace Code {

FieldPtr LookupField(CODE_Handle library,
                     const char* class_name,
                     const char* field_name) {
  LibraryPtr raw_library = Library::RawCast(Api::UnwrapHandle(library));
  Library& lib = Library::ZoneHandle(raw_library);
  const String& classname =
      String::Handle(Symbols::New(Thread::Current(), class_name));
  Class& cls = Class::Handle(lib.LookupClass(classname));
  EXPECT(!cls.IsNull());  // No ambiguity error expected.

  String& fieldname = String::Handle(String::New(field_name));
  Field& field =
      Field::ZoneHandle(cls.LookupInstanceFieldAllowPrivate(fieldname));
  EXPECT(!field.IsNull());
  return field.ptr();
}

TEST_CASE(GuardFieldSimpleTest) {
  const char* script_chars =
      "class A {\n"
      "  var f1 = 3.0;\n"
      "  dynamic f2 = 3;\n"
      "  var f3 = List<dynamic>.filled(4, null);\n"
      "  foo() {\n"
      "    f1 = f1 + f1;\n"
      "  }\n"
      "  bar() {\n"
      "    f2 = null;\n"
      "    f2 = 3.0;\n"
      "  }\n"
      "}\n"
      "\n"
      "runFoo() {\n"
      "  var a = A();\n"
      "  for (int i = 0; i < 2000; i++) {\n"
      "    a.foo();\n"
      "  }\n"
      "}\n"
      "\n"
      "runBar() {\n"
      "  var a = A();\n"
      "  for (int i = 0; i < 2000; i++) {\n"
      "    a.bar();\n"
      "  }\n"
      "}\n"
      "main() {\n"
      "  for (int i = 0; i < 100; i++) {\n"
      "    runFoo();\n"
      "    runBar();\n"
      "  }\n"
      "}\n";
  CODE_Handle lib = TestCase::LoadTestScript(script_chars, nullptr);
  CODE_Handle result = CODE_Invoke(lib, NewString("main"), 0, nullptr);
  EXPECT_VALID(result);
  TransitionNativeToVM transition(thread);
  Field& f1 = Field::ZoneHandle(LookupField(lib, "A", "f1"));
  Field& f2 = Field::ZoneHandle(LookupField(lib, "A", "f2"));
  Field& f3 = Field::ZoneHandle(LookupField(lib, "A", "f3"));
  const intptr_t no_length = Field::kNoFixedLength;
  EXPECT_EQ(no_length, f1.guarded_list_length());
  EXPECT_EQ(kDoubleCid, f1.guarded_cid());
  EXPECT_EQ(false, f1.is_nullable());
  EXPECT_EQ(no_length, f2.guarded_list_length());
  EXPECT_EQ(kDynamicCid, f2.guarded_cid());
  EXPECT_EQ(true, f2.is_nullable());
  EXPECT_EQ(no_length, f3.guarded_list_length());
}

TEST_CASE(GuardFieldFinalListTest) {
  const char* script_chars =
      "class A {\n"
      "  var f1 = 3.0;\n"
      "  dynamic f2 = 3;\n"
      "  final f3 = List<dynamic>.filled(4, null);\n"
      "  foo() {\n"
      "    f1 = f1 + f1;\n"
      "  }\n"
      "  bar() {\n"
      "    f2 = null;\n"
      "    f2 = 3.0;\n"
      "  }\n"
      "}\n"
      "\n"
      "runFoo() {\n"
      "  var a = A();\n"
      "  for (int i = 0; i < 2000; i++) {\n"
      "    a.foo();\n"
      "  }\n"
      "}\n"
      "\n"
      "runBar() {\n"
      "  var a = A();\n"
      "  for (int i = 0; i < 2000; i++) {\n"
      "    a.bar();\n"
      "  }\n"
      "}\n"
      "main() {\n"
      "  for (int i = 0; i < 100; i++) {\n"
      "    runFoo();\n"
      "    runBar();\n"
      "  }\n"
      "}\n";
  CODE_Handle lib = TestCase::LoadTestScript(script_chars, nullptr);
  CODE_Handle result = CODE_Invoke(lib, NewString("main"), 0, nullptr);
  EXPECT_VALID(result);
  TransitionNativeToVM transition(thread);
  Field& f1 = Field::ZoneHandle(LookupField(lib, "A", "f1"));
  Field& f2 = Field::ZoneHandle(LookupField(lib, "A", "f2"));
  Field& f3 = Field::ZoneHandle(LookupField(lib, "A", "f3"));
  const intptr_t no_length = Field::kNoFixedLength;
  EXPECT_EQ(no_length, f1.guarded_list_length());
  EXPECT_EQ(kDoubleCid, f1.guarded_cid());
  EXPECT_EQ(false, f1.is_nullable());
  EXPECT_EQ(no_length, f2.guarded_list_length());
  EXPECT_EQ(kDynamicCid, f2.guarded_cid());
  EXPECT_EQ(true, f2.is_nullable());
  EXPECT_EQ(4, f3.guarded_list_length());
  EXPECT_EQ(kArrayCid, f3.guarded_cid());
  EXPECT_EQ(false, f3.is_nullable());
}

TEST_CASE(GuardFieldFinalVariableLengthListTest) {
  const char* script_chars =
      "class A {\n"
      "  var f1 = 3.0;\n"
      "  dynamic f2 = 3;\n"
      "  final f3 = List.empty(growable: true);\n"
      "  foo() {\n"
      "    f1 = f1 + f1;\n"
      "  }\n"
      "  bar() {\n"
      "    f2 = null;\n"
      "    f2 = 3.0;\n"
      "  }\n"
      "}\n"
      "\n"
      "runFoo() {\n"
      "  var a = A();\n"
      "  for (int i = 0; i < 2000; i++) {\n"
      "    a.foo();\n"
      "  }\n"
      "}\n"
      "\n"
      "runBar() {\n"
      "  var a = A();\n"
      "  for (int i = 0; i < 2000; i++) {\n"
      "    a.bar();\n"
      "  }\n"
      "}\n"
      "main() {\n"
      "  for (int i = 0; i < 100; i++) {\n"
      "    runFoo();\n"
      "    runBar();\n"
      "  }\n"
      "}\n";
  CODE_Handle lib = TestCase::LoadTestScript(script_chars, nullptr);
  CODE_Handle result = CODE_Invoke(lib, NewString("main"), 0, nullptr);
  EXPECT_VALID(result);
  TransitionNativeToVM transition(thread);
  Field& f1 = Field::ZoneHandle(LookupField(lib, "A", "f1"));
  Field& f2 = Field::ZoneHandle(LookupField(lib, "A", "f2"));
  Field& f3 = Field::ZoneHandle(LookupField(lib, "A", "f3"));
  const intptr_t no_length = Field::kNoFixedLength;
  EXPECT_EQ(no_length, f1.guarded_list_length());
  EXPECT_EQ(kDoubleCid, f1.guarded_cid());
  EXPECT_EQ(false, f1.is_nullable());
  EXPECT_EQ(no_length, f2.guarded_list_length());
  EXPECT_EQ(kDynamicCid, f2.guarded_cid());
  EXPECT_EQ(true, f2.is_nullable());
  EXPECT_EQ(no_length, f3.guarded_list_length());
  EXPECT_EQ(kGrowableObjectArrayCid, f3.guarded_cid());
  EXPECT_EQ(false, f3.is_nullable());
}

TEST_CASE(GuardFieldConstructorTest) {
  const char* script_chars =
      "import 'dart:typed_data';\n"
      "class A {\n"
      "  var f1 = 3.0;\n"
      "  dynamic f2 = 3;\n"
      "  final f3;\n"
      "  A(x) : f3 = x;\n"
      "  foo() {\n"
      "    f1 = f1 + f1;\n"
      "  }\n"
      "  bar() {\n"
      "    f2 = null;\n"
      "    f2 = 3.0;\n"
      "  }\n"
      "}\n"
      "\n"
      "runFoo() {\n"
      "  var l = new Float32List(5);\n"
      "  for (int i = 0; i < 2000; i++) {\n"
      "    var a = new A(l);\n"
      "    a.foo();\n"
      "  }\n"
      "}\n"
      "\n"
      "runBar() {\n"
      "  var l = new Float32List(5);\n"
      "  var a = new A(l);\n"
      "  for (int i = 0; i < 2000; i++) {\n"
      "    a.bar();\n"
      "  }\n"
      "}\n"
      "main() {\n"
      "  for (int i = 0; i < 100; i++) {\n"
      "    runFoo();\n"
      "    runBar();\n"
      "  }\n"
      "}\n";
  CODE_Handle lib = TestCase::LoadTestScript(script_chars, nullptr);
  CODE_Handle result = CODE_Invoke(lib, NewString("main"), 0, nullptr);
  EXPECT_VALID(result);
  TransitionNativeToVM transition(thread);
  Field& f1 = Field::ZoneHandle(LookupField(lib, "A", "f1"));
  Field& f2 = Field::ZoneHandle(LookupField(lib, "A", "f2"));
  Field& f3 = Field::ZoneHandle(LookupField(lib, "A", "f3"));
  const intptr_t no_length = Field::kNoFixedLength;
  EXPECT_EQ(no_length, f1.guarded_list_length());
  EXPECT_EQ(kDoubleCid, f1.guarded_cid());
  EXPECT_EQ(false, f1.is_nullable());
  EXPECT_EQ(no_length, f2.guarded_list_length());
  EXPECT_EQ(kDynamicCid, f2.guarded_cid());
  EXPECT_EQ(true, f2.is_nullable());
  const intptr_t length = 5;
  EXPECT_EQ(length, f3.guarded_list_length());
  EXPECT_EQ(kTypedDataFloat32ArrayCid, f3.guarded_cid());
  EXPECT_EQ(false, f3.is_nullable());
}

TEST_CASE(GuardFieldConstructor2Test) {
  const char* script_chars =
      "import 'dart:typed_data';\n"
      "class A {\n"
      "  final f3;\n"
      "  A(x) : f3 = x;\n"
      "  foo() {\n"
      "  }\n"
      "  bar() {\n"
      "  }\n"
      "}\n"
      "\n"
      "runFoo() {\n"
      "  var l = new Float32List(5);\n"
      "  for (int i = 0; i < 2000; i++) {\n"
      "    var a = new A(l);\n"
      "  }\n"
      "}\n"
      "\n"
      "runBar() {\n"
      "  var l = new Float32List(99);\n"
      "  var a = new A(l);\n"
      "}\n"
      "main() {\n"
      "  for (int i = 0; i < 100; i++) {\n"
      "    runFoo();\n"
      "    runBar();\n"
      "  }\n"
      "}\n";
  CODE_Handle lib = TestCase::LoadTestScript(script_chars, nullptr);
  CODE_Handle result = CODE_Invoke(lib, NewString("main"), 0, nullptr);
  EXPECT_VALID(result);
  TransitionNativeToVM transition(thread);
  Field& f3 = Field::ZoneHandle(LookupField(lib, "A", "f3"));
  const intptr_t no_length = Field::kNoFixedLength;
  EXPECT_EQ(no_length, f3.guarded_list_length());
  EXPECT_EQ(kTypedDataFloat32ArrayCid, f3.guarded_cid());
  EXPECT_EQ(false, f3.is_nullable());
}

}  // namespace dart
