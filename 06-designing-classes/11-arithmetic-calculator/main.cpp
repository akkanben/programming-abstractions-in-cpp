/* Programming Abstractions in C++
 *
 * Exercise 06-11
 *
 * Write a program that implements a simple arithmetic calculator. Input to the
 * calculator consists of lines composed of numbers (either integers or reals)
 * combined together using the arithmetic operators +, -, *, and /. For each
 * line of input, your program should display the result of applying the
 * operators from left to right. You should use the token scanner to read the
 * terms and operators and set up the scanner so that it ignores any whitespace
 * characters. Your program should exit when the user enters a blank line. A
 * sample run of your program might look like this:
 *
 *  <image of sample run>
 *
 * The last line in this sample run is the arithmetic problem the Mathemagician
 * gives to Milo in Norton Juster’s children’s story, The Phantom Tollbooth.
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

int main() {
  std::string line = "not blank";
  double total = 0;
  while (line != "") {
    line = getLine("> ");
    TokenScanner scanner(line);
    scanner.ignoreWhitespace();
    scanner.scanNumbers();
    std::string v1, v2, op;
    v1 = scanner.nextToken();
    while (scanner.hasMoreTokens()) {
      op = scanner.nextToken();
      v2 = scanner.nextToken();
      total = findCurrentTotal(v1, v2, op);
      v1 = realToString(total);
    }
    std::cout << total << std::endl;
  }
  return 0;
}

double findCurrentTotal(std::string v1, std::string v2, std::string op) {
  double a = stringToReal(v1);
  double b = stringToReal(v2);

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
