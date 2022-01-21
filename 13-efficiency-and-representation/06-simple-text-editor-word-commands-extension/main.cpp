/* Programming Abstractions in C++
 *
 * Exercise 13-06
 *
 * Extend the editor application so that the F, B, and D commands can be
 * preceded with the letter W to indicate word motion. Thus, the command WF
 * should move forward to the end of the next word, WB should move backward to
 * the beginning of the preceding word, and WD should delete characters through
 * the end of the next word. For the purposes of this exercise, a word consists
 * of a consecutive sequence of alphanumeric characters (i.e., letters or
 * digits) and includes any adjacent nonalphanumeric characters between the
 * cursor and the word. This interpretation is easiest to see in the context of
 * an example:
 *
 *  <image of sample run>
 *
 * The most straightforward way to implement these commands is to extend
 * the EditorBuffer class so that it exports methods that perform word-based
 * operations, which are up to you to design. Implement these extensions for all
 * three of the buffer representations introduced in this chapter.
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
    std::string cmd = getLine("Which Editor?");
    if (cmd != "") {
      switch (stringToInteger(cmd)) {
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
        break;
      }
    } else
      break;
  }
  return 0;
}
