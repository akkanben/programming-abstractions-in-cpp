/* Programming Abstractions in C++
 *
 * Exercise 11-08
 *
 * Even though it is illegal to copy stream objects in C++, you can store a
 * pointer to a stream in a data structure. This technique, for example, makes
 * it possible to implement the method
 *
 *  void setInput(istream & infile)
 *
 * from the TokenScanner class introduced in section 6.4. All you need to do is
 * store the address of infile in a pointer variable and then dereference the
 * pointer to read from the stream.
 *
 * Extend the simplified TokenScanner class presented in Figures 6-10 and
 * 6-11 so that it can read tokens from input streams as well as strings.
 *
 * Solution 2021 Ben Mills
 *
 * For a test I'm using exercise 06-10 spellcheck running on the updated simple
 * tokenscanner (instead of the StanfordCPPLib one).
 */

#include <fstream>
#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/lexicon.h"
#include "tokenscanner.h"

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
  infile.close();
  return 0;
}
