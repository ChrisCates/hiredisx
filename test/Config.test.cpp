#define BOOST_TEST_MODULE "Hiredisx Configuration tests"

#include <boost/test/unit_test.hpp>
#include <string>
#include <iostream>
#include "hiredisx.hpp"

BOOST_AUTO_TEST_SUITE(Config)

BOOST_AUTO_TEST_CASE(ConfigVariables) {
    BOOST_CHECK_EQUAL(hiredisx::version, "0.0.1");
}

BOOST_AUTO_TEST_CASE(ConnectSuccess) {
    hiredisx::connect();
    redisContext context = hiredisx::context.load(std::memory_order_acquire);

    BOOST_CHECK_EQUAL(context.err, 0);
}

BOOST_AUTO_TEST_CASE(ConnectFailure) {
    hiredisx::connect("foobar");
    redisContext context = hiredisx::context.load(std::memory_order_acquire);

    BOOST_CHECK_EQUAL(context.err, 2);
    BOOST_CHECK_EQUAL(context.errstr, "nodename nor servname provided, or not known");
}


BOOST_AUTO_TEST_SUITE_END()
