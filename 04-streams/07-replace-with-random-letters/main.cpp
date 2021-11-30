/* Programming Abstractions in C++
 *
 * Exercise 04-07
 *
 * On occasion, publishers find it useful to evaluate layouts and stylistic
 * designs without being distracted by the actual words. To do so, they
 * sometimes typeset sample pages in such a way that all of the original letters
 * are replaced with random letters. The resulting text has the spacing and
 * punctuation structure of the original, but no longer conveys any meaning that
 * might get in the way of the design. The publishing term for text that has
 * been replaced in this way is greek, presumably after the old saying “It’s all
 * Greek to me,” which is itself adapted from a line from Julius Caesar.
 *
 * Write a program that reads characters from an input file and displays them
 * on the console after making the appropriate random substitutions. Your
 * program should replace every uppercase character in the input by a random
 * uppercase character and every lowercase character by a random lowercase
 * one. Nonalphabetic characters should remain unchanged. For example, if the
 * input file Troilus.txt contains the text from Troilus and Cressida,
 *
 *  <image of Troilus.txt snippet>
 *
 * your program should generate output that looks something like this:
 *
 *  <image of example run>
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/random.h"
#include <fstream>
#include <iostream>
#include <string>

std::string promptUserForFile(std::ifstream &inFile, std::string prompt = "");
std::string itsAllGreek(std::ifstream &inFile);

int main() {
  std::ifstream inFile;
  promptUserForFile(inFile, "Input file: ");
  std::cout << itsAllGreek(inFile) << std::endl;
  inFile.close();
  return 0;
}

std::string itsAllGreek(std::ifstream &inFile) {
  std::string greek;
  char ch;
  while (inFile.get(ch)) {
    if (isupper(ch)) {
      int rand = randomInteger('A', 'Z');
      greek += rand;
    } else if (islower(ch)) {
      int rand = randomInteger('a', 'z');
      greek += rand;
    } else
      greek += ch;
  }
  return greek;
}

std::string promptUserForFile(std::ifstream &inFile, std::string prompt) {
  while (true) {
    std::cout << prompt;
    std::string fileName;
    getline(std::cin, fileName);
    inFile.open(fileName.c_str());
    if (!inFile.fail())
      return fileName;
    inFile.clear();
    std::cout << "Unable to open that file. Try again." << std::endl;
    if (prompt == "")
      prompt = "Input file: ";
  }
}
