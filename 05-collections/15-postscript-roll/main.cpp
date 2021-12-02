/* Programming Abstractions in C++
 *
 * Exercise 05-15
 *
 * The figures in this book are created using PostScript®, a powerful graphics
 * language developed by the Adobe Corporation in the early 1980s. PostScript
 * programs store their data on a stack. Many of the operators available in the
 * PostScript language have the effect of manipulating the stack in some way.
 * You can, for example, invoke the pop operator, which pops the top element
 * off the stack, or the exch operator, which swaps the top two elements.
 *
 * One of the most interesting (and surprisingly useful) PostScript operators is
 * the roll operator, which takes two arguments: n and k. The effect of
 * applying roll(n,k) is to rotate the top n elements of a stack by k positions,
 * where the general direction of the rotation is toward the top of the stack.
 * More specifically, roll(n, k) has the effect of removing the top n elements,
 * cycling the top element to the last position k times, and then replacing the
 * reordered elements back on the stack. Figure 5-14 shows before and after
 * pictures for three different examples of roll.
 *
 *  <Figure 5-14>
 *
 * Write a function
 *
 *  void roll(Stack<char> & stack, int n, int k)
 *
 * that implements the roll(n, k) operation on the specified stack. Your
 * implementation should check that n and k are both nonnegative and that n is
 * not larger than the stack size; if either of these conditions is violated,
 * your implementation should call error with the message
 *
 *  roll: argument out of range
 *
 * Note, however, that k can be larger than n, in which case the roll operation
 * continues through more than a complete cycle. This case is illustrated in the
 * final example in Figure 5-14, in which the top two elements on the stack are
 * rolled four times, leaving the stack exactly as it started.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/stack.h"
#include <iostream>

void roll(Stack<char> &stack, int n, int k);
std::string stackToString(Stack<char> stack);

int main() {
  Stack<char> stack;
  stack.push('a');
  stack.push('b');
  stack.push('c');
  stack.push('d');
  int num = getInteger("Enter a number of characters: ");
  if (num > stack.size() || num < 0) {
    error("roll: argument out of range");
    return 0;
  }
  int pos = getInteger("Enter a number of possitions to move back: ");
  if (pos < 0) {
    error("roll: argument out of range");
    return 0;
  }
  std::cout << "Before: " << stackToString(stack) << std::endl;
  roll(stack, num, pos);
  std::cout << "After: " << stackToString(stack) << std::endl;
  return 0;
}

void roll(Stack<char> &stack, int n, int k) {
  Stack<char> secondStack;
  std::string str;
  for (int i = 0; i < n; i++) {
    str += stack.pop();
  }
  str.insert(0, str.substr(k % n));
  for (int i = 0; i < n; i++) {
    secondStack.push(str[i]);
  }
  for (int i = 0; i < n; i++) {
    stack.push(secondStack.pop());
  }
}

std::string stackToString(Stack<char> stack) {
  std::string str;
  int size = stack.size();
  for (int i = 0; i < size; i++) {
    str += stack.pop();
  }
  return str;
}
