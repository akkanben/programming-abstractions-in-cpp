/* Programming Abstractions in C++
 *
 * Exercise 05-25
 *
 * Write a program that prints out a table showing the number of words that
 * appear in the English lexicon, sorted by the length of the word. For the
 * lexicon in EnglishWords.dat, the output of this program looks like this:
 *
 *  <image of sample run>
 *
 * Solution 2021 Ben Mills
 */

#include <iomanip>
#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/lexicon.h"
#include "../../StanfordCPPLib/include/vector.h"

int main() {
  Lexicon english;
  english.addWordsFromFile("../../extras/dictionary.txt");
  Vector<int> words(18);
  for (std::string str : english) {
    words.set(str.length(), (words.get(str.length())) + 1);
  }
  for (int i = 0; i < words.size(); i++) {
    std::cout << left << setw(10) << i << right << words.get(i) << std::endl;
  }
  return 0;
}
