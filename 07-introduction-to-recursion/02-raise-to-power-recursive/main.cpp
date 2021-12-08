/* Programming Abstractions in C++
 *
 * Exercise 07-02
 *
 * Unlike many programming languages, C++ does not include a predefined
 * operator that raises a number to a power. As a partial remedy for this
 * deficiency, write a recursive implementation of a function
 *
 *  int raiseToPower(int n, int k)
 *
 * that calculates n^k . The recursive insight that you need to solve this
 * problem is the mathematical property that n^k = 1 if k is 0 n × n^k-1
 * otherwise
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

int raiseToPower(int n, int k);

int main() {
  std::cout << "Powers of Two:" << std::endl;
  for (int i = 1; i <= 20; i++) {
    std::cout << raiseToPower(2, i) << std::endl;
  }
  return 0;
}

int raiseToPower(int n, int k) {
  if (k == 0)
    return 1;
  else
    return n * raiseToPower(n, k - 1);
}
