/* Programming Abstractions in C++
 *
 * Exercise 07-01
 *
 * Spherical objects, such as cannonballs, can be stacked to form a pyramid with
 * one cannonball at the top, sitting on top of a square composed of four
 * cannonballs, sitting on top of a square composed of nine cannonballs, and so
 * forth. Write a recursive function cannonball that takes as its argument the
 * height of the pyramid and returns the number of cannonballs it contains. Your
 * function must operate recursively and must not use any iterative constructs,
 * such as while or for.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

int cannonballs(int height);

int main() {
  for (int i = 1; i <= 10; i++) {
    std::cout << "A cannonball pyramid " << i << " levels high would need "
              << cannonballs(i) << " cannonballs to build." << std::endl;
  }
  return 0;
}

int cannonballs(int height) {
  if (height < 1)
    return 0;
  else if (height == 1)
    return 1;
  else
    return height * height + cannonballs(height - 1);
}
