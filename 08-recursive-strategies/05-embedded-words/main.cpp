/* Programming Abstractions in C++
 *
 * Exercise 08-05
 *
 * Write a program EmbeddedWords that finds all English words that can be
 * formed by taking some subset of letters in order from a given starting word.
 * For example, given the starting word happy, you can certainly produce the
 * words a, ha, hap, and happy, in which the letters appear consecutively. You
 * can also produce the words hay and ay, because those letters appear in happy
 * in the correct left-to-right order. You cannot, however, produce the words pa
 * or pap because the letters—even though they appear in the word—don’t
 * appear in the correct order. A sample run of the program might look like
 * this:
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/lexicon.h"
#include "../../StanfordCPPLib/include/set.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/vector.h"

Vector<std::string> getOrderedCombinations(std::string str);
Set<std::string> findWords(Vector<std::string> words, Lexicon &dictionary);
void printWords(Set<std::string> words);

int main() {
  Lexicon english;
  english.addWordsFromFile("../../extras/dictionary.txt");
  std::string line = " ";
  while (line != "") {
    std::cout << "Enter starting word: ";
    line = getLine();
    if (line == "")
      break;
    Vector<std::string> possibleWords = getOrderedCombinations(line);
    Set<std::string> actualWords = findWords(possibleWords, english);
    printWords(actualWords);
  }
  return 0;
}

Vector<std::string> getOrderedCombinations(std::string str) {
  Vector<std::string> output;
  if (str == "")
    output += str;
  else {
    for (int i = 0; i < str.length(); i++) {
      char ch = str[i];
      std::string rest = str.substr(i + 1);
      foreach (std::string s in getOrderedCombinations(rest)) {
        output += ch + s;
      }
    }
  }
  return output;
}

Set<std::string> findWords(Vector<std::string> words, Lexicon &dictionary) {
  Set<std::string> output;
  for (std::string element : words) {
    if (dictionary.contains(element))
      output.add(element);
  }
  return output;
}

void printWords(Set<std::string> words) {
  for (std::string element : words) {
    std::cout << element << std::endl;
  }
}
