/* Programming Abstractions in C++
 *
 * Exercise
 *
 * Another common statistical measure is the standard deviation, which provides
 * an indication of how much the values in a distribution x1, x2, x3, . . . , xn
 * differ from the mean. In mathematical form, the standard deviation (!) is
 * expressed as follows, at least if you are computing the standard deviation of
 * a complete distribution as opposed to a sample:
 *
 * <image of standard deviation equation>
 *
 * The Greek letter sigma indicates a summation of the quantity that follows,
 * which in this case is the square of the difference between the mean and each
 * individual data point. Write a function
 *
 *  double stddev(Vector<double> & data);
 *
 * that returns the standard deviation of the data distribution.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/filelib.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "../../StanfordCPPLib/include/vector.h"
#include <iostream>
#include <math.h>
#include <string>

double mean(Vector<double> &data);
double stddev(Vector<double> &data);

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
  std::cout << "The mean is: " << mean(data) << std::endl;
  std::cout << "The standard deviation is: " << stddev(data) << std::endl;
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

double stddev(Vector<double> &data) {
  double variance = 0.0;
  double total = 0.0;

  // Get the mean first
  for (int i = 0; i < data.size(); i++) {
    total += data[i];
  }
  double mean = total / data.size();

  // Find the square of the difference between each value, total these.
  for (int i = 0; i < data.size(); i++) {
    variance += (data[i] - mean) * (data[i] - mean);
  }
  variance = variance / data.size();
  return sqrt(variance);
}
