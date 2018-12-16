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
    redisContext* ctx = hiredisx::connect();

    bool error = (bool) ctx->err;

    BOOST_CHECK_EQUAL(error, false);

    bool cleared = hiredisx::disconnect(ctx);

    BOOST_CHECK_EQUAL(cleared, true);
}

BOOST_AUTO_TEST_CASE(ConnectFailure) {
    hiredisx::options.host = "foobar";
    redisContext* ctx = hiredisx::connect();

    BOOST_CHECK_EQUAL(ctx->err, 2);
    BOOST_CHECK_EQUAL(ctx->errstr, "nodename nor servname provided, or not known");
}

BOOST_AUTO_TEST_CASE(CanConnect) {
    hiredisx::options.host = "localhost";
    bool connectable = hiredisx::canConnect();

    BOOST_CHECK_EQUAL(connectable, true);

    hiredisx::options.host = "foobar";
    bool notConnectable = hiredisx::canConnect();

    BOOST_CHECK_EQUAL(notConnectable, false);
}


BOOST_AUTO_TEST_SUITE_END()
