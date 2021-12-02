/* Programming Abstractions in C++
 *
 * Exercise 05-23
 *
 * In Scrabble, knowing the two-letter word list is important because those
 * short words make it easy to “hook” a new word into tiles already on the
 * board. Another list that Scrabble experts memorize is the list of
 * three-letter words that can be formed by adding a letter to the front or back
 * of a two-letter word. Write a program that generates this list.
 *
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/lexicon.h"
#include <iostream>

int main() {
  Lexicon english;
  english.addWordsFromFile("../../extras/dictionary.txt");
  for (std::string str : english) {
    if (str.length() == 2) {
      char alphabet = 'a';
      while (alphabet <= 'z') {
        std::string a = alphabet + str;
        std::string b = str + alphabet;
        if (english.contains(a)) {
          std::cout << str << " + " << alphabet << " ---> " << a << std::endl;
        } else if (english.contains(b)) {
          std::cout << str << " + " << alphabet << " ---> " << b << std::endl;
        }
        alphabet++;
      }
    }
  }
  return 0;
}
