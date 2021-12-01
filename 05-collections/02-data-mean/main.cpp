/* Programming Abstractions in C++
 *
 * Exercise 05-02
 *
 * In statistics, a collection of data values is often referred to as a
 * distribution. One of the primary goals of statistical analysis is to find
 * ways to compress the complete set of data into summary statistics that
 * express properties of the distribution as a whole. The most common
 * statistical measure is the mean, which is simply the traditional average. For
 * the distribution x1 , x2, x3, . . . , xn, the mean is usually represented by
 * the symbol (x with macron) . Write a function
 *
 *  double mean(Vector<double> & data);
 *
 * that returns the mean of the data
 * in the vector.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/filelib.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "../../StanfordCPPLib/include/vector.h"
#include <iostream>
#include <string>

double mean(Vector<double> &data);

int main() {
  std::ifstream inFile;
  Vector<double> data;
  std::string line;
  promptUserForFile(inFile, "Enter file name: ");
  while (getline(inFile, line)) {
    if (line.length() < 1)
      data.add(0);
    data.add(stringToReal(line));
  }
  std::cout << "The mean: " << mean(data) << std::endl;
  inFile.close();
  return 0;
}

double mean(Vector<double> &data) {
  double total = 0.0;
  for (int i = 0; i < data.size(); i++) {
    total += data[i];
  }
  return total / data.size();
}
