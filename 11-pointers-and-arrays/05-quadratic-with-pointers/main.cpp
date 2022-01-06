/* Programming Abstractions in C++
 *
 * Exercise 11-05
 *
 * Rewrite the Quadratic program from Figure 2-3 so that it uses explicit
 * pointers instead of call by reference to return values from the functions
 * getCoefficients and solveQuadratic.
 *
 * Solution 2021 Ben Mills
 */

#include <cmath>
#include <cstdlib>
#include <iostream>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/simpio.h"

void getCoefficients(double *a, double *b, double *c);
void solveQuadratic(double *a, double *b, double *c, double *x1, double *x2);
void printRoots(double x1, double x2);

int main() {
  double a, b, c, r1, r2;
  getCoefficients(&a, &b, &c);
  solveQuadratic(&a, &b, &c, &r1, &r2);
  printRoots(r1, r2);
  return 0;
}

void getCoefficients(double *a, double *b, double *c) {
  *a = getReal("a: ");
  *b = getReal("b: ");
  *c = getReal("c: ");
}

void solveQuadratic(double *a, double *b, double *c, double *x1, double *x2) {
  if (a == 0)
    error("The coefficient a must be nonzero");
  double disc = *b * *b - 4 * *a * *c;
  if (disc < 0)
    error("This equation has no real roots");
  double sqrtDisc = std::sqrt(disc);
  *x1 = (-*b + sqrtDisc) / (2 * *a);
  *x2 = (-*b - sqrtDisc) / (2 * *a);
}

void printRoots(double x1, double x2) {
  if (x1 == x2)
    std::cout << "There is a double root at " << x1 << std::endl;
  else
    std::cout << "The roots are " << x1 << " and " << x2 << std::endl;
}
