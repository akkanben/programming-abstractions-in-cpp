/* Programming Abstractions in C++
 *
 * Exercise 13-01
 *
 * Although the SimpleTextEditor application is useful for demonstrating the
 * workings of the editor, it is not ideal as a test program, mostly because it
 * relies on explicit input from the user. Design and implement a unit test for
 * the EditorBuffer class that exercises the methods in the class
 * comprehensively enough to uncover likely errors in the implementation.
 *
 * Solution 2021 Ben Mills
 */

#include <cassert>
#include <iostream>
#include <string>

#include "../00-array-editor-buffer-implementation/EditorBuffer.h"

int main() {
  EditorBuffer buffer;
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
  std::cout << "Simple Text Editor (array implementation) unit test succeeded"
            << std::endl;
  return 0;
}
