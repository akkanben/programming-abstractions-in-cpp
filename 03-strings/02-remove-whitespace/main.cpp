/* Programming Abstractions in C++
 *
 * Exercise 03-02
 *
 * The strlib.h function exports a function trim(str) that returns a new
 * string formed by removing all whitespace characters from the beginning and
 * end of str. Write the corresponding implementation.
 *
 * Solution 2021 Ben Mills
 */

#include <cctype>
#include <iostream>
#include <string>

std::string const phrases[6] = {
    "results will come.           ", "    deeds are done.          ",
    "answers are needed.          ", "    no batteries are included",
    "sleeping in                  ", "         patterns on the wall",
};

std::string trim(std::string str);

int main() {
  int phrasesLength = sizeof phrases / sizeof phrases[0];
  for (int i = 0; i < phrasesLength; i++) {
    std::cout << trim(phrases[i]) << std::endl;
  }
  return 0;
}

std::string trim(std::string str) {
  for (int i = 0; i < str.length(); i++) {
    if (!std::isspace(str[i])) {
      str = str.substr(i);
      break;
    }
  }
  for (int i = str.length() - 1; i >= 0; i--) {
    if (!std::isspace(str[i])) {
      str = str.substr(0, i + 1);
      break;
    }
  }
  return str;
}
