#define BOOST_TEST_MODULE "Hiredisx Command tests"

#include <boost/test/unit_test.hpp>
#include <string>
#include <vector>
#include <iostream>

#include "hiredisx.hpp"

BOOST_AUTO_TEST_SUITE(Command)

BOOST_AUTO_TEST_CASE(CommandPing) {
    hiredisx::connect();

    redisReply* reply = hiredisx::op::command("PING");
    BOOST_CHECK_EQUAL(reply->str, "PONG");
    freeReplyObject(reply);

    hiredisx::disconnect();
}

BOOST_AUTO_TEST_CASE(ApiSetFoo) {
    hiredisx::connect();

    bool success = hiredisx::set("foo", "bar");
    BOOST_CHECK_EQUAL(success, true);

    hiredisx::disconnect();
}

BOOST_AUTO_TEST_CASE(ApiGetFoo) {
    hiredisx::connect();

    std::string foo = hiredisx::get("foo");
    BOOST_CHECK_EQUAL(foo, "bar");

    hiredisx::disconnect();
}

BOOST_AUTO_TEST_CASE(ApiDelFoo) {
    hiredisx::connect();

    bool deleted = hiredisx::del("foo");
    BOOST_CHECK_EQUAL(deleted, true);

    hiredisx::disconnect();
}

BOOST_AUTO_TEST_CASE(ApiPushList) {
    hiredisx::connect();

    bool pushed;

    pushed = hiredisx::push("list", "yo", "R");
    BOOST_CHECK_EQUAL(pushed, true);

    pushed = hiredisx::push("list", "ay", "R");
    BOOST_CHECK_EQUAL(pushed, true);

    pushed = hiredisx::push("list", "yung", "R");
    BOOST_CHECK_EQUAL(pushed, true);

    hiredisx::disconnect();
}

BOOST_AUTO_TEST_CASE(ApiGetList) {
    hiredisx::connect();

    std::vector<std::string> list = hiredisx::getList("list");

    BOOST_CHECK_EQUAL(list.size(), 3);

    BOOST_CHECK_EQUAL(list[0], "yo");
    BOOST_CHECK_EQUAL(list[1], "ay");
    BOOST_CHECK_EQUAL(list[2], "yung");

    bool deleted = hiredisx::del("list");
    BOOST_CHECK_EQUAL(deleted, true);


    hiredisx::disconnect();
}

BOOST_AUTO_TEST_SUITE_END()
