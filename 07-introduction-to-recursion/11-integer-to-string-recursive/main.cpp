/* Programming Abstractions in C++
 *
 * Exercise
 *
 * The strlib.h library contains a function integerToString. Reimplement
 * this function without using streams by exploiting the recursive decomposition
 * of an integer outlined in exercise 7.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

std::string integerToString(int n);

int main() {
  for (int i = 123; i < 1000; i += 111) {
    std::string number = integerToString(i);
    std::cout << number << std::endl;
  }
  return 0;
}

std::string integerToString(int n) {
  std::string output = "";
  if (n < 10) {
    char cNum = n + '0';
    output += cNum;
  } else
    output = integerToString(n / 10) + integerToString(n % 10);
  return output;
}
