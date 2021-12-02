/* Programming Abstractions in C++
 *
 * Exercise
 *
 * QUESTION
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/filelib.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/stack.h"
#include <iostream>

bool isCorrectlyBracketed(std::string str);

int main() {
  std::ifstream inFile;
  std::string fileName = promptUserForFile(inFile, "Enter a file to check: ");
  std::string line;
  int lineCount = 0;
  while (getline(inFile, line)) {
    lineCount++;
    if (isCorrectlyBracketed(line)) {
      std::cout << "Line " << lineCount << ": Correctly Bracketed."
                << std::endl;
    } else {
      std::cout << "Line " << lineCount << ": Incorrectly Bracketed."
                << std::endl;
    }
  }
  return 0;
}

bool isCorrectlyBracketed(std::string str) {
  Stack<char> stack;
  char currentStackChar;
  std::string justTheBrackets;
  // creates the justTheBrackets string and gets rid of all the rest.
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' ||
        str[i] == '[' || str[i] == ']') {
      justTheBrackets += str[i];
    }
  }
  if (justTheBrackets.size() % 2 == 1)
    return false;
  for (int i = 0; i < justTheBrackets.length(); i++) {
    if (stack.size() > 0) {
      currentStackChar = stack.peek();
    }
    if (justTheBrackets[i] == '(' || justTheBrackets[i] == '{' ||
        justTheBrackets[i] == '[') {
      stack.push(justTheBrackets[i]);
    } else {
      if (currentStackChar == '(' && justTheBrackets[i] == ')') {
        stack.pop();
      } else if (currentStackChar == '{' && justTheBrackets[i] == '}') {
        stack.pop();
      } else if (currentStackChar == '[' && justTheBrackets[i] == ']') {
        stack.pop();
      } else {
        return false;
      }
    }
  }
  return true;
}
