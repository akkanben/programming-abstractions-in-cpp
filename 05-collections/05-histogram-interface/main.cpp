/* Programming Abstractions in C++
 *
 * Exercise 05.05
 *
 * Extend the flexibility of the previous exercise by defining a hist.h
 * interface that gives clients more control over the format of the histogram.
 * At a minimum, your interface should allow clients to specify the minimum and
 * maximum values along with the size of each histogram range, but you should
 * feel free to provide other capabilities as well. Use your imagination!
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/filelib.h"
#include "../../StanfordCPPLib/include/vector.h"
#include "./histogram.h"
#include <iostream>
#include <string>

void fileSetup(std::ifstream &inFile, Vector<int> &data, std::string &line);

int main() {
  std::ifstream inFile;
  Vector<int> data;
  Vector<int> displayInterval;
  Vector<std::string> displayData;
  std::string line;
  int maxValue;
  int minValue;
  int intervalSize;
  char ch;
  fileSetup(inFile, data, line);
  initializeVectors(data, displayData, displayInterval, ch);
  printHistogram(displayData, displayInterval);
  return 0;
}

void fileSetup(std::ifstream &inFile, Vector<int> &data, std::string &line) {
  promptUserForFile(inFile, "Enter file name for data: ");
  while (getline(inFile, line)) {
    if (line.length() < 1)
      data.add(0);
    data.add(stringToInteger(line));
  }
}
