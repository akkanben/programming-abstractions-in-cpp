/* Programming Abstractions in C++
 *
 * Exercise 06-15
 *
 * Implement the scanNumbers method for the TokenScanner class, which
 * causes the token scanner to read any valid C++ number as a single token. The
 * difficult part of this extension lies in understanding the rules for what
 * constitutes a valid numeric string and then finding a way to implement those
 * rules efficiently. The easiest way to specify those rules is in a form that
 * computer scientists call a finite-state machine, which is usually represented
 * diagrammatically as a collection of circles representing the possible states
 * of the machine. The circles are then connected by a set of labeled arcs that
 * indicate how the process moves from one state to another. A finite-state
 * machine for scanning a real number appears in Figure 6-15.
 *
 * When you use a finite-state machine, you start in state s0 and then follow
 * the labeled arcs for each character in the input until there is no arc that
 * matches the current character. If you end up in a state marked by a double
 * circle, you have successfully scanned a number. These states that indicate
 * successful scanning of a token are called final states. Figure 6-15 includes
 * three examples that show how the finite-state machine scans numbers of
 * various kinds.
 *
 * The easiest way to write the code that scans a token when scanNumbers is
 * in effect is to simulate the operation of the finite-state machine. Your code
 * should keep track of the current state and then go through the input one
 * character at a time. Each character will either signal the end of the number
 * or send the machine into a new state.
 *
 *  <Figure 6-15>
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
  const std::string text =
      "Integer number 1234, real number 123.321, scientific notation 2.0E+9.";
  TokenScanner scanner(text);
  scanner.scanNumbers();
  while (scanner.hasMoreTokens()) {
    std::string token = scanner.nextToken();
    std::cout << token << std::endl;
  }
  return 0;
}
