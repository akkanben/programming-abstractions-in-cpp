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
  int comb = 1;
  int k_count = 1;
  int steps = n - (n - k);
  for (int i = 0; i < steps; i++) {
    comb *= n;
    n -= 1;
  }
  for (int i = 1; i <= k; i++) {
    k_count *= i;
  }
  comb /= k_count;
  return comb;
}
