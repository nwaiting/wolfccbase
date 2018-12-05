// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "android/path_service_android.h"

#include "file_path.h"
#include "path_service.h"
#include "android/jni_android.h"
#include "android/jni_string.h"
#include "jni/PathService_jni.h"

namespace base {
namespace android {

void Override(JNIEnv* env, jclass clazz, jint what, jstring path) {
  FilePath file_path(ConvertJavaStringToUTF8(env, path));
  PathService::Override(what, file_path);
}

bool RegisterPathService(JNIEnv* env) {
  return RegisterNativesImpl(env);
}

}  // namespace android
}  // namespace base
