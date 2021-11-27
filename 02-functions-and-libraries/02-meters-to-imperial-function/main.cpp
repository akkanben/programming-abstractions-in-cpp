/* Programming Abstractions in C++
 *
 * Exercise 02-02
 *
 * Reimplement the distance-conversion program from exercise 2 in Chapter 1 so
 * that it uses a function. In this case, the function must produce both the
 * number of feet and the number of inches, which means that you need to use
 * call by reference to return these values.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

const int SENTINEL = 0;

void convert(int meters, int &inches, int &feet);

int main() {
  int meters;
  while (true) {
    std::cout << "Enter a value in meters to convert to feet and inches: ";
    std::cin >> meters;
    if (meters == SENTINEL)
      break;
    int feet;
    int inches;
    convert(meters, inches, feet);
    std::cout << meters << " meters in US measurement would be " << feet
              << " feet and " << inches << " inches." << std::endl;
  }
  return 0;
}

void convert(int meters, int &inches, int &feet) {
  int totalInches = meters / 0.0254;
  inches = totalInches % 12;
  feet = totalInches / 12;
}
