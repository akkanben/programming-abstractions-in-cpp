/* Programming Abstractions in C++
 *
 * Exercise 06-08
 *
 * The Rational class presented in the text defines the operators +, –, *, / but
 * needs several other operators for completeness. Add the following operators
 * to both the interface and implementation:
 *
 *  • The relational operators ==, !=, <, <=, >, and >=
 *  • The shorthand assignment operators +=, -=, *=, and /=
 *  • The ++ and -- operators in both their prefix and suffix form.
 *
 * Solution 2021 Ben Mills
 */

#include "Rational.h"
#include <iostream>

int main() {
  Rational a(1, 4);
  for (Rational i(1, 2); i < Rational(6 / 2); i++) {
    std::cout << a << " + " << i.toString() << " = " << (a + i).toString()
              << std::endl;
    std::cout << a << " - " << i.toString() << " = " << (a - i).toString()
              << std::endl;
    std::cout << a << " * " << i.toString() << " = " << (a * i).toString()
              << std::endl;
    std::cout << a << " / " << i.toString() << " = " << (a / i).toString()
              << std::endl;
  }
  return 0;
}
