#include <gtest/gtest.h>

#include <example.h>

TEST(example, calculateFactorial) {
    EXPECT_EQ(calculateFactorial(0), 1);
    EXPECT_EQ(calculateFactorial(1), 1);
    EXPECT_EQ(calculateFactorial(5), 120);
    EXPECT_EQ(calculateFactorial(10), 3628800);
}
