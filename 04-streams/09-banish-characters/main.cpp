/* Programming Abstractions in C++
 *
 * Exercise
 *
 * QUESTION
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/simpio.h"
#include <fstream>
#include <iostream>
#include <string>

std::string promptuserforfile(std::ifstream &infile, std::string prompt);
std::string promptuserforfile(std::ofstream &outfile, std::string prompt);
void banishcharacters(std::ifstream &infile, std::ofstream &outfile,
                      std::string tobanish);

int main() {
  std::ifstream infile;
  std::ofstream outfile;
  promptuserforfile(infile, "Input file: ");
  promptuserforfile(outfile, "Output file: ");
  std::string tobanish = getLine("Enter letters to remove: ");
  std::cout << std::endl;
  banishcharacters(infile, outfile, tobanish);
  infile.close();
  outfile.close();
  return 0;
}

std::string promptuserforfile(std::ifstream &infile, std::string prompt) {
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

std::string promptuserforfile(std::ofstream &outfile, std::string prompt) {
  while (true) {
    std::cout << prompt;
    std::string filename;
    getline(std::cin, filename);
    outfile.open(filename.c_str());
    if (!outfile.fail())
      return filename;
    outfile.clear();
    std::cout << "Unable to open that file. Try again." << std::endl;
    if (prompt == "")
      prompt = "Output file: ";
  }
}

void banishcharacters(std::ifstream &infile, std::ofstream &outfile,
                      std::string tobanish) {
  char ch;
  while (infile.get(ch)) {
    bool toput = true;
    for (int i = 0; i < tobanish.length(); i++) {
      if (tobanish.at(i) == ch) {
        toput = false;
      }
    }
    if (toput) {
      std::cout.put(ch);
      outfile.put(ch);
    }
  }
}
