/* Programming Abstractions in C++
 *
 * Exercise 06-12
 *
 * Extend the program you wrote for the preceding exercise so that the terms in
 * the expressions can also be variable names assigned earlier in the session by
 * entering simple assignment statements as shown in the following sample run:
 *
 * Solution 2021 Ben Mills
 */

#include <cctype>
#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/map.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "../../StanfordCPPLib/include/tokenscanner.h"

std::string convertVar(std::string v, Map<std::string, std::string> varMap);
double findCurrentTotal(std::string v1, std::string v2, std::string op,
                        Map<std::string, std::string> varMap);

int main() {
  Map<std::string, std::string> variables;
  std::string line;
  double total = 0;
  do {
    line = getLine("> ");
    TokenScanner scanner(line);
    scanner.ignoreWhitespace();
    scanner.scanNumbers();
    std::string v1, v2, op = "";
    bool assignFlag = false;
    v1 = scanner.nextToken();
    while (scanner.hasMoreTokens()) {
      op = scanner.nextToken();
      if (op == "=") {
        assignFlag = true;
        std::string assign_v1, assign_v2, assign_op;
        assign_v1 = scanner.nextToken();
        while (scanner.hasMoreTokens()) {
          assign_op = scanner.nextToken();
          assign_v2 = scanner.nextToken();
          total = findCurrentTotal(assign_v1, assign_v2, assign_op, variables);
          assign_v1 = realToString(total);
        }
        variables.put(v1, assign_v1);
      } else {
        v2 = scanner.nextToken();
        total = findCurrentTotal(v1, v2, op, variables);
        v1 = realToString(total);
      }
    }
    if (v1 != "")
      total = stringToReal(convertVar(v1, variables));
    if (!assignFlag)
      std::cout << total << std::endl;
  } while (line != "");
  return 0;
}

double findCurrentTotal(std::string v1, std::string v2, std::string op,
                        Map<std::string, std::string> varMap) {
  double a, b;
  a = stringToReal(convertVar(v1, varMap));
  b = stringToReal(convertVar(v2, varMap));
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

std::string convertVar(std::string v, Map<std::string, std::string> varMap) {
  if (isalpha(v[0]))
    return varMap.get(v);
  else
    return v;
}
