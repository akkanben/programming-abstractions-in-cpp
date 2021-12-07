/* Programming Abstractions in C++
 *
 * Exercise 06-14
 *
 * Implement the scanStrings method for the TokenScanner class. When
 * scanStrings is in effect, the token scanner should return quoted strings as
 * single tokens. The strings may use either single or double quotation marks
 * and should include the quotation marks in the string that nextToken returns.
 *
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/error.h"
#include "tokenscanner.h"

void saveToken(Stack<std::string> &s, std::string str);
std::string popSaved(Stack<std::string> &s);

int main() {
  const std::string text = "Using \"air quotes\" is silly.";
  TokenScanner scanner(text);
  scanner.scanStrings();
  while (scanner.hasMoreTokens()) {
    std::string token = scanner.nextToken();
    std::cout << token << std::endl;
  }
  return 0;
}
