/* Programming Abstractions in C++
 *
 * Exercise 10-01
 *
 * It is easy to write a recursive function
 *
 *  double raiseToPower(double x, int n)
 *
 * that calculates xn, by relying on the recursive insight that
 *
 *  x^n = x * x^n–1
 *
 * Such a strategy leads to an implementation that runs in linear time. You can,
 * however, adopt a recursive divide-and-conquer strategy which takes advantage
 * of the fact that
 *
 * x^2n = x^n * x^n
 *
 * Use this fact to write a recursive version of raiseToPower that runs in
 * O(log N) time.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

double logNRaiseToPower(double x, int n);

int main() {
  std::cout << "O(log N) recursive raiseToPower()" << std::endl;
  for (int i = 1; i < 20; i++) {
    std::cout << "2^" << i << " = " << logNRaiseToPower(2.0, i) << std::endl;
  }
  return 0;
}

double logNRaiseToPower(double x, int n) {
  if (n == 1)
    return x;
  double reducedPower = logNRaiseToPower(x, n / 2);
  if (n % 2 == 1)
    return reducedPower * reducedPower * x;
  else
    return reducedPower * reducedPower;
}
