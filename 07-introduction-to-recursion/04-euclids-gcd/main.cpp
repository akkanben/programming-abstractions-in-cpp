/* Programming Abstractions in C++
 *
 * Exercise 7-04
 *
 * The greatest common divisor (often abbreviated to gcd) of two nonnegative
 * integers is the largest integer that divides evenly into both. In the third
 * century BCE, the Greek mathematician Euclid discovered that the greatest
 * common divisor of x and y can always be computed as follows:
 *
 *  • If x is evenly divisible by y, then y is the greatest common divisor.
 *
 *  • Otherwise, the greatest common divisor of x and y is always equal to the
 *    greatest common divisor of y and the remainder of x divided by y.
 *
 * Use Euclid’s insight to write a recursive function gcd(x, y) that computes
 * the greatest common divisor of x and y.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/error.h"

int gcd(int x, int y);

int main() {
  for (int i = 1; i < 100; i++) {
    for (int j = i; j < 100; j++) {
      int value = gcd(i, j);
      if (i != j && value != j && value != i && value != j && value > 2)
        std::cout << "The GCD of " << i << " and " << j << " is: " << value
                  << std::endl;
    }
  }
  return 0;
}

int gcd(int x, int y) {
  if (x < 1 || y < 1) {
    error("GCD: invalid argument.");
    return -1;
  } else if (x % y == 0)
    return y;
  else
    return gcd(y, x % y);
}
