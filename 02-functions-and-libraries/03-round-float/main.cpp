/* Programming Abstractions in C++
 *
 * Exercise 02-03
 *
 * When a floating-point number is converted to an integer in C++, the value is
 * truncated by throwing away any fraction. Thus, when 4.99999 is converted to
 * an integer, the result is 4. In many cases, it would be useful to have the
 * option of rounding a floating-point value to the nearest integer. Given a
 * positive floating-point number x, you can round it to the closest integer by
 * adding 0.5 and then truncating the result to an integer. Because truncation
 * always moves toward zero, rounding negative numbers requires you to subtract
 * 0.5, rather than adding it.
 *
 * Write a function roundToNearestInt(x) that rounds the floating-point
 * number x to the nearest integer. Show that your function works by writing a
 * suitable main program to test it.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

int const SENTINEL = 0;

int roundToNearestInt(float floatingValue);

int main() {
  float input;
  while (true) {
    std::cout << "Enter a floating point number to round: ";
    std::cin >> input;
    if (input == SENTINEL)
      break;
    std::cout << input << " rounded becomes " << roundToNearestInt(input)
              << std::endl;
  }
  return 0;
}

int roundToNearestInt(float floatingValue) {
  int roundedNumber = 0;
  if (floatingValue > 0) {
    floatingValue += 0.5;
  } else {
    floatingValue -= 0.5;
  }
  return roundedNumber = floatingValue; // float to int truncation is here
}
