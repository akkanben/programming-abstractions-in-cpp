/* Programming Abstractions in C++
 *
 * Exercise 05-22
 *
 * Section 3.6 defines the function isPalindrome that checks whether a word
 * reads identically forward and backward. Use that function together with the
 * English lexicon to print out a list of all words that are palindromes.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/lexicon.h"

bool isPalindrome(std::string str);
std::string reverse(std::string str);

int main() {
  Lexicon english;
  english.addWordsFromFile("../../extras/dictionary.txt");
  for (string str : english) {
    if (isPalindrome(str)) {
      std::cout << str << std::endl;
    }
  }
  return 0;
}

std::string reverse(std::string str) {
  std::string output = "";
  for (int i = str.length() - 1; i >= 0; i--) {
    output += str[i];
  }
  return output;
}

bool isPalindrome(std::string str) { return str == reverse(str); }
