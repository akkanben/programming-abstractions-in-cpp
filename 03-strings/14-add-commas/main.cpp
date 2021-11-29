/* Programming Abstractions in C++
 *
 * Exercise 03-14
 *
 * When large numbers are written out on paper, it is traditional—at least in
 * the United States—to use commas to separate the digits into groups of three.
 * For example, the number one million is usually written in the following form:
 *
 * 1,000,000
 *
 * To make it easier for programmers to display numbers in this fashion,
 * implement a function
 *
 *  string addCommas(string digits);
 *
 * that takes a string of decimal digits representing a number and returns the
 * string formed by inserting commas at every third position, starting on the
 * right. For example, if you were to execute the main program
 *
 *  int main() {
 *    while (true) {
 *      string digits;
 *      cout << "Enter a number: ";
 *      getline(cin, digits);
 *      if (digits == "") break;
 *      cout << addCommas(digits) << endl;
 *    }
 *    return 0;
 *  }
 *
 * your implementation of the addCommas function should be able to produce the
 * following sample run:
 *
 * <image of example run>
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include <iostream>
#include <string>

std::string addCommas(std::string str);

int main() {
  while (true) {
    std::string digits;
    std::cout << "Enter a number: ";
    getline(std::cin, digits);
    if (digits == "")
      break;
    std::cout << addCommas(digits) << std::endl;
  }
  return 0;
}

std::string addCommas(std::string str) {
  int postion = 1;
  int commaCount = 0;
  for (int i = str.length() - 1; i > 0; i--) {
    if (postion >= 3 && postion % 3 == 0) {
      str = str.substr(0, str.length() - postion - commaCount) + "," +
            str.substr(str.length() - postion - commaCount);
      commaCount++;
      postion++;
    } else {
      postion++;
    }
  }
  return str;
}
