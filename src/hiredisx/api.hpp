#include <hiredis.h>
#include <string>
#include <vector>
#include <type_traits>

#include "connect.hpp"
#include "command.hpp"

#ifndef _HIREDISX_API_H
#define _HIREDISX_API_H 1

namespace hiredisx {

    std::string get(std::string key) {
        std::string command = "GET " + key;
        redisReply* reply = hiredisx::op::command(command.c_str());

        std::string value;

        if (reply->type == REDIS_REPLY_ERROR) {
            value.assign(reply->str, reply->len);
        } else {
            value.assign(reply->str, reply->len);
        }

        freeReplyObject(reply);
        return value;
    }

    bool set(std::string key, std::string value) {
        std::string command = "SET " + key + " " + value;
        redisReply* reply = hiredisx::op::command(command.c_str());

        bool success = reply->type != REDIS_REPLY_ERROR;
        freeReplyObject(reply);

        return success;
    }

    bool del(std::string key) {
        std::string command = "DEL " + key;
        redisReply* reply = hiredisx::op::command(command.c_str());

        bool success = reply->type != REDIS_REPLY_ERROR;
        freeReplyObject(reply);

        return success;
    }

    bool push(std::string key, std::string value, std::string prefix = "L") {
        std::string command = prefix + "PUSH " + key + " " + value;
        redisReply* reply = hiredisx::op::command(command.c_str());

        bool success = reply->type != REDIS_REPLY_ERROR;
        freeReplyObject(reply);

        return success;
    }

    std::vector<std::string> getList(std::string key, int start = 0, int end = -1, std::string prefix = "L") {
        std::string command = prefix + "RANGE " + key + " " + std::to_string(start) + " " + std::to_string(end);
        redisReply* reply = hiredisx::op::command(command.c_str());

        std::vector<std::string> list;

        if (reply->type == REDIS_REPLY_ARRAY) {
            for (int i = 0; i < reply->elements; i++) {
                redisReply* element = reply->element[i];

                std::string elementValue;
                elementValue.assign(element->str, element->len);

                list.push_back(elementValue);
            }
        }

        freeReplyObject(reply);

        return list;
    }

}

#endif
