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

#include <fstream>
#include <iostream>
#include <string>

std::string promptUserForFile(std::ifstream &infile, std::string prompt = "");

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
