/* Programming Abstractions in C++
 *
 * Exercise 02-09
 *
 * The combinations function C(n, k) described in this chapter determines the
 * number of ways you can choose k values from a set of n elements, ignoring the
 * order of the elements. If the order of the value matters—so that, in the case
 * of the coin example, choosing a quarter first and then a dime is seen as
 * distinct from choosing a dime and then a quarter—you need to use a different
 * function, which computes the number of permutations. This function is denoted
 * as P(n, k), and has the following mathematical formulation:
 *
 * P(n, k) = n!/ (n-k)!
 *
 * Although this definition is mathematically correct, it is not well suited to
 * implementation in practice because the factorials involved can get much too
 * large to store in an integer variable, even when the answer is small. For
 * example, if you tried to use this formula to calculate the number of ways to
 * select two cards from a standard 52-card deck, you would end up trying to
 * evaluate the following fraction:
 *
 * <very large numerator & denominator fracion>
 *
 * Even though the answer is the much more manageable 2652 (52 x 51).
 *
 * Write a function permutations(n, k) that computes the P(n, k) function
 * without calling the fact function. Part of your job in this problem is to
 * figure out how to compute this value efficiently. To do so, you will probably
 * find it useful to play around with some relatively small values to get a
 * sense of how the factorials in the numerator and denominator of the formula
 * behave.
 *
 * Solution 2021 Ben Mills
 *
 * If we evaluate the permutation fraction before factoring we can reduce the
 * overhead of by reducing the fraction. For example if we find permutations of
 * 2 in a set of five:
 *
 *   5! / (5 - 2)!  =  5! / 3!
 *
 *   5 * 4 * 3 * 2 * 1
 *   -----------------  =  5 * 4 = 20
 *           3 * 2 * 1
 *
 * So if we subtract n from (n - k) we know how many steps of n! are needed. In
 * this example 5 - (5 - 2) = 2 so we only need the first 2 steps of 5!.
 *
 */

#include <iostream>

int permutations(int n, int k);
void getValues(int &n, int &k);

int main() {
  int n;
  int k;
  getValues(n, k);
  std::cout << "There are " << permutations(n, k) << " permutations with " << n
            << " values in sets of " << k << std::endl;
  return 0;
}

int permutations(int n, int k) {
  int steps = n - (n - k);
  int perm = n;
  for (int i = 1; i < steps; i++) {
    perm *= n - 1;
  }
  return perm;
}

void getValues(int &n, int &k) {
  std::cout << "Enter the number of elements: ";
  std::cin >> n;
  std::cout << "Enter the number per set: ";
  std::cin >> k;
}
