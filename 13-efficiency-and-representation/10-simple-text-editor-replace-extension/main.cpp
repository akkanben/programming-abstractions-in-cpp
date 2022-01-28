/* Programming Abstractions in C++
 *
 * Exercise 13-10
 *
 * Without making any changes to the EditorBuffer class interface beyond
 * those required for exercise 9, add an R command to the editor application
 * that replaces the next occurrence of one string with another, where the two
 * strings are specified after the R command separated by a slash, as shown:
 *
 *  <image of sample run>
 *
 * Solution 2021 Ben Mills
 */

#include <cctype>
#include <iostream>

#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "SimpleEditorWithArray.h"
#include "SimpleEditorWithLinkedList.h"
#include "SimpleEditorWithStack.h"

int main() {
  while (true) {
    std::cout << "1: Stack" << std::endl;
    std::cout << "2: Array" << std::endl;
    std::cout << "3: Linked List" << std::endl;
    std::cout << "0: Quit" << std::endl;
    int cmd = getInteger("Which Editor? ");
    switch (cmd) {
    case 1:
      stackEditor();
      break;
    case 2:
      arrayEditor();
      break;
    case 3:
      linkedListEditor();
      break;
    default:
      std::cout << "Not a valid option." << std::endl;
      std::cout << "Exiting." << std::endl;
    case 0:
      return 0;
    }
  }
}
