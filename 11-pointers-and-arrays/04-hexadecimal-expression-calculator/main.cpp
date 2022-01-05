/* Programming Abstractions in C++
 *
 * Exercise 11-04
 *
 * Rewrite the simple expression calculator from Chapter 6, exercise 11, so that
 * both the input and output values are represented in hexadecimal. A sample
 * run of this program might look like this:
 *
 * <image of sample run>
 *
 * In writing this program, the easiest approach is to scan all tokens as words
 * rather than numbers and then call the functions you wrote for exercise 3 to
 * perform the conversions.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "../../StanfordCPPLib/include/tokenscanner.h"

double findCurrentTotal(std::string v1, std::string v2, std::string op);
std::string integerToString(int number);
std::string integerToString(int number, int base);
int stringToInteger(std::string str);
int stringToInteger(std::string str, int base);
double logNRaiseToPower(double x, int n);

int main() {
  std::string line = "not blank";
  double total = 0;
  while (line != "") {
    line = getLine("> ");
    TokenScanner scanner(line);
    scanner.ignoreWhitespace();
    // scanner.scanNumbers();
    std::string v1, v2, op;
    v1 = scanner.nextToken();
    while (scanner.hasMoreTokens()) {
      op = scanner.nextToken();
      v2 = scanner.nextToken();
      total = findCurrentTotal(v1, v2, op);
      v1 = integerToString(total, 16);
    }
    std::cout << integerToString(total, 16) << std::endl;
  }
  return 0;
}

double findCurrentTotal(std::string v1, std::string v2, std::string op) {

  double a = stringToInteger(v1, 16);
  double b = stringToInteger(v2, 16);

  if (op == "+") {
    return a + b;
  } else if (op == "-") {
    return a - b;
  } else if (op == "*") {
    return a * b;
  } else if (op == "/") {
    return a / b;
  } else {
    return 0;
  }
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
