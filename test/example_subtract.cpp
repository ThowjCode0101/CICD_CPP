#include <gtest/gtest.h>

#include "example.h"

TEST(example, subtract) {
  double res;
  res = subtract_numbers(1.0, 2.0);
  ASSERT_NEAR(res, -1.0, 1.0e-11);
}
 TEST(example, findMaximum) {
  std::vector<double> numbers = {1.0, 2.0, 3.0, 4.0, 5.0};
  double max = findMaximum(numbers);
  ASSERT_NEAR(max, 5.0, 1.0e-11);
  numbers = {5.0, 4.0, 3.0, 2.0, 1.0};
  max = findMaximum(numbers);
  ASSERT_NEAR(max, 5.0, 1.0e-11);
  numbers = {3.0, 1.0, 4.0, 2.0, 5.0};
  max = findMaximum(numbers);
  ASSERT_NEAR(max, 5.0, 1.0e-11);
  numbers = {};
  max = findMaximum(numbers);
  ASSERT_NEAR(max, 0.0, 1.0e-11); // Assuming empty vector returns 0.0
  numbers = {1.0};
  max = findMaximum(numbers);
  ASSERT_NEAR(max, 1.0, 1.0e-11); // Single element vector
}