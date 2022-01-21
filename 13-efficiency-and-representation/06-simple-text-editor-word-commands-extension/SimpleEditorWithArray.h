#include <cctype>
#include <iostream>

#include "../../StanfordCPPLib/include/foreach.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "EditorBufferWithArray.h"

void executeCommand(EditorBufferWithArray &arrayBuffer, std::string line,
                    bool wordFlag);
void displayBuffer(EditorBufferWithArray &arrayBuffer);
void printArrayHelpText();

EditorBufferWithArray arrayBuffer;

void arrayEditor() {
  std::cout << "\n~ ARRAY BASED EDITOR ~" << std::endl;
  while (true) {
    std::string cmd = getLine("*");
    if (cmd != "")
      executeCommand(arrayBuffer, cmd, false);
    else
      break;
  }
}

void executeCommand(EditorBufferWithArray &arrayBuffer, std::string line,
                    bool wordFlag) {
  switch (toupper(line[0])) {
  case 'I':
    line = line.substr(1);
    foreach (char ch in line) { arrayBuffer.insertCharacter(ch); }
    displayBuffer(arrayBuffer);
    break;
  case 'D':
    if (wordFlag)
      arrayBuffer.deleteWord();
    else
      arrayBuffer.deleteCharacter();
    displayBuffer(arrayBuffer);
    break;
  case 'F':
    if (wordFlag)
      arrayBuffer.moveCursorForwardToEndOfWord();
    else
      arrayBuffer.moveCursorForward();
    displayBuffer(arrayBuffer);
    break;
  case 'B':
    if (wordFlag)
      arrayBuffer.moveCursorBackwardToBeginningOfWord();
    else
      arrayBuffer.moveCursorBackward();
    displayBuffer(arrayBuffer);
    break;
  case 'J':
    arrayBuffer.moveCursorToStart();
    displayBuffer(arrayBuffer);
    break;
  case 'E':
    arrayBuffer.moveCursorToEnd();
    displayBuffer(arrayBuffer);
    break;
  case 'H':
    printArrayHelpText();
    break;
  case 'W':
    executeCommand(arrayBuffer, line.substr(1), true);
    break;
  case 'Q':
    break;
  default:
    std::cout << "Illegal command" << std::endl;
    break;
  }
}

void displayBuffer(EditorBufferWithArray &arrayBuffer) {
  std::string str = arrayBuffer.getText();
  for (int i = 0; i < str.length(); i++) {
    std::cout << " " << str[i];
  }
  std::cout << std::endl;
  std::cout << string(2 * arrayBuffer.getCursor(), ' ') << "^" << std::endl;
}

void printArrayHelpText() {
  std::cout << "Array Based Editor commands:" << std::endl;
  std::cout << "  Iabc  Inserts the characters abc at the cursor position"
            << std::endl;
  std::cout << "  F     Moves the curosr forward one character" << std::endl;
  std::cout << "  B     Moves the curosr backward one character" << std::endl;
  std::cout << "  D     Deletes the character after the cursor" << std::endl;
  std::cout << "  J     Jumps to the beginning of the arrayBuffer" << std::endl;
  std::cout << "  E     Jumps to the end of the arrayBuffer" << std::endl;
  std::cout << "  H     Prints this message" << std::endl;
  std::cout << "  W     Indicate a word motion (used with F,B and D)"
            << std::endl;
  std::cout << "  Enter Exits the current editor program" << std::endl;
}
