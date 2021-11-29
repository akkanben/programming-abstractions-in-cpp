/* Programming Abstractions in C++
 *
 * Exercise 03-07
 *
 * Write a function string removeCharacters(string str, string remove)
 * that returns a new string consisting of the characters in str after removing
 all
 * instances of the characters in remove. For example, if you call
 *
 * removeCharacters("counterrevolutionaries", "aeiou")
 *
 * the function should return "cntrrvltnrs", which is the original string after
 * removing all of its vowels.

 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

std::string removeCharacters(std::string str, std::string remove);
bool containsLetter(char letter, std::string str);

int main() {
  std::cout << "Hello with no \"l\" would be " << removeCharacters("Hello", "l")
            << std::endl;
  std::cout << "Counterrevolutionaries with no vowels would be "
            << removeCharacters("Counterrevolutionaries", "aeiou") << std::endl;
}

std::string removeCharacters(std::string str, std::string remove) {
  std::string output;
  for (int i = 0; i < str.length(); i++) {
    if (!containsLetter(str[i], remove)) {
      output += str[i];
    }
  }
  return output;
}

bool containsLetter(char letter, std::string str) {
  for (int i = 0; i < str.length(); i++) {
    if (letter == str[i])
      return true;
  }
  return false;
}
