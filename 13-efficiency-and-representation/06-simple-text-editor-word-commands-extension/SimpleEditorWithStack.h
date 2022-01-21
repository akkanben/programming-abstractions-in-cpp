#include <cctype>
#include <iostream>

#include "../../StanfordCPPLib/include/foreach.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "EditorBufferWithStack.h"

void executeCommand(EditorBufferWithStack &stackBuffer, std::string line,
                    bool wordFlag);
void displayBuffer(EditorBufferWithStack &stackBuffer);
void printStackHelpText();

EditorBufferWithStack stackBuffer;

void stackEditor() {
  std::cout << "\n~ STACK BASED EDITOR ~" << std::endl;
  while (true) {
    std::string cmd = getLine("*");
    if (cmd != "")
      executeCommand(stackBuffer, cmd, false);
    else
      break;
  }
}

void executeCommand(EditorBufferWithStack &stackBuffer, std::string line,
                    bool wordFlag) {
  switch (toupper(line[0])) {
  case 'I':
    line = line.substr(1);
    foreach (char ch in line) { stackBuffer.insertCharacter(ch); }
    displayBuffer(stackBuffer);
    break;
  case 'D':
    if (wordFlag)
      stackBuffer.deleteWord();
    else
      stackBuffer.deleteCharacter();
    displayBuffer(stackBuffer);
    break;
  case 'F':
    if (wordFlag)
      stackBuffer.moveCursorForwardToEndOfWord();
    else
      stackBuffer.moveCursorForward();
    displayBuffer(stackBuffer);
    break;
  case 'B':
    if (wordFlag)
      stackBuffer.moveCursorBackwardToBeginningOfWord();
    else
      stackBuffer.moveCursorBackward();
    displayBuffer(stackBuffer);
    break;
  case 'J':
    stackBuffer.moveCursorToStart();
    displayBuffer(stackBuffer);
    break;
  case 'E':
    stackBuffer.moveCursorToEnd();
    displayBuffer(stackBuffer);
    break;
  case 'H':
    printStackHelpText();
    break;
  case 'W':
    executeCommand(stackBuffer, line.substr(1), true);
    break;
  case 'Q':
    break;
  default:
    std::cout << "Illegal command" << std::endl;
    break;
  }
}

void displayBuffer(EditorBufferWithStack &stackBuffer) {
  std::string str = stackBuffer.getText();
  for (int i = 0; i < str.length(); i++) {
    std::cout << " " << str[i];
  }
  std::cout << std::endl;
  std::cout << string(2 * stackBuffer.getCursor(), ' ') << "^" << std::endl;
}

void printStackHelpText() {
  std::cout << "Stack Based Editor commands:" << std::endl;
  std::cout << "  Iabc  Inserts the characters abc at the cursor position"
            << std::endl;
  std::cout << "  F     Moves the curosr forward one character" << std::endl;
  std::cout << "  B     Moves the curosr backward one character" << std::endl;
  std::cout << "  D     Deletes the character after the cursor" << std::endl;
  std::cout << "  J     Jumps to the beginning of the stackBuffer" << std::endl;
  std::cout << "  E     Jumps to the end of the stackBuffer" << std::endl;
  std::cout << "  H     Prints this message" << std::endl;
  std::cout << "  W     Indicate a word motion (used with F,B and D)"
            << std::endl;
  std::cout << "  Enter Exits the current editor program" << std::endl;
}
