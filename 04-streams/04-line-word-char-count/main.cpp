/* Programming Abstractions in C++
 *
 * Exercise 04-04
 *
 * Write a program that reads a file and reports how many lines, words, and
 * characters appear in it. For the purposes of this program, a word consists of
 * a consecutive sequence of any characters except whitespace characters. As an
 * example, suppose that the file Lear.txt contains the following passage from
 * Shakespeare’s King Lear,
 *
 * <Lear.txt image>
 * your program should be able to generate the following sample run:
 *
 * <sample run image>
 *
 * The counts in the output should be displayed in a column that is aligned on
 * the right but which expands to fit the data. For example, if you have a file
 * containing the full text of George Eliot’s Middlemarch, the output of your
 * program should look like this:
 *
 * <output of middlemarch run image>
 *
 * Solution 2021 Ben Mills
 *
 * middlemarch.txt from https://www.gutenberg.org/ebooks/145
 *
 */

#include <fstream>
#include <iostream>
#include <string>

std::string promptUserForFile(std::ifstream &infile, std::string prompt = "");

int main() {
  std::ifstream infile;
  promptUserForFile(infile, "Input file: ");
  int lineCount = 0;
  int wordCount = 0;
  int charCount = 0;
  bool lastSpace = false;
  char ch;
  while (infile.get(ch)) {
    if (ch == '\n') {
      charCount++;
      lineCount++;
      wordCount++;
      lastSpace = false;
    } else if (ch == ' ') {
      if (!lastSpace)
        wordCount++;
      charCount++;
      lastSpace = true;
    } else {
      charCount++;
      lastSpace = false;
    }
  }
  std::cout << "Chars: " << charCount << std::endl;
  std::cout << "Words: " << wordCount << std::endl;
  std::cout << "Lines: " << lineCount << std::endl;
  infile.close();
  return 0;
}

std::string promptUserForFile(std::ifstream &infile, std::string prompt) {
  while (true) {
    std::cout << prompt;
    std::string filename;
    getline(std::cin, filename);
    infile.open(filename.c_str());
    if (!infile.fail())
      return filename;
    infile.clear();
    std::cout << "Unable to open that file. Try again." << std::endl;
    if (prompt == "")
      prompt = "Input file: ";
  }
}
