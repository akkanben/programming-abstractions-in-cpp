/* Programming Abstractions in C++
 *
 * Exercise 13-9
 *
 * For each of the three representations of the buffer given in this chapter,
 * implement the method
 *
 *  bool EditorBuffer::search(string str);
 *
 * When this method is called, it should start searching from the current cursor
 * position, looking for the next occurrence of the string str. If it finds it,
 * search should leave the cursor after the last character in str and return the
 * value true. If str does not occur between the cursor and the end of the
 * buffer, then search should leave the cursor unchanged and return false.
 *
 * To illustrate the operation of search, suppose that you have added the S
 * command to the editor.cpp program so that it calls the search method,
 * passing it the rest of the input line. Your program should then be able to
 * match the following sample run:
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
