#include "Fixed.hpp"
#include <iostream>
#include <limits>

void test_arithmetic_operators() {
    std::cout << "\n=== Arithmetic Operators ===" << std::endl;
    Fixed a(10.5f);
    Fixed b(2.2f);

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;
}

void test_comparison_operators() {
    std::cout << "\n=== Comparison Operators ===" << std::endl;
    Fixed a(10.5f);
    Fixed b(10.5f);
    Fixed c(5.25f);

    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    std::cout << "a == b: " << (a == b) << " (expected: 1)" << std::endl;
    std::cout << "a == c: " << (a == c) << " (expected: 0)" << std::endl;
    std::cout << "a != c: " << (a != c) << " (expected: 1)" << std::endl;
    std::cout << "a > c: " << (a > c) << " (expected: 1)" << std::endl;
    std::cout << "c < a: " << (c < a) << " (expected: 1)" << std::endl;
    std::cout << "a >= b: " << (a >= b) << " (expected: 1)" << std::endl;
    std::cout << "a <= c: " << (a <= c) << " (expected: 0)" << std::endl;
}

void test_increment_decrement() {
    std::cout << "\n=== Increment/Decrement Operators ===" << std::endl;
    Fixed a;

    std::cout << "Initial a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a after prefix ++: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a after postfix ++: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a after prefix --: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a after postfix --: " << a << std::endl;
}

void test_min_max() {
    std::cout << "\n=== Min/Max Functions ===" << std::endl;
    Fixed a(15.75f);
    Fixed const b(7.25f);
    Fixed const c(7.25f);

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
}

int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "Basic tests from subject:" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    // Extra tests
    // test_arithmetic_operators();
    // test_comparison_operators();
    // test_increment_decrement();
    // test_min_max();

    return 0;
}