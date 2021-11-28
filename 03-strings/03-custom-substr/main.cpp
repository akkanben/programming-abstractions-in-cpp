/* Programming Abstractions in C++
 *
 * Exercise 03-03
 *
 * Without using the built-in string method substr, implement a free function
 * substr(str, pos, n) that returns the substring of str beginning at position
 * pos and containing at most n characters. Make sure that your function
 * correctly applies the following rules:
 *
 *   If n is missing or greater than the length of the string, the substring
 * should extend through the end of the original string.
 *
 *   If pos is greater than the length of the string, substr should call error
 *   with an appropriate message.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/error.h"
#include <iostream>
#include <string>

std::string subStr(std::string str, int pos, int n);
std::string subStr(std::string str, int pos);

int main() {
  std::cout << "potato minus po is: " << subStr("potato", 2) << std::endl;
  std::cout << "potato minus pot is: " << subStr("potato", 3) << std::endl;
  std::cout << "potato minus ta is: " << subStr("potato", 0, 2)
            << subStr("potato", 4) << std::endl;
  std::cout << "potato minus out-of-bounds is: " << subStr("potato", 9)
            << std::endl;
  return 0;
}

std::string subStr(std::string str, int pos, int n) {
  if (n > str.length())
    n = str.length();
  if (pos > str.length())
    error("Position not valid.");
  std::string subString = "";
  for (int i = pos; i < n; i++) {
    subString += str[i];
  }
  return subString;
}

std::string subStr(std::string str, int pos) {
  int n = str.length();
  if (pos > str.length())
    error("Position not valid.");

  std::string subString = "";
  for (int i = pos; i < n; i++) {
    subString += str[i];
  }
  return subString;
}
