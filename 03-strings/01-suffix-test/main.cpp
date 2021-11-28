/* Programming Abstractions in C++
 *
 * Exercise 03-01
 *
 * Implement the function endsWith(str, suffix), which returns true if
 * str ends with suffix. Like its startsWith counterpart, the endsWith
 * function should allow the second argument to be either a string or a
 * character.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

std::string const strSuffix = "ed";
char const charSuffix = 'd';

std::string const words[8] = {
    "result",   "deed",    "answer", "included",
    "sleeping", "pattern", "method", "booked",
};

bool endsWith(std::string str, std::string suffix);
bool endsWith(std::string str, char suffix);

int main() {
  int wordsLength = sizeof words / sizeof words[0];
  for (int i = 0; i < wordsLength; i++) {
    std::string strStatus = endsWith(words[i], strSuffix) ? "DOES" : "does NOT";
    std::string charStatus =
        endsWith(words[i], charSuffix) ? "DOES" : "does NOT";
    std::cout << words[i] << " " << strStatus << " end with the string "
              << strSuffix << "." << std::endl;
    std::cout << words[i] << " " << charStatus << " end with the char "
              << charSuffix << "." << std::endl;
    std::cout << "\n";
  }
  return 0;
}

bool endsWith(std::string str, std::string suffix) {
  if (str.substr(str.length() - suffix.length()) == suffix)
    return true;
  return false;
}

bool endsWith(std::string str, char suffix) {
  if (str.at(str.length() - 1) == suffix)
    return true;
  return false;
}
