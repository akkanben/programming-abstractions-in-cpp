/* Programming Abstractions in C++
 *
 * Exercise 03-11
 *
 * The concept of a palindrome is often extended to full sentences by ignoring
 * punctuation and differences in the case of letters. For example, the sentence
 *
 * Madam, I’m Adam.
 *
 * is a sentence palindrome, because if you only look at the letters and ignore
 * any distinction between uppercase and lowercase letters, it reads identically
 * backward and forward.
 *
 * Write a predicate function isSentencePalindrome(str) that returns
 * true if the string str fits this definition of a sentence palindrome. For
 * example, you should be able to use your function to write a main program
 * capable of producing the following sample run:
 *
 * <image of example with 3 sentences>
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/simpio.h"
#include <cctype>
#include <iostream>
#include <string>

bool isSentencePalindrome(std::string str);
std::string toOnlyLowerAlpha(std::string str);
std::string reverse(std::string str);

int main() {
  std::cout << "This program tests for sentance palindromes." << std::endl;
  std::cout << "Indicate the end of the input with a blank line.\n"
            << std::endl;
  std::string line = " ";
  while (line != "") {
    std::cout << "Enter a sentance: ";
    line = getLine();
    if (line == "")
      break;
    if (isSentencePalindrome(line)) {
      std::cout << "That sentance IS a palindrome." << std::endl << std::endl;
    } else {
      std::cout << "That sentance is NOT a palindrom." << std::endl
                << std::endl;
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

std::string toOnlyLowerAlpha(std::string str) {
  std::string output = "";
  for (int i = 0; i < str.length(); i++) {
    if (std::isalpha(str[i])) {
      output += tolower(str[i]);
    }
  }
  return output;
}

bool isSentencePalindrome(std::string str) {
  std::string cleanStr = toOnlyLowerAlpha(str);
  return cleanStr == reverse(cleanStr);
}
