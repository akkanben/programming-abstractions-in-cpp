/* Programming Abstractions in C++
 *
 * Exercise 06-10
 *
 * Write a program that checks the spelling of all words in a file. Your program
 * should use the TokenScanner class to reads tokens from an input file and
 * then look up each word in the lexicon stored in the file EnglishWords.dat
 * introduced in Chapter 5. If the word does not appear in the lexicon, your
 * program should print a message to that effect. If, for example, you run the
 * program on a file containing the text of this paragraph, the SpellCheck
 * program would produce the following output:
 *
 *  <image of sample run>
 *
 * Solution 2021 Ben Mills
 */

#include <fstream>
#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/lexicon.h"
#include "../../StanfordCPPLib/include/tokenscanner.h"

const std::string FILETOCHECK = "test.txt";
const std::string DICTIONARY = "../../extras/dictionary.txt";

int main() {
  Lexicon dict(DICTIONARY);
  ifstream infile;
  infile.open(FILETOCHECK.c_str());
  if (infile.fail()) {
    error("Can't read file.");
    return 1;
  } else {
    TokenScanner scanner(infile);
    scanner.ignoreWhitespace();
    cout << "Input file: " << FILETOCHECK << endl;
    while (scanner.hasMoreTokens()) {
      string token = scanner.nextToken();
      if (!dict.contains(token) && token.length() > 1) {
        cout << "\"" << token << "\""
             << " is not in the dictionary.  " << endl;
      }
    }
  }
  return 0;
}
