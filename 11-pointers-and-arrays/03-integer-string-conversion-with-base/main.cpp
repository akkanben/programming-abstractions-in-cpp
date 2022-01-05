/* Programming Abstractions in C++
 *
 * Exercise 11-03
 *
 * Write overloaded versions of the integerToString and stringToInteger
 * functions that take a second argument indicating the numeric base, which can
 * be any integer in the range 2 through 36 (the 10 digits plus the 26 letters).
 * For example, calling
 *
 *  integerToString(42, 16)
 *
 * should return the string "2A". Similarly, calling
 *
 *  stringToInteger("111111", 2)
 *
 * should return the integer 63. Your functions should allow for negative
 * numbers and should generate an error if any of the digits in the first
 * argument to stringToInteger is out of range for the specified base.
 * *
 * Solution 2021 Ben Mills
 */

#include <iomanip>
#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/error.h"

std::string integerToString(int number);
std::string integerToString(int number, int base);
int stringToInteger(std::string str);
int stringToInteger(std::string str, int base);
double logNRaiseToPower(double x, int n);

int main() {
  std::cout << "STRING TO INTEGER TESTS:" << std::endl;
  std::cout << "stringToInteger(\"42\") = " << stringToInteger("42")
            << std::endl
            << "stringToInteger(\"-42\") = " << stringToInteger("-42")
            << std::endl;
  std::cout << "stringToInteger(\"111111\", 2) = "
            << stringToInteger("111111", 2) << std::endl
            << "stringToInteger(\"-111111\", 2) = "
            << stringToInteger("-111111", 2) << std::endl;
  std::cout << "stringToInteger(\"2A\", 16) = " << stringToInteger("2A", 16)
            << std::endl
            << "stringToInteger(\"-2A\", 16) = " << stringToInteger("-2A", 16)
            << std::endl;
  std::cout << "stringToInteger(\"40\", 8) = " << stringToInteger("40", 8)
            << std::endl
            << "stringToInteger(\"-40\", 8) = " << stringToInteger("-40", 8)
            << std::endl;
  std::cout << "stringToInteger(\"000\") = " << stringToInteger("000")
            << std::endl;
  std::cout << std::endl;
  std::cout << "INTEGER TO STRING TESTS:" << std::endl;
  std::cout << "Base 10  |  Base 02  |  Base 08  |  Base 16" << std::endl;
  std::cout << "---------+-----------+-----------+---------" << std::endl;
  for (int i = -10; i < 74; i++) {
    std::cout << std::right << std::setw(7) << integerToString(i) << "     "
              << std::setw(7) << integerToString(i, 2) << "     "
              << std::setw(7) << integerToString(i, 8) << "     "
              << std::setw(7) << integerToString(i, 16) << std::endl;
  }
  return 0;
}

std::string integerToString(int number) {
  std::string output = "";
  bool negativeFlag = false;
  if (number == 0)
    output = '0';
  if (number < 0) {
    number = -number;
    negativeFlag = true;
  }
  while (number > 0) {
    char letter = (number % 10) + '0';
    output = letter + output;
    number /= 10;
  }
  return negativeFlag ? '-' + output : output;
}

std::string integerToString(int number, int base) {
  if (base > 36)
    error("Base must be 36 or less.");
  std::string output = "";
  bool negativeFlag = false;
  if (number == 0)
    output = '0';
  if (number < 0) {
    number = -number;
    negativeFlag = true;
  }
  while (number > 0) {
    char letter = (number % base) + '0';
    if (letter > '9')
      letter += 7; // the difference between '9' and 'A' in ascii
    output = letter + output;
    number /= base;
  }
  return negativeFlag ? '-' + output : output;
}

int stringToInteger(std::string str) {
  bool negativeFlag = false;
  if (str[0] == '-') {
    str = str.substr(1);
    negativeFlag = true;
  }
  int output = 0;
  int position = 0;
  for (int i = str.length() - 1; i >= 0; i--) {
    int number = str[i] - '0';
    output += number * logNRaiseToPower(10, position);
    position++;
  }
  return negativeFlag ? -output : output;
}

int stringToInteger(std::string str, int base) {
  bool negativeFlag = false;
  if (str[0] == '-') {
    str = str.substr(1);
    negativeFlag = true;
  }
  int output = 0;
  int position = 0;
  for (int i = str.length() - 1; i >= 0; i--) {
    int number = str[i] - '0';
    if (number > 9)
      number -= 7; // again accounting for the ascii difference
    number *= logNRaiseToPower(base, position);
    output += number;
    position++;
  }
  return negativeFlag ? -output : output;
}

double logNRaiseToPower(double x, int n) {
  if (n == 0)
    return 1;
  if (n == 1)
    return x;
  double reducedPower = logNRaiseToPower(x, n / 2);
  if (n % 2 == 1)
    return reducedPower * reducedPower * x;
  else
    return reducedPower * reducedPower;
}
