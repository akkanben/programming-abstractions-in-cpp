/* Programming Abstractions in C++ (in JavaScript)
 *
 * Exercise 01.02
 *
 * Write a program that converts a distance in meters to the corresponding
 * English distance in feet and inches. The conversion factors you need are 1
 * inch = 0.0254 meters 1 foot = 12 inches
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

int main() {
  double value;
  std::cout << "Enter a value in meters to convert to inches: ";
  std::cin >> value;
  int TotalInches;
  int feet;
  int inches;
  TotalInches = value / 0.0254;
  feet = TotalInches / 12;
  inches = TotalInches % 12;
  std::cout << value << " meters in US measurement would be " << feet
            << " feet and " << inches << " inches." << std::endl;
  return 0;
}
