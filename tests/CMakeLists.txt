add_executable(concurrency_tests
    test_atomic.cpp
    test_spinlock.cpp
)

target_link_libraries(concurrency_tests
    PRIVATE concurrency
    PRIVATE gtest_main
)

include(GoogleTest)
gtest_discover_tests(concurrency_tests)
