/* Programming Abstractions in C++
 *
 * Exercise 13-08
 *
 * Editors that support the copy/paste facility described in the preceding
 * exercise usually provide a third operation called cut that copies the text
 * from the buffer and then deletes it. Implement a new editor command called X
 * that implements the cut operation without making any changes to the
 * EditorBuffer class interface beyond those you needed to solve exercise 7.
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
