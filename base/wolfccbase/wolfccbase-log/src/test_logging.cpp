#include <iostream>
#include <stdint.h>
#include "base/logging.h"


int main()
{
    logging::InitLogging(NULL, logging::LoggingDestination(), logging::LogLockingState(), logging::OldFileDeletionState(), logging::DcheckState());
    logging::SetMinLogLevel(logging::LOG_INFO);

    LOG(INFO) << "this is a test";
    int32_t num_cookies = 100;
    LOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";

    std::cin.get();
    return 0;
}
