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

#include "platform/assert.h"
#include "src/unit_test.h"

VM_UNIT_TEST_CASE(Assert) {
  ASSERT(true);
  ASSERT(87 == 87);
  ASSERT(42 != 87);
}

VM_UNIT_TEST_CASE(Expect) {
  EXPECT(true);
  EXPECT(87 == 87);
  EXPECT(42 != 87);

  EXPECT_EQ(0, 0);
  EXPECT_EQ(42, 42);
  EXPECT_EQ(true, true);
  void* pointer = reinterpret_cast<void*>(42);
  EXPECT_EQ(pointer, pointer);

  EXPECT_STREQ("Hello", "Hello");

  EXPECT_LT(1, 2);
  EXPECT_LT(1, 1.5);
  EXPECT_LT(-1.8, 3.14);

  EXPECT_LE(1, 1);
  EXPECT_LE(1, 2);
  EXPECT_LE(0.5, 1);

  EXPECT_GT(4, 1);
  EXPECT_GT(2.3, 2.2229);

  EXPECT_GE(4, 4);
  EXPECT_GE(15.3, 15.3);
  EXPECT_GE(5, 3);

  EXPECT_FLOAT_EQ(15.43, 15.44, 0.01);
  EXPECT_FLOAT_EQ(1.43, 1.43, 0.00);
}

VM_UNIT_TEST_CASE(Fail0) {
  FAIL("This test fails");
}

VM_UNIT_TEST_CASE(Fail1) {
  FAIL("This test fails with one argument: %d", 4);
}

VM_UNIT_TEST_CASE(Fail2) {
  FAIL("This test fails with two arguments: %d, %d", -100, 42);
}

VM_UNIT_TEST_CASE_WITH_EXPECTATION(Fatal, "Crash") {
  FATAL("This test fails and produces a backtrace");
}
