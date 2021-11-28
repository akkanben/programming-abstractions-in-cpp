/* Programming Abstractions in C++
 *
 * Exercise 02-07
 *
 * Even though clients of the <cmath> library typically don’t need to understand
 * how functions like sqrt work internally, the implementers of that library
 * have to be able to design an effective algorithm and write the necessary
 * code. If you were asked to implement the sqrt function without using the
 * library version, there are many strategies you could adopt. One of the
 * easiest strategies to understand is successive approximation in which you
 * make a guess at the solution and then refine that guess by choosing new
 * values that move closer to the solution.
 *
 * You can use successive approximation to determine the square root of x by
 * adopting the following strategy:
 *
 *   1. Begin by guessing that the square root is x / 2. Call that guess g.
 *   2. The actual square root must lie between g and x / g. At each step in the
 *      successive approximation, generate a new guess by averaging g and x / g.
 *   3. Repeat step 2 until the values g and x / g are as close together as the
 *      machine precision allows. In C++, the best way to check for this
 * condition is to test whether the average is equal to either of the values
 * used to generate it.
 *
 * Use this strategy to write your own implementation of the sqrt function.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

double sqrt(double x);

int main() {
  float n;
  std::cout << "Enter a number to find the square root of: ";
  std::cin >> n;
  std::cout << std::endl;
  std::cout << "The root is " << sqrt(n) << std::endl;
  return 0;
}

double sqrt(double x) {
  double g = x / 2;
  double average = (g + (x / g)) / 2;
  while (true) {
    g = average;
    average = (g + (x / g)) / 2;
    if (average == g || average == x / g) {
      break;
    }
  }
  return average;
}
