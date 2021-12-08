/* Programming Abstractions in C++
 *
 * Exercise
 *
 * The digital root of an integer n is defined as the result of summing the
 * digits repeatedly until only a single digit remains. For example, the digital
 * root of 1729 can be calculated using the following steps:
 *
 *  Step 1:   1 + 7 + 2 + 9   -->   19
 *  Step 2:   1 + 9           -->   10
 *  Step 3:   1 + 0           -->    1
 *
 * Because the total at the end of step 3 is the single digit 1, that value is
 * the digital root.
 *
 * Write a function digitalRoot(n) that returns the digital root of its
 * argument. Although it is easy to implement digitalRoot using the
 * digitSum function from exercise 6 and a while loop, part of the challenge of
 * this problem is to write the function recursively without using any explicit
 * loop constructs.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

int digitalRoot(int n);

int digitSum(int n);

int main() {
  std::cout << "digitalRoot(1729):       " << digitalRoot(1729) << std::endl;
  std::cout << "digitalRoot(1111):       " << digitalRoot(1111) << std::endl;
  std::cout << "digitalRoot(1234567890): " << digitalRoot(1234567890)
            << std::endl;
  std::cout << "digitalRoot(9999):       " << digitalRoot(9999) << std::endl;
  return 0;
}

int digitSum(int n) {
  if (n < 10)
    return n;
  return n % 10 + digitSum(n / 10);
}

int digitalRoot(int n) {
  if (n < 10)
    return n;
  return digitalRoot(digitSum(n));
}
