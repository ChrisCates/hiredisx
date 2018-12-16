#include <hiredis.h>
#include <string>

#ifndef _HIREDISX_CONNECT_H
#define _HIREDISX_CONNECT_H 1

namespace hiredisx {

    struct OptionsStruct {
        std::string host = "localhost";
        int port = 6379;
        int timeoutS = 5;
        int timeoutNS = 0;
    } options;

    redisContext* connect() {
        struct timeval timeoutStruct = {
            options.timeoutS,
            options.timeoutNS
        };

        redisContext* ctx = redisConnectWithTimeout(options.host.c_str(), options.port, timeoutStruct);
        return ctx;
    }

    bool disconnect(redisContext* context) {
        redisFree(context);
        return true;
    }

    bool canConnect() {
        redisContext* ctx = hiredisx::connect();
        int status = ctx->err;
        
        hiredisx::disconnect(ctx);

        return status == 0 ? true : false;
    }

}

#endif
