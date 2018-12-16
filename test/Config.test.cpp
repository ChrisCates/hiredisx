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
    bool opened = hiredisx::connect();

    BOOST_CHECK_EQUAL(opened, true);

    bool cleared = hiredisx::disconnect();

    BOOST_CHECK_EQUAL(cleared, true);
}

BOOST_AUTO_TEST_CASE(ConnectFailure) {
    bool opened = hiredisx::connect("foobar");

    BOOST_CHECK_EQUAL(opened, false);
}


BOOST_AUTO_TEST_SUITE_END()
