// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "android/base_jni_registrar.h"

#include "basictypes.h"
#include "message_pump_android.h"
#include "android/build_info.h"
#include "android/jni_android.h"
#include "android/jni_registrar.h"
#include "android/locale_utils.h"
#include "android/path_service_android.h"
#include "android/path_utils.h"

namespace base {
namespace android {

static RegistrationMethod kBaseRegisteredMethods[] = {
  { "BuildInfo", base::android::BuildInfo::RegisterBindings },
  { "LocaleUtils", base::android::RegisterLocaleUtils },
  { "PathService", base::android::RegisterPathService },
  { "PathUtils", base::android::RegisterPathUtils },
  { "SystemMessageHandler", base::MessagePumpForUI::RegisterBindings },
};

bool RegisterJni(JNIEnv* env) {
  return RegisterNativeMethods(env, kBaseRegisteredMethods,
                               arraysize(kBaseRegisteredMethods));
}

}  // namespace android
}  // namespace base
