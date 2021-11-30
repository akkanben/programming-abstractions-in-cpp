/* Programming Abstractions in C++
 *
 * Exercise 04-08
 *
 * Even though comments are essential for human readers, the compiler simply
 * ignores them. If you are writing a compiler, you therefore need to be able to
 * recognize and eliminate comments that occur in a source file.
 * Write a function
 *
 * void removeComments(istream & is, ostream & os);
 *
 * that copies characters from the input stream is to the output stream os,
 * except for characters that appear inside C++ comments. Your implementation
 * should recognize both comment conventions:
 *
 * - Any text beginning with "slash star" and ending with "star slash", possibly
 * many lines later.
 *
 * - Any text beginning with "slash slash" and extending through
 *
 * the end of the line. The real C++ compiler needs to check to make sure that
 * these characters are not contained inside quoted strings, but you should feel
 * free to ignore that detail. The problem is tricky enough as it stands.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/random.h"
#include <fstream>
#include <iostream>
#include <string>

std::string promptUserForFile(std::ifstream &inFile, std::string prompt = "");
void removeComments(std::istream &is, std::ostream &os);

int main() {
  std::ifstream inFile;
  promptUserForFile(inFile, "Input file: ");
  removeComments(inFile, std::cout);
  inFile.close();
  return 0;
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

/*
 * Function: removeComments
 * Usage: removeComments(inFile, std::cout);
 * ------------------
 * Does not directly modify the "inFile" but sends the
 * modified stream to the screen. The erase method is
 * used to delete the comments and the find method is
 * used to locate the comment start/end.
 */

void removeComments(std::istream &is, std::ostream &os) {
  std::string line;
  while (getline(is, line)) {
    if (line.find("//") != std::string::npos) {
      line.erase(line.find("//"));
      os << line << std::endl;
    } else if (line.find("/*") == std::string::npos &&
               line.find("*/") == std::string::npos) {
      os << line << std::endl;
    } else if (line.find("/*") != std::string::npos &&
               line.find("*/") != std::string::npos) {
      line.erase(line.find("/*"));
      os << line << std::endl;
    } else if (line.find("/*") != std::string::npos) {
      line.erase(line.find("/*"));
      os << line;
      getline(is, line);
      while (line.find("*/") == std::string::npos) {
        getline(is, line);
      }
      if (line.find("*/") > 1) {
        line.erase(0, line.length() - line.find("*/") - 2);
      } else {
        line.erase(line.find("*/"));
      }
      os << line;
    } else {
      os << line << std::endl;
    }
  }
}
