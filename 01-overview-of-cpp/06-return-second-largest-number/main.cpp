/* Programming Abstractions in C++
 *
 * Exercise 01-06
 *
 * For a slightly more interesting challenge, write a program that finds both
 * the largest and the second-largest number in a list, prior to the entry of a
 * sentinel.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

const int SENTINEL = 0;

int main() {
  int value;
  int largest = 0;
  int secondLargest = 0;
  std::cout
      << "This program finds the largest and second largest integer in a list."
      << std::endl;
  std::cout << "Enter " << SENTINEL << " to signal the end of the list."
            << std::endl;
  while (value != SENTINEL) {
    std::cout << "? ";
    std::cin >> value;
    if (value == SENTINEL)
      break;
    if (value > largest) {
      secondLargest = largest;
      largest = value;
    } else if (value > secondLargest) {
      secondLargest = value;
    }
  }
  std::cout << "The largest value was " << largest << "." << std::endl;
  std::cout << "The second largest value was " << secondLargest << "."
            << std::endl;
  return 0;
}
