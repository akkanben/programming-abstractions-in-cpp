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
    displayBuffer(buffer);
    break;
  case 'D':
    buffer.deleteCharacter();
    displayBuffer(buffer);
    break;
  case 'F':
    buffer.moveCursorForward();
    displayBuffer(buffer);
    break;
  case 'B':
    buffer.moveCursorBackward();
    displayBuffer(buffer);
    break;
  case 'J':
    buffer.moveCursorToStart();
    displayBuffer(buffer);
    break;
  case 'E':
    buffer.moveCursorToEnd();
    displayBuffer(buffer);
    break;
  case 'H':
    printHelpText();
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
  std::cout << "  H     Prints this message" << std::endl;
  std::cout << "  Q     Exits the editor program" << std::endl;
}
