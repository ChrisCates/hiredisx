#include <hiredis.h>
#include <string>

#include "connect.hpp"

#ifndef _HIREDISX_COMMAND_H
#define _HIREDISX_COMMAND_H 1

namespace hiredisx {

    namespace op {
        redisReply* command(std::string command) {
            redisContext* context = hiredisx::context.load(std::memory_order_acquire);
            redisReply* reply = (redisReply*) redisCommand(context, command.c_str());

            return reply;
        }
    }

}

#endif
