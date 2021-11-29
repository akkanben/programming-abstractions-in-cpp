/* Programming Abstractions in C++
 *
 * Exercise 03-08
 *
 * Modify your solution to exercise 7 so that, instead of using a function that
 * returns a new string, you define a function removeCharactersInPlace that
 * removes the letters from the string passed as the first argument.
 *
 * Solution 2021 Ben Mills
 *
 */

#include <iostream>
#include <string>

std::string removeCharactersInPlace(std::string str, std::string remove);
bool containsLetter(char letter, std::string str);

int main() {
  std::cout << "Hello with no \"l\" would be "
            << removeCharactersInPlace("Hello", "l") << std::endl;
  std::cout << "Counterrevolutionaries with no vowels would be "
            << removeCharactersInPlace("Counterrevolutionaries", "aeiou")
            << std::endl;
  std::cout << "Supercalifragilisticexpialidocious with no vowels would be "
            << removeCharactersInPlace("Supercalifragilisticexpialidocious",
                                       "aeiou")
            << std::endl;
}

std::string removeCharactersInPlace(std::string str, std::string remove) {
  for (int i = str.length() - 1; i >= 0; i--)
    if (containsLetter(str[i], remove)) {
      str.erase(i, 1);
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
