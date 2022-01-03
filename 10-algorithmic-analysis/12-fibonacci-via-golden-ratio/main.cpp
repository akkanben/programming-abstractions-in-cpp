/* Programming Abstractions in C++
 *
 * Exercise 10-12
 *
 * Exercise 1 shows that it is possible to compute x n in O (log N ) time. This
 * fact in turn makes it possible to write an implementation of the function
 * fib(n) that also runs in O (log N ) time, which is much faster than the
 * traditional iterative version. To do so, you need to rely on the somewhat
 * surprising fact that the Fibonacci function is closely related to a value
 * called the golden ratio, which has been known since the days of Greek
 * mathematics. The golden ratio, which is usually designated by the Greek
 * letter !, is defined to be the value that satisfies the equation
 *
 *  phi^2 – phi – 1 = 0
 *
 * Because this is a quadratic equation, it actually has two roots. If you apply
 * the quadratic formula, you will discover that these roots are
 *
 *  phi = 1 + sqrt(5) / 2
 *
 *  phi = 1 - sqrt(5) / 2
 *
 * In 1718, the French mathematician Abraham de Moivre discovered that the
 * Nth Fibonacci number can be represented in closed form as
 *
 * phi^n - phi^n / sqrt(5)
 *
 * Moreover, because phi^n is always very small, the formula can be simplified
 * to
 *
 * phi^n / sqrt(5)
 *
 * rounded to the nearest integer.
 *
 * Use this formula and the raiseToPower function from exercise 1 to write
 * an implementation of fib(n) that runs in O(log N) time. Once you have
 * verified empirically that the formula seems to work for the first several
 * terms in the sequence, use mathematical induction to prove that the formula
 * actually computes the nth Fibonacci number.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <math.h>

double const PHI = (1.0 + sqrt(5.0)) / 2.0;

int fib(int n);
double logNRaiseToPower(double x, int n);

int main() {
  std::cout << "fib(n) in O(log N) time" << std::endl;
  for (int i = 1; i <= 20; i++) {
    std::cout << "Fibonacci " << i << ": " << fib(i) << std::endl;
  }
  return 0;
}

int fib(int n) { return round(logNRaiseToPower(PHI, n) / sqrt(5)); }

double logNRaiseToPower(double x, int n) {
  if (n == 1)
    return x;
  double reducedPower = logNRaiseToPower(x, n / 2);
  if (n % 2 == 1)
    return reducedPower * reducedPower * x;
  else
    return reducedPower * reducedPower;
}
