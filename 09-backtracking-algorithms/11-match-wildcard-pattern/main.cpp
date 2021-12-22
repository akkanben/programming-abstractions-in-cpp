/* Programming Abstractions in C++
 *
 * Exercise 09-11
 *
 * Most operating systems and many applications that allow users to work with
 * files support wildcard patterns, in which special characters are used to
 * create filename patterns that can match many different files. The most common
 * special characters used in wildcard matching are ?, which matches any single
 * character, and *, which matches any sequence of characters. Other characters
 * in a filename pattern must match the corresponding character in a filename.
 * For example, the pattern *.* matches any filename that contains a period,
 * such as EnglishWords.dat or HelloWorld.cpp, but would not match
 * filenames that do not contain a period. Similarly, the pattern test.? matches
 * any filename that consists of the name test, a period, and a single
 * character; thus, test.? matches test.h but not test.cpp. These patterns can
 * be combined in any way you like. For example, the pattern ??* matches any
 * filename containing at least two characters.
 *
 * Write a function
 *
 *  bool wildcardMatch(string filename, string pattern);
 *
 * that takes two strings, representing a filename and a wildcard pattern, and
 * returns true if that filename matches the pattern. Thus,
 *
 *  wildcardMatch("US.txt", "*.*")       returns true
 *  wildcardMatch("test", "*.*")         returns false
 *  wildcardMatch("test.h", "test.?")    returns true
 *  wildcardMatch("test.cpp", "test.?")  returns false
 *  wildcardMatch("x", "??*")            returns false
 *  wildcardMatch("yy", "??*")           returns true
 *  wildcardMatch("zzz", "??*")          returns true
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/strlib.h"
#include "../../StanfordCPPLib/include/vector.h"

bool wildcardMatch(string fileName, string pattern);
bool match(string fileName, string pattern, int position);

int main() {
  std::string a = wildcardMatch("abc", "abc") ? "true" : "false";
  std::string b = wildcardMatch("US.txt", "*.*") ? "true" : "false";
  std::string c = wildcardMatch("test", "*.*") ? "true" : "false";
  std::string d = wildcardMatch("test.h", "test.?") ? "true" : "false";
  std::string e = wildcardMatch("test.cpp", "test.?") ? "true" : "false";
  std::string f = wildcardMatch("x", "??*") ? "true" : "false";
  std::string g = wildcardMatch("yy", "??*") ? "true" : "false";
  std::string h = wildcardMatch("zzz", "??*") ? "true" : "false";

  std::cout << "wildcardMatch(\"abc\", \"abc\")         "
            << "returns " << a << std::endl;
  std::cout << "wildcardMatch(\"US.txt\", \"*.*\")      "
            << "returns " << b << std::endl;
  std::cout << "wildcardMatch(\"test\", \"*.*\")        "
            << "returns " << c << std::endl;
  std::cout << "wildcardMatch(\"test.h\", \"test.?\")   "
            << "returns " << d << std::endl;
  std::cout << "wildcardMatch(\"test.cpp\", \"test.?\") "
            << "returns " << e << std::endl;
  std::cout << "wildcardMatch(\"x\", \"??*\")           "
            << "returns " << f << std::endl;
  std::cout << "wildcardMatch(\"yy\", \"??*\")          "
            << "returns " << g << std::endl;
  std::cout << "wildcardMatch(\"zzz\", \"??*\")         "
            << "returns " << h << std::endl;
  return 0;
}

bool wildcardMatch(string fileName, string pattern) {
  int position = 0;
  return match(fileName, pattern, position);
}

bool match(string fileName, string pattern, int position) {
  if (position == fileName.length()) {
    if (pattern.length() > fileName.length()) {
      return false;
    } else {
      return true;
    }
  }
  for (int i = 0; i < (fileName.length() - position); i++) {
    if (fileName[i + position] == pattern[0]) {
      string SubPattern = pattern.substr(1);
      if (match(fileName, SubPattern, position + 1)) {
        return true;
      }
    }
    if (pattern[0] == '*') {
      if (pattern.length() > 1) {
        string SubPattern = pattern.substr(1);
        if (match(fileName, SubPattern, position + 1)) {
          return true;
        }
      } else {
        return true;
      }
    }
    if (pattern[0] == '?') {
      string SubPattern = pattern.substr(1);
      if (match(fileName, SubPattern, position + 1)) {
        return true;
      }
    }
  }
  return false;
}
