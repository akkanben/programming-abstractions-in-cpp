/* Programming Abstractions in C++
 *
 * Exercise 01-07
 *
 * Using the AddIntegerList program from Figure 1-5 as a model, write a
 * program AverageList that reads in a list of integers representing exam scores
 * and then prints out the average. Because some unprepared student might
 * actually get a score of 0, your program should use !1 as the sentinel to mark
 the
 * end of the input.

 * Solution 2021 Ben Mills
 */

#include <iostream>

const int SENTINEL = -1;

int main() {
  int value;
  int runningTotal = 0;
  int count = 0;
  std::cout << "This program finds the averages integers in a list."
            << std::endl;
  std::cout << "Enter " << SENTINEL << " to signal the end of the list."
            << std::endl;
  while (value != SENTINEL) {
    std::cout << "? ";
    std::cin >> value;
    if (value == SENTINEL)
      break;
    runningTotal += value;
    count++;
  }
  std::cout << "The average score was " << runningTotal / count << "."
            << std::endl;
  return 0;
}
