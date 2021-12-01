/* Programming Abstractions in C++
 *
 * Exercise 04-12
 *
 * Complete the implementation of the simpio.h interface by implementing the
 * functions getReal and getLine.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <sstream>
#include <string>

double getReal(std::string prompt = "");
std::string getLine(std::string prompt = "");

int main() {
  double d = getReal("Enter a real number: ");
  std::string s = getLine("Enter a line of text: ");
  std::cout << "You entered " << d << " and " << s << std::endl;
  return 0;
}

double getReal(std::string prompt) {
  double value;
  std::string line;
  while (true) {
    std::cout << prompt;
    getline(std::cin, line);
    std::istringstream stream(line);
    stream >> value >> std::ws;
    if (!stream.fail() && stream.eof())
      break;
    std::cout << "Illegal double format. Try again." << std::endl;
  }
  return value;
}

std::string getLine(std::string prompt) {
  std::string line;
  char ch;
  std::cout << prompt;
  while (ch != '\n') {
    std::cin >> std::noskipws >> ch;
    line += ch;
  }
  return line;
}
