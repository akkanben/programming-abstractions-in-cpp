/* Programming Abstractions in C++
 *
 * Exercise 01.03
 *
 * As mathematical historians have told the story, the German mathematician Carl
 * Friedrich Gauss (1777-1855) began to show his mathematical talent at a very
 * early age. When he was in elementary school, Gauss was asked by his teacher
 * to compute the sum of the numbers between 1 and 100. Gauss is said to have
 * given the answer instantly: 5050.
 *
 * Write a program that computes the answer to the question Gauss’s teacher
 * posed.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

int main() {
  int runningTotal = 0;
  for (int i = 1; i <= 100; i++) {
    runningTotal += i;
    std::cout << i << "  : " << runningTotal << std::endl;
  }
  return 0;
}
