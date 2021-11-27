/* Programming Abstractions in C++
 *
 * Exercise 01-08
 *
 * Using the digitSum function from the section entitled “The while statement”
 * as a model, write a program that reads in an integer and then displays the
 * number that has the same digits in the reverse order.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

/* Function Prototypes */
void coutReversedNumber(int number);

int main() {
  int number;
  std::cout << "This program reverses the digits in an integer." << std::endl;
  std::cout << "Enter a positive integer: ";
  std::cin >> number;
  std::cout << "The reversed integer is ";
  coutReversedNumber(number);
  return 0;
}

void coutReversedNumber(int number) {
  while (number > 0) {
    std::cout << number % 10;
    number /= 10;
  }
  std::cout << std::endl;
}
