/* Programming Abstractions in C++
 *
 * Exercise 13-02
 *
 * Even though the stacks in the two-stack implementation of the EditorBuffer
 * class (see Figures 13-6 and 13-7) expand dynamically, the amount of character
 * space required in the stacks is likely to be twice as large as that required
 * in the corresponding array implementation. The problem is that each stack
 * must be able to accommodate all the characters in the buffer. Suppose, for
 * example, that you are working with a buffer containing N characters. If
 * you’re at the beginning of the buffer, those N characters are in the after
 * stack; if you move to the end of the buffer, those N characters move to the
 * before stack. As a result, each of the stacks must have a capacity of N
 * characters.
 *
 * You can reduce the storage requirement in the two-stack implementation of
 * the buffer by storing the two stacks at opposite ends of the same internal
 * array. The before stack starts at the beginning of the array, while the after
 * stack starts at the end. The two stacks then grow toward each other as
 * indicated by the arrows in the following diagram:
 *
 *  before --->         <--- after
 *
 * Reimplement the EditorBuffer class using this representation (which is, in
 * fact, the design strategy used in many editors today). Make sure that your
 * program continues to have the same computational efficiency as the two-stack
 * implementation in the text and that the buffer space expands dynamically as
 * needed.
 *
 * Solution 2021 Ben Mills
 *
 * The updated EditorBuffer files and the DoubleCharStack class implement the
 * exercise, this main file just tests it.
 */

#include <cassert>
#include <iostream>
#include <string>

#include "EditorBuffer.h"

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
  std::string str2 =
      "(inserting more text to make sure the capacity expands correctly) ";
  buffer.moveCursorBackward();
  for (int i = 0; i < str2.length(); i++)
    buffer.insertCharacter(str2[i]);
  assert(buffer.getText() == "hello (inserting more text to make sure the "
                             "capacity expands correctly) sworld!");
  std::cout << "Simple Text Editor (array implementation) unit test succeeded"
            << std::endl;
  return 0;
}
