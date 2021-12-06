/* Programming Abstractions in C++
 *
 * Exercise 02-10
 *
 * Combinatorics implementation
 *
 */

#include "combinatorics.h"

int permutations(int n, int k) {
  int steps = n - (n - k);
  int perm = n;
  for (int i = 1; i < steps; i++) {
    perm *= n - 1;
  }
  return perm;
}

int combinations(int n, int k) {
  double numerator = 1;
  double denominator = 1;
  int n_steps = n - (n - k);
  for (int i = 0; i < n_steps; i++) {
    numerator *= n;
    n -= 1;
  }
  for (int i = 1; i <= k; i++) {
    denominator *= i;
  }
  return numerator / denominator;
}
