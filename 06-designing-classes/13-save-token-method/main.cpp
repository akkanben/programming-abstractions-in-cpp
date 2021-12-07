/* Programming Abstractions in C++
 *
 * Exercise 06-13
 *
 * Implement the saveToken method for the TokenScanner class. This
 * method saves the specified token so that subsequent calls to nextToken
 * return the saved token without consuming any additional characters from the
 * input. Your implementation should allow clients to save multiple tokens,
 * which are then returned so that the last token saved is the first token
 * returned.
 *
 * Solution 2021 Ben Mills
 */

#include <fstream>
#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/error.h"
#include "tokenscanner.h"

void saveToken(Stack<std::string> &s, std::string str);
std::string popSaved(Stack<std::string> &s);

int main() {
  const std::string text =
      "Implement the saveToken method for the TokenScanner class. This method "
      "saves the specified token so that subsequent calls to nextToken return "
      "the saved token without consuming any additional characters from the "
      "input. Your implementation should allow clients to save multiple "
      "tokens, which are then returned so that the last token saved is the "
      "first token returned.";
  TokenScanner scanner(text);
  while (scanner.hasMoreTokens()) {
    std::string token = scanner.nextToken();
    scanner.saveToken(integerToString(token.length()));
    std::string count = scanner.nextToken();
    std::cout << token << "(" << count << ")" << std::endl;
  }
  return 0;
}
