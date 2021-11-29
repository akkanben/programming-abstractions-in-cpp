/* Programming Abstractions in C++
 *
 * Exercise 03-09
 *
 * The waste of time in spelling imaginary sounds and their history
 * (or etymology as it is called) is monstrous in English . . .
 *    —George Bernard Shaw, 1941
 *
 * In the early part of the 20th century, there was considerable interest in
 * both England and the United States in simplifying the rules used for spelling
 * English words, which has always been a difficult proposition. One suggestion
 * advanced as part of this movement was to eliminate all doubled letters, so
 * that bookkeeper would be written as bokeper and committee would become
 * comite. Write a function removeDoubledLetters(str) that returns a new string
 * in which any duplicated characters in str have been replaced by a single
 * copy.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

std::string removeDoubledLetters(std::string str);

int main() {
  std::cout << "Bookkeeper with no double letters would be "
            << removeDoubledLetters("Bookkeeper") << std::endl;
  std::cout << "Committee with no double letters would be "
            << removeDoubledLetters("Committee") << std::endl;
  std::cout << "Sleeplessness with no double letters would be "
            << removeDoubledLetters("Sleeplessness") << std::endl;
  return 0;
}

std::string removeDoubledLetters(std::string str) {
  char lastLetter;
  std::string output = "";
  for (int i = 0; i < str.length(); i++) {
    if (lastLetter != str[i]) {
      output += str[i];
    }
    lastLetter = str[i];
  }
  return output;
}
