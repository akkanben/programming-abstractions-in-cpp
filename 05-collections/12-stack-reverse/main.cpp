/* Programming Abstractions in C++
 *
 * Exercise 05-12
 *
 * Write a program that uses a stack to reverse a sequence of integers read from
 * the console one number per line, as shown in the following sample run:
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/stack.h"
#include <iostream>

int main() {
  Stack<int> stack;
  std::cout << "Enter a list of integers, ending in 0:" << std::endl;
  int num = getInteger("? ");
  while (num != 0) {
    stack.push(num);
    num = getInteger("? ");
  }
  std::cout << "Those integers in reverse order are:" << std::endl;
  int size = stack.size(); // we need this because the size of the stack changes
                           // as we pop items off
  for (int i = 0; i < size; i++) {
    std::cout << stack.pop() << std::endl;
  }
  return 0;
}
