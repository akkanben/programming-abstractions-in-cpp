/* Programming Abstractions in C++
 *
 * Exercise
 *
 * Some files use tab characters to align data into columns. Doing so, however,
 * can cause problems for applications that are unable to work directly with
 * tabs. For these applications, it is useful to have access to a program that
 * replaces tabs in an input file with the number of spaces required to reach
 * the next tab stop. In programming, tab stops are usually set at every eight
 * columns. For example, suppose that the input file contains a line of the form
 *
 *  <image of tab sizes>
 *
 * where the ----| symbol represents the space taken up by a tab, which differs
 * depending on its position in the line. If the tab stops are set every eight
 * spaces, the first tab character must be replaced by five spaces and the
 * second tab character by three.
 *
 * Write a program that copies an input file to an output file, replacing all
 * tab characters by the appropriate number of spaces.
 *
 * Solution 2021 Ben Mills
 */

#include <fstream>
#include <iostream>
#include <string>

std::string promptUserForFile(std::ifstream &inFile, std::string prompt);
std::string promptUserForFile(std::ofstream &outFile, std::string prompt);
void replaceTabs(std::ifstream &inFile, std::ofstream &outFile, int numTab = 4);

int main() {
  std::ifstream inFile;
  std::ofstream outFile;
  promptUserForFile(inFile, "Input file: ");
  promptUserForFile(outFile, "Output file: ");
  replaceTabs(inFile, outFile);
  inFile.close();
  outFile.close();

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

std::string promptUserForFile(std::ofstream &outFile, std::string prompt) {
  while (true) {
    std::cout << prompt;
    std::string fileName;
    getline(std::cin, fileName);
    outFile.open(fileName.c_str());
    if (!outFile.fail())
      return fileName;
    outFile.clear();
    std::cout << "Unable to open or create that file. Try again." << std::endl;
    if (prompt == "")
      prompt = "Output file: ";
  }
}

void replaceTabs(std::ifstream &inFile, std::ofstream &outFile, int numTab) {
  char ch;
  int spaceCounter = 0;
  int sizeToTab = 0;
  while (inFile.get(ch)) {
    if (ch == '\n')
      spaceCounter = -1;
    if (spaceCounter < 0) {
      sizeToTab = numTab;
    } else {
      sizeToTab = numTab - (spaceCounter % numTab);
    }
    if (ch == '\t') {
      for (int i = 0; i < sizeToTab; i++) {
        outFile.put(' ');
        std::cout << ' ';
      }
      spaceCounter += sizeToTab;
    } else {
      outFile.put(ch);
      std::cout << ch;
      spaceCounter++;
    }
  }
}
