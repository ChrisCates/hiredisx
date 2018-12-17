#define BOOST_TEST_MODULE "Hiredisx Threadsafety tests"

#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <string>
#include <iostream>
#include <thread>
#include "hiredisx.hpp"

BOOST_AUTO_TEST_SUITE(Threadsafety)

BOOST_AUTO_TEST_CASE(ThreadPool) {
    boost::thread_group pool;

    std::cout << "Creating threads..." << std::endl;

    for (int i = 0; i < 10; i++) {
        boost::thread *t = new boost::thread([=]() mutable {
            std::cout << "Created thread " << std::to_string(i) << std::endl;
            std::string test = hiredisx::ping();
            std::cout << "Thread message " << test << std::endl;
            BOOST_CHECK_EQUAL(test, "PONG");
            std::cout << "Finished with thread " << std::to_string(i) << std::endl;
        });

        pool.add_thread(t);
    }

    pool.join_all();
}

BOOST_AUTO_TEST_SUITE_END()
