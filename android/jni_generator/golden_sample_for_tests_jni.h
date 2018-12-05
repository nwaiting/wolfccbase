// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator_tests.py
// For
//     org/chromium/example/jni_generator/SampleForTests

#ifndef org_chromium_example_jni_generator_SampleForTests_JNI
#define org_chromium_example_jni_generator_SampleForTests_JNI

#include <jni.h>

#include "base/android/jni_android.h"
#include "base/android/scoped_java_ref.h"
#include "base/basictypes.h"
#include "base/logging.h"

using base::android::ScopedJavaLocalRef;

// Step 1: forward declarations.
namespace {
const char kInnerClassClassPath[] =
    "org/chromium/example/jni_generator/SampleForTests$InnerClass";
const char kSampleForTestsClassPath[] =
    "org/chromium/example/jni_generator/SampleForTests";
// Leaking this jclass as we cannot use LazyInstance from some threads.
jclass g_InnerClass_clazz = NULL;
// Leaking this jclass as we cannot use LazyInstance from some threads.
jclass g_SampleForTests_clazz = NULL;
}  // namespace

namespace base {
namespace android {

static jint Init(JNIEnv* env, jobject obj);

static jdouble GetDoubleFunction(JNIEnv* env, jobject obj);

static jfloat GetFloatFunction(JNIEnv* env, jclass clazz);

static void SetNonPODDatatype(JNIEnv* env, jobject obj,
    jobject rect);

static jobject GetNonPODDatatype(JNIEnv* env, jobject obj);

static jint InnerFunction(JNIEnv* env, jclass clazz);

// Step 2: method stubs.
static void Destroy(JNIEnv* env, jobject obj,
    jint nativeCPPClass) {
  DCHECK(nativeCPPClass) << "Destroy";
  CPPClass* native = reinterpret_cast<CPPClass*>(nativeCPPClass);
  return native->Destroy(env, obj);
}

static jint Method(JNIEnv* env, jobject obj,
    jint nativeCPPClass) {
  DCHECK(nativeCPPClass) << "Method";
  CPPClass* native = reinterpret_cast<CPPClass*>(nativeCPPClass);
  return native->Method(env, obj);
}

static jdouble MethodOtherP0(JNIEnv* env, jobject obj,
    jint nativePtr) {
  DCHECK(nativePtr) << "MethodOtherP0";
  CPPClass::InnerClass* native =
        reinterpret_cast<CPPClass::InnerClass*>(nativePtr);
  return native->MethodOtherP0(env, obj);
}

static jstring InnerMethod(JNIEnv* env, jobject obj,
    jint nativeCPPClass) {
  DCHECK(nativeCPPClass) << "InnerMethod";
  CPPClass* native = reinterpret_cast<CPPClass*>(nativeCPPClass);
  return native->InnerMethod(env, obj).Release();
}

static jmethodID g_SampleForTests_javaMethod = 0;
static jint Java_SampleForTests_javaMethod(JNIEnv* env, jobject obj, jint foo,
    jint bar) {
  /* Must call RegisterNativesImpl()  */
  DCHECK(g_SampleForTests_clazz);
  DCHECK(g_SampleForTests_javaMethod);
  jint ret =
    env->CallIntMethod(obj,
      g_SampleForTests_javaMethod, foo, bar);
  base::android::CheckException(env);
  return ret;
}

static jmethodID g_SampleForTests_staticJavaMethod = 0;
static jboolean Java_SampleForTests_staticJavaMethod(JNIEnv* env) {
  /* Must call RegisterNativesImpl()  */
  DCHECK(g_SampleForTests_clazz);
  DCHECK(g_SampleForTests_staticJavaMethod);
  jboolean ret =
    env->CallStaticBooleanMethod(g_SampleForTests_clazz,
      g_SampleForTests_staticJavaMethod);
  base::android::CheckException(env);
  return ret;
}

static jmethodID g_SampleForTests_packagePrivateJavaMethod = 0;
static void Java_SampleForTests_packagePrivateJavaMethod(JNIEnv* env, jobject
    obj) {
  /* Must call RegisterNativesImpl()  */
  DCHECK(g_SampleForTests_clazz);
  DCHECK(g_SampleForTests_packagePrivateJavaMethod);

  env->CallVoidMethod(obj,
      g_SampleForTests_packagePrivateJavaMethod);
  base::android::CheckException(env);

}

static jmethodID g_SampleForTests_methodThatThrowsException = 0;
static void Java_SampleForTests_methodThatThrowsException(JNIEnv* env, jobject
    obj) {
  /* Must call RegisterNativesImpl()  */
  DCHECK(g_SampleForTests_clazz);
  DCHECK(g_SampleForTests_methodThatThrowsException);

  env->CallVoidMethod(obj,
      g_SampleForTests_methodThatThrowsException);

}

static jmethodID g_InnerClass_JavaInnerMethod = 0;
static jfloat Java_InnerClass_JavaInnerMethod(JNIEnv* env, jobject obj) {
  /* Must call RegisterNativesImpl()  */
  DCHECK(g_InnerClass_clazz);
  DCHECK(g_InnerClass_JavaInnerMethod);
  jfloat ret =
    env->CallFloatMethod(obj,
      g_InnerClass_JavaInnerMethod);
  base::android::CheckException(env);
  return ret;
}

static jmethodID g_InnerClass_javaInnerFunction = 0;
static void Java_InnerClass_javaInnerFunction(JNIEnv* env) {
  /* Must call RegisterNativesImpl()  */
  DCHECK(g_InnerClass_clazz);
  DCHECK(g_InnerClass_javaInnerFunction);

  env->CallStaticVoidMethod(g_InnerClass_clazz,
      g_InnerClass_javaInnerFunction);
  base::android::CheckException(env);

}

// Step 3: GetMethodIDs and RegisterNatives.
static void GetMethodIDsImpl(JNIEnv* env) {
  g_InnerClass_clazz = reinterpret_cast<jclass>(env->NewGlobalRef(
      base::android::GetUnscopedClass(env, kInnerClassClassPath)));
  g_SampleForTests_clazz = reinterpret_cast<jclass>(env->NewGlobalRef(
      base::android::GetUnscopedClass(env, kSampleForTestsClassPath)));
  g_SampleForTests_javaMethod =
      base::android::GetMethodID(
          env, g_SampleForTests_clazz,
          "javaMethod",

"("
"I"
"I"
")"
"I");

  g_SampleForTests_staticJavaMethod =
      base::android::GetStaticMethodID(
          env, g_SampleForTests_clazz,
          "staticJavaMethod",

"("
")"
"Z");

  g_SampleForTests_packagePrivateJavaMethod =
      base::android::GetMethodID(
          env, g_SampleForTests_clazz,
          "packagePrivateJavaMethod",

"("
")"
"V");

  g_SampleForTests_methodThatThrowsException =
      base::android::GetMethodID(
          env, g_SampleForTests_clazz,
          "methodThatThrowsException",

"("
")"
"V");

  g_InnerClass_JavaInnerMethod =
      base::android::GetMethodID(
          env, g_InnerClass_clazz,
          "JavaInnerMethod",

"("
")"
"F");

  g_InnerClass_javaInnerFunction =
      base::android::GetStaticMethodID(
          env, g_InnerClass_clazz,
          "javaInnerFunction",

"("
")"
"V");

}

static bool RegisterNativesImpl(JNIEnv* env) {
  GetMethodIDsImpl(env);

  static const JNINativeMethod kMethodsInnerClass[] = {
    { "nativeInnerFunction",
"("
")"
"I", reinterpret_cast<void*>(InnerFunction) },
    { "nativeInnerMethod",
"("
"I"
")"
"Ljava/lang/String;", reinterpret_cast<void*>(InnerMethod) },
  };
  const int kMethodsInnerClassSize = arraysize(kMethodsInnerClass);

  if (env->RegisterNatives(g_InnerClass_clazz,
                           kMethodsInnerClass,
                           kMethodsInnerClassSize) < 0) {
    LOG(ERROR) << "RegisterNatives failed in " << __FILE__;
    return false;
  }

  static const JNINativeMethod kMethodsSampleForTests[] = {
    { "nativeInit",
"("
")"
"I", reinterpret_cast<void*>(Init) },
    { "nativeDestroy",
"("
"I"
")"
"V", reinterpret_cast<void*>(Destroy) },
    { "nativeGetDoubleFunction",
"("
")"
"D", reinterpret_cast<void*>(GetDoubleFunction) },
    { "nativeGetFloatFunction",
"("
")"
"F", reinterpret_cast<void*>(GetFloatFunction) },
    { "nativeSetNonPODDatatype",
"("
"Landroid/graphics/Rect;"
")"
"V", reinterpret_cast<void*>(SetNonPODDatatype) },
    { "nativeGetNonPODDatatype",
"("
")"
"Ljava/lang/Object;", reinterpret_cast<void*>(GetNonPODDatatype) },
    { "nativeMethod",
"("
"I"
")"
"I", reinterpret_cast<void*>(Method) },
    { "nativeMethodOtherP0",
"("
"I"
")"
"D", reinterpret_cast<void*>(MethodOtherP0) },
  };
  const int kMethodsSampleForTestsSize = arraysize(kMethodsSampleForTests);

  if (env->RegisterNatives(g_SampleForTests_clazz,
                           kMethodsSampleForTests,
                           kMethodsSampleForTestsSize) < 0) {
    LOG(ERROR) << "RegisterNatives failed in " << __FILE__;
    return false;
  }

  return true;
}
}  // namespace android
}  // namespace base

#endif  // org_chromium_example_jni_generator_SampleForTests_JNI
