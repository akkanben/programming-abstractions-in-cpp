/* Programming Abstractions in C++
 *
 * Exercise 05-24
 *
 * One of the most important strategic principles in Scrabble is to conserve
 * your S tiles, because the rules for English plurals mean that many words take
 * an S-hook at the end. Some words, of course, allow an S tile to be added at
 * the beginning, but it turns out that there are 680 words—including, for
 * example, both the words cold and hot—that allow S-hooks on either end. Write
 * a program that uses the English lexicon to make a list of all such words.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/lexicon.h"

int main() {
  Lexicon english;
  english.addWordsFromFile("../../extras/dictionary.txt");
  int total = 0;
  int totalWords = english.size();
  for (std::string str : english) {
    std::string prefix = "s" + str;
    std::string suffix = str + "s";
    if (english.contains(prefix) && english.contains(suffix)) {
      std::cout << str << " :: " << prefix << " & " << suffix << std::endl;
      total++;
    }
  }
  std::cout << std::endl
            << "The total number of words: " << totalWords << std::endl;
  std::cout << "The total S words: " << total << std::endl;
  return 0;
}
