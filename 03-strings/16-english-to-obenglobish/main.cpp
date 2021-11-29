/* Programming Abstractions in C++
 *
 * Exercise 03-16
 *
 * Most people—at least those in English-speaking countries—have played the
 * Pig Latin game at some point in their lives. There are, however, other
 * invented “languages” in which words are created using some simple
 * transformation of English. One such language is called Obenglobish, in which
 * words are created by adding the letters ob before the vowels (a, e, i, o, and
 * u) in an English word. For example, under this rule, the word english gets
 * the letters ob added before the e and the i to form obenglobish, which is how
 * the language gets its name.
 *
 * In official Obenglobish, the o b characters are added only before vowels
 * that are pronounced, which means that a word like game would become
 * gobame rather than gobamobe because the final e is silent. While it is
 * impossible to implement this rule perfectly, you can do a pretty good job by
 * adopting the rule that the ob should be added before every vowel in the
 * English word except
 *
 * • Vowels that follow other vowels
 * • An e that occurs at the end of the word
 *
 * Write a function obenglobish that takes an English word and returns its
 * Obenglobish equivalent, using the translation rule given above. For example,
 * if you used your function with the main program
 *
 *  int main() {
 *    while (true) {
 *      string word = getLine("Enter a word: ");
 *      if (word == "") break;
 *      string trans = obenglobish(word);
 *      cout << word << " -> " << trans << endl;
 *    }
 *    return 0;
 *  }
 *
 * you should be able to generate the following sample run:
 *
 * <image of sample run>
 *
 * Solution 2021 Ben Mills
 *
 */

#include "../../StanfordCPPLib/include/simpio.h"
#include <cctype>
#include <iostream>
#include <string>

std::string obenglobish(std::string word);
bool isVowel(char ch);

int main() {
  while (true) {
    std::string word = getLine("Enter a word: ");
    if (word == "")
      break;
    std::string trans = obenglobish(word);
    std::cout << word << " -> " << trans << std::endl;
  }
  return 0;
}

std::string obenglobish(std::string word) {
  std::string output;
  bool doubleVowel = false;
  for (int i = 0; i < word.length(); i++) {
    if (i == word.length() - 1 && word[i] == 'e')
      return output + word[i];
    if (isVowel(word[i]) && !doubleVowel) {
      output += "ob" + word.substr(i, 1);
      doubleVowel = true;
    } else if (isVowel(word[i]) && doubleVowel) {
      output += word[i];
    } else {
      output += word[i];
      doubleVowel = false;
    }
  }
  return output;
}

bool isVowel(char ch) {
  switch (tolower(ch)) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return true;
  default:
    return false;
  }
}
