/* Programming Abstractions in C++
 *
 * Exercise 13-07
 *
 * Most modern editors provide a facility that allows the user to copy a section
 * of the buffer text into an internal storage area and then paste it back in at
 * some other position. For each of the three representations of the buffer
 * given in this chapter, implement the method
 *
 *  void EditorBuffer::copy(int count);
 *
 * which stores a copy of the next count characters somewhere in the internal
 * structure for the buffer, and the method
 *
 *  void EditorBuffer::paste();
 *
 * which inserts those saved characters back into the buffer at the current
 * cursor position. Calling paste does not affect the saved text, which means
 * that you can insert multiple copies of the same text by calling paste more
 * than once.
 *
 * Test your implementation by adding the commands C and P to the editor
 * application for the copy and paste operations, respectively. The C command
 * should take a numeric argument to specify the number of characters using the
 * technique described in exercise 5.
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
