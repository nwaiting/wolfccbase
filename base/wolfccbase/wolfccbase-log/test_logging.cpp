#include <iostream>
#include <stdint.h>
#include "logging.h"


int main()
{
    LOG(INFO) << "this is a test";
    int32_t num_cookies = 100;
    LOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";

    std::cin.get();
    return 0;
}
