/* Programming Abstractions in C++
 *
 * Exercise 03-04
 *
 * Implement a function capitalize(str) that returns a string in which the
 * initial character is capitalized (if it is a letter) and all other letters
 * are converted to lowercase. Characters other than letters are not affected.
 * For example, both capitalize("BOOLEAN") and capitalize("boolean") should
 * return the string "Boolean".
 *
 * Solution 2021 Ben Mills
 *
 * This function relies on capital and lowercase letters being 32 positions
 * apart. In C++ we could just do char arithmetic a bit more directly but for
 * JavaScript I used:
 *
 * String.fromCodePoint() and codePointAt();
 *
 */

#include <cctype>
#include <iostream>

std::string capitalize(std::string str);

int main() {
  std::cout << "BOOLEAN with propper capitalization would be: "
            << capitalize("BOOLEAN") << std::endl;
  std::cout << "boolean with propper capitalization would be: "
            << capitalize("boolean") << std::endl;
  std::cout << "b00l3an with propper capitalization would be: "
            << capitalize("B00l3an") << std::endl;
}

std::string capitalize(std::string str) {
  std::string output;
  for (int i = 0; i < str.length(); i++) {
    if (i == 0 && std::isalpha(str[0])) {
      output += toupper(str[0]);
    } else {
      output += tolower(str[i]);
    }
  }
  return output;
}
