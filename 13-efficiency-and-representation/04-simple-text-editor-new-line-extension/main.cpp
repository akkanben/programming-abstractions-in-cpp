/* Programming Abstractions in C++
 *
 * Exercise 13-04
 *
 * One of the serious limitations of the SimpleTextEditor application is that it
 * offers no way to insert a newline character into the buffer, making it
 * impossible to enter more than one line of data. Starting with the editor
 * application from exercise 2, add an A command that reads text on subsequent
 * lines, ending when the user enters a line consisting of a single period (as
 * in the ed editor on Unix systems). A sample run of this version of the editor
 * might look like this:
 *
 *  <image of sample run>
 *
 * Solution 2021 Ben Mills
 */

#include <cctype>
#include <iostream>

#include "../../StanfordCPPLib/include/foreach.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "EditorBuffer.h"

void executeCommand(EditorBuffer &buffer, std::string line);
void displayBuffer(EditorBuffer &buffer);
void printHelpText();

int main() {
  EditorBuffer buffer;
  while (true) {
    std::string cmd = getLine("*");
    if (cmd != "")
      executeCommand(buffer, cmd);
  }
  return 0;
}

void executeCommand(EditorBuffer &buffer, std::string line) {
  switch (toupper(line[0])) {
  case 'I':
    line = line.substr(1);
    foreach (char ch in line) { buffer.insertCharacter(ch); }
    break;
  case 'A':
    while (true) {
      line = getLine("");
      if (line != ".") {
        foreach (char ch in line) { buffer.insertCharacter(ch); }
        buffer.insertCharacter('\n');
      } else {
        if (buffer.getCursor() == buffer.getSize()) {
          buffer.moveCursorBackward();
          buffer.deleteCharacter();
        }
        break;
      }
    }
    break;
  case 'D':
    buffer.deleteCharacter();
    break;
  case 'F':
    buffer.moveCursorForward();
    break;
  case 'B':
    buffer.moveCursorBackward();
    break;
  case 'J':
    buffer.moveCursorToStart();
    break;
  case 'E':
    buffer.moveCursorToEnd();
    break;
  case 'H':
    printHelpText();
    break;
  case 'T':
    std::cout << buffer.getText() << std::endl;
    break;
  case 'Q':
    exit(0);
  default:
    std::cout << "Illegal command" << std::endl;
    break;
  }
}

void displayBuffer(EditorBuffer &buffer) {
  std::string str = buffer.getText();
  for (int i = 0; i < str.length(); i++) {
    std::cout << " " << str[i];
  }
  std::cout << std::endl;
  std::cout << string(2 * buffer.getCursor(), ' ') << "^" << std::endl;
}

void printHelpText() {
  std::cout << "Editor commands:" << std::endl;
  std::cout << "  Iabc  Inserts the characters abc at the cursor position"
            << std::endl;
  std::cout << "  F     Moves the curosr forward one character" << std::endl;
  std::cout << "  B     Moves the curosr backward one character" << std::endl;
  std::cout << "  D     Deletes the character after the cursor" << std::endl;
  std::cout << "  J     Jumps to the beginning of the buffer" << std::endl;
  std::cout << "  E     Jumps to the end of the buffer" << std::endl;
  std::cout << "  T     Print the buffer" << std::endl;
  std::cout << "  H     Prints this message" << std::endl;
  std::cout << "  Q     Exits the editor program" << std::endl;
}
