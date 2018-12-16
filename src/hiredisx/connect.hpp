#include <hiredis.h>
#include <string>

#ifndef _HIREDISX_CONNECT_H
#define _HIREDISX_CONNECT_H 1

namespace hiredisx {

    std::atomic<redisContext> context;

    void connect(std::string host = "localhost", int port = 6379, int timeoutS = 5, int timeoutNS = 0) {
        struct timeval timeoutStruct = {
            timeoutS,
            timeoutNS
        };

        redisContext* ctx = redisConnectWithTimeout(host.c_str(), port, timeoutStruct);
        context.store(*ctx, std::memory_order_release);
    }

}

#endif
