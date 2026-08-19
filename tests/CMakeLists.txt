cmake_minimum_required(VERSION 3.15)

find_package(GTest REQUIRED)

add_executable(conan-library-a-tests
    test_sum.cpp
)

target_link_libraries(conan-library-a-tests
    PRIVATE
        conan-library-a::conan-library-a
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(conan-library-a-tests)
