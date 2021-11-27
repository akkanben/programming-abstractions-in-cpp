/* Programming Abstractions in C++
 *
 * Exercise 01.04
 *
 * Write a program that reads in a positive integer N and then calculates and
 * displays the sum of the first N odd integers. For example, if N is 4, your
 * program should display the value 16, which is 1 + 3 + 5 + 7.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

int main() {
  int numberOfIntegers;
  int sum = 0;
  int currentNumber = 1;
  std::cout << "Please enter the number of odd integers you would like to add "
               "together: ";
  std::cin >> numberOfIntegers;
  for (int i = 0; i < numberOfIntegers; i++) {

    if (i == 0) {
      std::cout << currentNumber;
    } else {
      std::cout << " + " << currentNumber;
    }
    sum += currentNumber;
    currentNumber = currentNumber + 2;
  }
  std::cout << ".\n\n"
            << "The sum is " << sum << "." << std::endl;
  return 0;
}
