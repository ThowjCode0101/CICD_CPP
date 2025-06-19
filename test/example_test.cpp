#include <gtest/gtest.h>
#include "../src/example.h"
#include <vector>
#include <string>

// Test parameters for factorial
struct FactorialTestParam {
    int input;
    int expected;
};

// Test parameters for prime numbers
struct PrimeTestParam {
    int input;
    bool expected;
};

// Test Fixture class for non-parameterized tests
class ExampleTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code that will be called before each test
    }

    void TearDown() override {
        // Cleanup code that will be called after each test
    }
};

// Parameterized test fixture for factorial
class FactorialParamTest : public ::testing::TestWithParam<FactorialTestParam> {};

// Parameterized test fixture for prime numbers
class PrimeParamTest : public ::testing::TestWithParam<PrimeTestParam> {};

// Test factorial function - parameterized
TEST_P(FactorialParamTest, FactorialTest) {
    const auto& param = GetParam();
    EXPECT_EQ(calculateFactorial(param.input), param.expected);
}

// Test prime number checker - parameterized
TEST_P(PrimeParamTest, IsPrimeTest) {
    const auto& param = GetParam();
    EXPECT_EQ(isPrime(param.input), param.expected);
}


// Parameter instantiation for factorial tests
INSTANTIATE_TEST_SUITE_P(
    FactorialTests,
    FactorialParamTest,
    ::testing::Values(
        FactorialTestParam{0, 1},
        FactorialTestParam{1, 1},
        FactorialTestParam{5, 120}
    )
);

// Parameter instantiation for prime number tests
INSTANTIATE_TEST_SUITE_P(
    PrimeTests,
    PrimeParamTest,
    ::testing::Values(
        PrimeTestParam{2, true},
        PrimeTestParam{17, true},
        PrimeTestParam{4, false},
        PrimeTestParam{1, false},
        PrimeTestParam{0, false}
    )
);

// Test string reverse function
TEST_F(ExampleTest, ReverseStringTest) {
    EXPECT_EQ(reverseString("hello"), "olleh");
    EXPECT_EQ(reverseString(""), "");
    EXPECT_EQ(reverseString("a"), "a");
}

// Test find maximum function
TEST_F(ExampleTest, FindMaximumTest) {
    std::vector<double> numbers = {1.5, 3.14, 2.7, 0.8};
    EXPECT_DOUBLE_EQ(findMaximum(numbers), 3.14);
    
    std::vector<double> empty;
    EXPECT_DOUBLE_EQ(findMaximum(empty), 0.0);
}

// Test Fibonacci sequence generator
TEST_F(ExampleTest, FibonacciTest) {
    std::vector<int> expected_fib3 = {0, 1, 1};
    EXPECT_EQ(generateFibonacci(3), expected_fib3);
    
    std::vector<int> expected_fib5 = {0, 1, 1, 2, 3};
    EXPECT_EQ(generateFibonacci(5), expected_fib5);
    
    EXPECT_TRUE(generateFibonacci(0).empty());
}