#define BOOST_TEST_MODULE "Hiredisx Command tests"

#include <boost/test/unit_test.hpp>
#include <string>
#include <iostream>
#include "hiredisx.hpp"

BOOST_AUTO_TEST_SUITE(Config)

BOOST_AUTO_TEST_CASE(CommandPing) {
    hiredisx::connect();
    redisContext context = hiredisx::context.load(std::memory_order_acquire);

    BOOST_CHECK_EQUAL(context.err, 0);

    redisReply reply = hiredisx::command("PING");
    BOOST_CHECK_EQUAL(reply.str, "PONG");
}

BOOST_AUTO_TEST_SUITE_END()
