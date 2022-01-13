/* Programming Abstractions in C++
 *
 * Exercise 12-13 (12-14 in book)
 *
 * Rewrite the rational.h and rational.cpp files so that the Rational
 * class is const correct.
 *
 * Solution 2021 Ben Mills
 */

#include "Rational.h"

#include <cassert>
#include <iostream>

int main() {
  Rational a(1, 4);
  Rational b(1, 2);
  assert(a + b == Rational(3, 4));
  assert(a - b == Rational(-1, 4));
  assert(a * b == Rational(1, 8));
  assert(a / b == Rational(1, 2));
  assert(a == Rational(1, 4));
  assert(a != b);
  assert(a != 0);
  assert(b < a == false);
  assert(a > b == false);
  assert(a >= a == true);
  assert(a >= b == false);
  assert(a <= a == true);
  assert(a <= b == true);
  assert((a += a) == b);                           // a = 1/2; b = 1/2
  assert((b -= Rational(1, 4)) == Rational(1, 4)); // a = 1/2; b = 1/4
  assert((b *= a) == Rational(1, 8));              // a = 1/2; b = 1/8
  assert((b /= a) == Rational(1, 4));              // a = 1/2; b = 1/4
  assert(a++ == Rational(1, 2));                   // a = 1 1/2; b = 1/4
  assert(++b == (Rational(1, 4) + 1));             // a = 1 1/2; b = 1 1/4
  assert(b-- == Rational(5, 4));                   // a = 1 1/2; b = -1/4
  assert(--a == Rational(1, 2));                   // a = 1/2; b = 1 1/4
  std::cout << "Rational class unit test succeeded." << std::endl;
  return 0;
}
