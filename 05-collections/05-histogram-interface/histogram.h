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

#ifndef _histogram_h
#define _histogram_h

#include "../../StanfordCPPLib/include/vector.h"
#include <string>

void printHistogram(Vector<std::string> &asterisk, Vector<int> &interval);

void initializeVectors(Vector<int> &data, Vector<std::string> &asterisk,
                       Vector<int> &interval, char &displayChar);

void getHistSpecs(int &maximumHistValue, int &minimumHistValue,
                  int &intervalSize, char &displayChar);

#endif
