/* Programming Abstractions in C++
 *
 * Exercise 01.01
 *
 * Write a program that reads in a temperature in degrees Celsius and displays
 * the corresponding temperature in degrees Fahrenheit. The conversion formula
 * is F = 9/5C + 32
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

int main() {
  double celsius;
  std::cout << "Enter a degree in Celsius: ";
  std::cin >> celsius;
  std::cout << celsius << std::endl;
  double farenheit = 9.0 / 5.0 * celsius + 32.0;
  std::cout << farenheit << std::endl;
  std::cout << std::endl
            << celsius << " degrees Celsius in Fahrenheit is: " << farenheit
            << std::endl;
  return 0;
}
