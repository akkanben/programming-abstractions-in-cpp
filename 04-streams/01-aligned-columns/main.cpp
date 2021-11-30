/* Programming Abstractions in C++
 *
 * Exercise 04-01
 *
 * The <iomanip> library gives programmers more control over output format,
 * which makes it easy, for example, to create formatted tables. Write a program
 * that displays a table of trigonometric sines and cosines that looks like
 * this:
 *
 *  <image of output>
 *
 * The numeric columns should all be aligned on the right, and the columns
 * containing the trigonometric functions (which are listed here for angles at
 * 15-degree intervals) should all have seven digits after the decimal point.
 *
 * Solution 2021 Ben Mills
 *
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>

double const PI = 3.14159265;

int main() {
  std::cout << " theta | sin(theta) | cos(theta) |" << std::endl;
  std::cout << "-------+------------+------------+" << std::endl;
  int theta = -90;
  while (theta <= 90) {
    double currentSin = sin(theta * M_PI / 180); // angle must be a radian
    double currentCos = cos(theta * M_PI / 180);
    std::cout << std::right << std::setprecision(7) << std::showpoint
              << std::fixed << std::setw(5) << theta << "  |" << std::setw(11)
              << currentSin << " |" << std::setw(11) << currentCos << " |"
              << std::endl;
    theta += 15;
  }
  return 0;
}
