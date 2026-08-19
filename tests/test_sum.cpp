#include <gtest/gtest.h>
#include <conan-library-a/sum.hpp>
#include <stdexcept>

using namespace conan_library_a;
using json = nlohmann::json;

TEST(SumTest, IntegerAddition) {
    EXPECT_EQ(sum(json(1), json(2)), json(3));
    EXPECT_EQ(sum(json(-5), json(5)), json(0));
    EXPECT_EQ(sum(json(100), json(200)), json(300));
}

TEST(SumTest, FloatAddition) {
    EXPECT_DOUBLE_EQ(sum(json(1.5), json(2.5)).get<double>(), 4.0);
    EXPECT_DOUBLE_EQ(sum(json(0.1), json(0.2)).get<double>(), 0.1 + 0.2);
}

TEST(SumTest, MixedNumericTypes) {
    EXPECT_DOUBLE_EQ(sum(json(1), json(2.5)).get<double>(), 3.5);
}

TEST(SumTest, ThrowsOnNonNumeric) {
    EXPECT_THROW(sum(json("hello"), json("world")), std::invalid_argument);
    EXPECT_THROW(sum(json(true), json(false)), std::invalid_argument);
}
