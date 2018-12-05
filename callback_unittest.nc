// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "callback.h"

namespace base {

class Parent {
};

class Child : Parent {
};

#if defined(NCTEST_EQUALS_REQUIRES_SAMETYPE)  // [r"no matching function for call to 'base::Callback<void\(\)>::Equals\(base::Callback<int\(\)>&\)'"]

// Attempting to call comparison function on two callbacks of different type.
//
// This should be a compile time failure because each callback type should be
// considered distinct.
void WontCompile() {
  Closure c1;
  Callback<int(void)> c2;
  c1.Equals(c2);
}

#elif defined(NCTEST_CONSTRUCTION_FROM_SUBTYPE)  // [r"conversion from 'base::Callback<base::Parent\(\)>' to non-scalar type 'base::Callback<base::Child\(\)>'"]

// Construction of Callback<A> from Callback<B> if A is supertype of B.
//
// While this is technically safe, most people aren't used to it when coding
// C++ so if this is happening, it is almost certainly an error.
void WontCompile() {
  Callback<Parent(void)> cb_a;
  Callback<Child(void)> cb_b = cb_a;
}

#elif defined(NCTEST_ASSIGNMENT_FROM_SUBTYPE)  // [r"no match for 'operator=' in 'cb_a = cb_b'"]

// Assignment of Callback<A> from Callback<B> if A is supertype of B.
// See explanation for NCTEST_CONSTRUCTION_FROM_SUBTYPE
void WontCompile() {
  Callback<Parent(void)> cb_a;
  Callback<Child(void)> cb_b;
  cb_a = cb_b;
}

#endif

}  // namespace base