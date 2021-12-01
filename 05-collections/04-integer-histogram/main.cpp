/* Programming Abstractions in C++
 *
 * Exercise
 *
 * A histogram is a graphical way of displaying data by dividing the data into
 * separate ranges and then indicating how many data values fall into each
 * range. For example, given the set of exam scores
 *
 * 100, 95, 47, 88, 86, 92, 75, 89, 81, 70, 55, 80
 *
 * a traditional histogram would have the following form:
 *
 *  <image of horizontal histogram>
 *
 * The asterisks in the histogram indicate one score in the 40s, one score in
 * the 50s, five scores in the 80s, and so forth.
 *
 * When you generate histograms using a computer, however, it is much
 * easier to display them sideways on the page, as in this sample run:
 *
 *  <image of sample run>
 *
 * Write a program that reads in a vector of integers from a data file and then
 * displays a histogram of those numbers, divided into the ranges 0–9, 10–19,
 * 20–29, and so forth, up to the range containing only the value 100. Your
 * program should generate output that looks as much like the sample run as
 * possible.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/filelib.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "../../StanfordCPPLib/include/vector.h"
#include <iostream>
#include <string>

int const DECADE_NUM = 11;

void printHistogram(Vector<int> &data);
void initializeAsterisk(Vector<int> &data, Vector<std::string> &asterisk);
void initializeDecades(Vector<std::string> &decades);

int main() {
  std::ifstream inFile;
  Vector<int> data;
  std::string line;
  promptUserForFile(inFile, "Enter file name: ");
  while (getline(inFile, line)) {
    if (line.length() < 1)
      data.add(0);
    data.add(stringToReal(line));
  }
  printHistogram(data);
  inFile.close();
  return 0;
}

void printHistogram(Vector<int> &data) {
  Vector<std::string> asterisk(data.size());
  Vector<std::string> decades;
  initializeDecades(decades);
  // initialize asterisk
  for (int i = 0; i < data.size(); i++) {
    asterisk[data[i] / 10] += "*";
  }
  // actual printing
  for (int i = 0; i < decades.size(); i++) {
    std::cout << decades[i] << ": " << asterisk[i] << std::endl;
  }
}

void initializeDecades(Vector<std::string> &decades) {
  for (int i = 0; i <= 10; i++) {
    if (i > 9) {
      decades.add(integerToString(i) + "0");
    } else {
      decades.add(integerToString(i) + "0s");
    }
  }
}
