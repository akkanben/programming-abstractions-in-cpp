/* Programming Abstractions in C++
 *
 * Exercise 04-03
 *
 * Write a program that prints the longest line in a file chosen by the user. If
 * several lines are all equally long, your program should print the first such
 * line.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/filelib.h"
#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream infile;
  promptUserForFile(infile, "Input file: ");
  std::string line;
  std::string longestLine;
  while (getline(infile, line)) {
    if (line.length() > longestLine.length()) {
      longestLine = line;
    }
  }
  std::cout << "The longest line is: " << longestLine << std::endl;
  infile.close();
  return 0;
}
