/* Programming Abstractions in C++
 *
 * Exercise
 *
 * Write a recursive function digitSum(n) that takes a nonnegative integer and
 * returns the sum of its digits. For example, calling digitSum(1729) should
 * return 1 + 7 + 2 + 9, which is 19.
 *
 * The recursive implementation of digitSum depends on the fact that it is
 * very easy to break an integer down into two components using division by 10.
 * For example, given the integer 1729, you can divide it into two pieces as
 * follows:
 *
 *      1729
 *      ----
 *     /    \
 *    v      v
 *   172     9
 *
 * Each of the resulting integers is strictly smaller than the original and thus
 * represents a simpler case.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

int digitSum(int n);

int main() {
  std::cout << "digitSum(1729):       " << digitSum(1729) << std::endl;
  std::cout << "digitSum(1111):       " << digitSum(1111) << std::endl;
  std::cout << "digitSum(1234567890): " << digitSum(1234567890) << std::endl;
  std::cout << "digitSum(9999):       " << digitSum(9999) << std::endl;
  return 0;
}

int digitSum(int n) {
  if (n < 10)
    return n;
  return n % 10 + digitSum(n / 10);
}
