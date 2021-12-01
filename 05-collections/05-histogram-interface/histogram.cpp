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

#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/vector.h"
#include <iostream>
#include <string>

void printHistogram(Vector<std::string> &asterisk, Vector<int> &interval) {

  for (int i = 0; i < interval.size(); i++) {
    std::cout << interval[i] << " : " << asterisk[i] << std::endl;
  }
}

void getHistSpecs(int &maximumHistValue, int &minimumHistValue,
                  int &intervalSize, char &displayChar) {
  maximumHistValue = getInteger("Enter a maximum: ");
  minimumHistValue = getInteger("Enter a minimum: ");
  intervalSize = getInteger("Enter an interval size: ");
  displayChar = getLine("Enter a display character: ")[0];
}

void initializeVectors(Vector<int> &data, Vector<std::string> &asterisk,
                       Vector<int> &interval, char &displayChar) {
  int minimumHistValue;
  int maximumHistValue;
  int intervalSize;
  getHistSpecs(maximumHistValue, minimumHistValue, intervalSize, displayChar);
  int intervalCount = (maximumHistValue - minimumHistValue) / intervalSize;
  // Initializing interval and asterisk
  for (int i = 0; i <= intervalCount; i++) {
    interval.add(minimumHistValue + (intervalSize * i));
    asterisk.add("");
  }
  // filing asterisk
  for (int i = 0; i < data.size(); i++) {
    asterisk[data[i] / intervalSize] += displayChar;
  }
}

