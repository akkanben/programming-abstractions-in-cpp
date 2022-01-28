/* Programming Abstractions in C++
 *
 * Exercise 13-12
 *
 * Implement the EditorBuffer class using the strategy described in the section
 * entitled “Doubly linked lists” earlier in this chapter. Be sure to test your
 * implementation as thoroughly as you can. In particular, make sure that you
 * can move the cursor in both directions across parts of the buffer where you
 * have recently made insertions and deletions.
 *
 * Solution 2021 Ben Mills
 */

#include <cassert>
#include <cctype>
#include <iostream>

#include "EditorBufferWithLinkedList.h"

int main() {
  EditorBufferWithLinkedList buffer;
  std::string str = "Hello World";
  assert(buffer.getText() == "");
  buffer.insertCharacter(str[0]);
  assert(buffer.getText() == "H");
  for (int i = 1; i < str.length(); i++)
    buffer.insertCharacter(str[i]);
  assert(buffer.getText() == str);
  buffer.moveCursorToStart();
  assert(buffer.getCursor() == 0);
  buffer.deleteCharacter();
  buffer.insertCharacter('h');
  assert(buffer.getText() == "hello World");
  for (int i = 0; i < 5; i++)
    buffer.moveCursorForward();
  buffer.deleteCharacter();
  buffer.insertCharacter('w');
  assert(buffer.getText() == "hello world");
  buffer.moveCursorToEnd();
  buffer.insertCharacter('!');
  assert(buffer.getText() == "hello world!");
  for (int i = 0; i < 6; i++)
    buffer.moveCursorBackward();
  buffer.insertCharacter('s');
  assert(buffer.getText() == "hello sworld!");
  buffer.moveCursorBackward();
  buffer.moveCursorToStart();
  buffer.moveCursorBackward();
  buffer.moveCursorToEnd();
  buffer.moveCursorForward();
  buffer.moveCursorBackwardToBeginningOfWord();
  buffer.deleteCharacter();
  assert(buffer.getText() == "hello world!");
  buffer.moveCursorToStart();
  buffer.copy(5);
  buffer.moveCursorToEnd();
  buffer.insertCharacter(' ');
  buffer.moveCursorForward();
  buffer.paste();
  buffer.paste();
  assert(buffer.getText() == "hello world! hellohello");
  std::cout << "Doubly linked list based buffer unit test succeeded"
            << std::endl;
  return 0;
}
