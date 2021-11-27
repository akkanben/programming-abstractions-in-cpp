/* Programming Abstractions in C++
 *
 * Exercise 01-05
 *
 * Write a program that reads in a list of integers from the user until the user
 * enters the value 0 as a sentinel. Be sure to define the sentinel value as a
 * constant in a way that makes it easy to change. You should also make sure
 * that the program works correctly if all the input values are negative.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

const int SENTINEL = 0;

int main() {
  int value;
  int largest = 0;
  std::cout << "This program finds the largest integer in a list." << std::endl;
  std::cout << "Enter " << SENTINEL << " to signal the end of the list."
            << std::endl;
  while (value != SENTINEL) {
    std::cout << "? ";
    std::cin >> value;
    if (value == SENTINEL)
      break;
    if (value > largest)
      largest = value;
  }
  std::cout << "The largest value was " << largest << "." << std::endl;
  return 0;
}
