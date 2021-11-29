/* Programming Abstractions in C++
 *
 * Exercise 03-12
 *
 * Write a function createRegularPlural(word) that returns the plural of
 * word formed by following these standard English rules:
 *
 * a. If the word ends in s, x, z, ch, or sh, add es to the word.
 * b. If the word ends in a y preceded by a consonant, change the y to ies.
 * c. In all other cases, add just an s.
 *
 * Write a test program and design a set of test cases to verify that your
 * program works.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

std::string createRegularPlural(std::string str);
bool containsLetter(char letter, std::string str);

int main() {
  std::string list[6] = {"box", "glass", "Pez", "push", "candy", "potato"};
  int listLength = sizeof list / sizeof list[0];
  for (int i = 0; i < listLength; i++) {

    std::cout << "\"" << list[i] << "\""
              << " pluralized is " << createRegularPlural(list[i]) << std::endl;
  }
  return 0;
}

std::string createRegularPlural(std::string str) {
  std::string output = "";
  std::string vowels = "aeiou";
  char lastLetter = str.substr(str.length() - 1).at(0);
  std::string lastTwoLetters = str.substr(str.length() - 2);
  if (lastLetter == 's' || lastLetter == 'x' || lastLetter == 'z' ||
      lastTwoLetters == "ch" || lastTwoLetters == "sh" ||
      lastTwoLetters == "es") {
    return str + "es";
  } else if (lastLetter == 'y' &&
             !containsLetter(lastTwoLetters.at(0), vowels)) {
    return str.substr(0, str.length() - 1) + "ies";
  } else {
    return str + 's';
  }
  return str;
}

bool containsLetter(char letter, std::string str) {
  for (int i = 0; i < str.length(); i++) {
    if (letter == str[i])
      return true;
  }
  return false;
}
