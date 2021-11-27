/* Programming Abstractions in C++
 *
 * Exercise 02-01
 *
 * If you did not do so the first time around, rewrite the Celsius-to-Fahrenheit
 * program from exercise 1 in Chapter 1 so that it uses a function to perform
 the
 * conversion.

 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

double convertToFahrenheit(double value);

const int SENTINEL = 0;

int main() {
  double value;
  while (true) {
    std::cout << "Enter a value in Celcius to convert to Fahrenheit: ";
    std::cin >> value;
    if (value == SENTINEL)
      break;
    std::cout << value << " in Celcius would be " << convertToFahrenheit(value)
              << std::endl;
  }
  std::cout << "goodbye." << std::endl;
  return 0;
}

double convertToFahrenheit(double value) { return (1.8 * value) + 32; }
