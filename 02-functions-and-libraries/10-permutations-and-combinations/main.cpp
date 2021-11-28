/* Programming Abstractions in C++
 *
 * Exercise 02-10
 *
 * The C(n, k) function from the text and the P(n, k) function from the
 * preceding exercise come up often in computational mathematics, particularly
 * in an area called combinatorics, which is concerned with counting the ways
 * objects can be combined. Now that you have C++ implementations for each of
 * these functions, it might be worth putting them in a library so that you can
 * use them in many different applications.
 *
 * Write the files combinatorics.h and combinatorics.cpp for a library
 * that exports the functions permutations and combinations. When you
 * write the implementation, make sure to rewrite the code for the combinations
 * function so that it uses the efficiency enhancements suggested for
 * permutations in exercise 9.
 *
 *
 * Solution 2021 Ben Mills
 */

#include "combinatorics.h"
#include <iostream>

void getValues(int &n, int &k);

int main() {
  int n;
  int k;

  getValues(n, k);

  std::cout << "There are " << permutations(n, k) << " permutations with " << n
            << " values in sets of " << k << std::endl;

  std::cout << "There are " << combinations(n, k) << " combinations with " << n
            << " values in sets of " << k << std::endl;

  return 0;
}

void getValues(int &n, int &k) {
  std::cout << "Enter the number of elements: ";
  std::cin >> n;
  std::cout << "Enter the number per set: ";
  std::cin >> k;
}
