// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ios/scoped_critical_action.h"

#import <UIKit/UIKit.h>

#include "logging.h"
#include "synchronization/lock.h"

namespace base {
namespace ios {

// This implementation calls |beginBackgroundTaskWithExpirationHandler:| when
// instantiated and |endBackgroundTask:| when destroyed, creating a scope whose
// execution will continue (temporarily) even after the app is backgrounded.
ScopedCriticalAction::ScopedCriticalAction() {
  background_task_id_ = [[UIApplication sharedApplication]
      beginBackgroundTaskWithExpirationHandler:^{
        DLOG(WARNING) << "Background task with id " << background_task_id_
                      << " expired.";
        // Note if |endBackgroundTask:| is not called for each task before time
        // expires, the system kills the application.
        EndBackgroundTask();
      }];
  if (background_task_id_ == UIBackgroundTaskInvalid) {
    DLOG(WARNING) <<
        "beginBackgroundTaskWithExpirationHandler: returned an invalid ID";
  } else {
    VLOG(3) << "Beginning background task with id " << background_task_id_;
  }
}

ScopedCriticalAction::~ScopedCriticalAction() {
  EndBackgroundTask();
}

void ScopedCriticalAction::EndBackgroundTask() {
  UIBackgroundTaskIdentifier task_id;
  {
    AutoLock lock_scope(background_task_id_lock_);
    if (background_task_id_ == UIBackgroundTaskInvalid)
      return;
    task_id = background_task_id_;
    background_task_id_ = UIBackgroundTaskInvalid;
  }

  VLOG(3) << "Ending background task with id " << task_id;
  [[UIApplication sharedApplication] endBackgroundTask:task_id];
}

}  // namespace ios
}  // namespace base
