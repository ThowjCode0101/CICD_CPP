#include "example.h"
#include <string>
#include <vector>

// Function 1: Calculate factorial
int calculateFactorial(int n) {
    if (n <= 1) return 1;
    return n * calculateFactorial(n - 1);
}

// Function 2: Reverse a string
std::string reverseString(const std::string& input) {
    return std::string(input.rbegin(), input.rend());
}

// Function 3: Find maximum in vector
double findMaximum(const std::vector<double>& numbers) {
    if (numbers.empty()) return 0.0;
    double max = numbers[0];
    for (const auto& num : numbers) {
        if (num > max) max = num;
    }
    return max;
}

// Function 4: Check if number is prime
bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

// Function 5: Generate Fibonacci sequence
std::vector<int> generateFibonacci(int n) {
    std::vector<int> fib;
    if (n <= 0) return fib;
    
    fib.push_back(0);
    if (n == 1) return fib;
    
    fib.push_back(1);
    for (int i = 2; i < n; i++) {
        fib.push_back(fib[i-1] + fib[i-2]);
    }
    return fib;
}

double add_numbers(const double f1, const double f2) { return f1 + f2; }

double subtract_numbers(const double f1, const double f2) { return f1 - f2; }

double multiply_numbers(const double f1, const double f2) { return f1 * f2; }
