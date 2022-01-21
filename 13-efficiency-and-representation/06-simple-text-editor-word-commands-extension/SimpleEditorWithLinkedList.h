#include <cctype>
#include <iostream>

#include "../../StanfordCPPLib/include/foreach.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "EditorBufferWithLinkedList.h"

void executeCommand(EditorBufferWithLinkedList &linkedListBuffer,
                    std::string line, bool wordFlag);
void displayBuffer(EditorBufferWithLinkedList &linkedListBuffer);
void printArrayHelpText();

EditorBufferWithLinkedList linkedListBuffer;

void linkedListEditor() {
  std::cout << "\n~ LINKED LIST BASED EDITOR ~" << std::endl;
  while (true) {
    std::string cmd = getLine("*");
    if (cmd != "")
      executeCommand(linkedListBuffer, cmd, false);
    else
      break;
  }
}

void executeCommand(EditorBufferWithLinkedList &linkedListBuffer,
                    std::string line, bool wordFlag) {
  switch (toupper(line[0])) {
  case 'I':
    line = line.substr(1);
    foreach (char ch in line) { linkedListBuffer.insertCharacter(ch); }
    displayBuffer(linkedListBuffer);
    break;
  case 'D':
    if (wordFlag)
      linkedListBuffer.deleteWord();
    else
      linkedListBuffer.deleteCharacter();
    displayBuffer(linkedListBuffer);
    break;
  case 'F':
    if (wordFlag)
      linkedListBuffer.moveCursorForwardToEndOfWord();
    else
      linkedListBuffer.moveCursorForward();
    displayBuffer(linkedListBuffer);
    break;
  case 'B':
    if (wordFlag)
      linkedListBuffer.moveCursorBackwardToBeginningOfWord();
    else
      linkedListBuffer.moveCursorBackward();
    displayBuffer(linkedListBuffer);
    break;
  case 'J':
    linkedListBuffer.moveCursorToStart();
    displayBuffer(linkedListBuffer);
    break;
  case 'E':
    linkedListBuffer.moveCursorToEnd();
    displayBuffer(linkedListBuffer);
    break;
  case 'H':
    printArrayHelpText();
    break;
  case 'W':
    executeCommand(linkedListBuffer, line.substr(1), true);
    break;
  case 'Q':
    break;
  default:
    std::cout << "Illegal command" << std::endl;
    break;
  }
}

void displayBuffer(EditorBufferWithLinkedList &linkedListBuffer) {
  std::string str = linkedListBuffer.getText();
  for (int i = 0; i < str.length(); i++) {
    std::cout << " " << str[i];
  }
  std::cout << std::endl;
  std::cout << string(2 * linkedListBuffer.getCursor(), ' ') << "^"
            << std::endl;
}

void printLinkedListHelpText() {
  std::cout << "Linked Lists Based Editor commands:" << std::endl;
  std::cout << "  Iabc  Inserts the characters abc at the cursor position"
            << std::endl;
  std::cout << "  F     Moves the curosr forward one character" << std::endl;
  std::cout << "  B     Moves the curosr backward one character" << std::endl;
  std::cout << "  D     Deletes the character after the cursor" << std::endl;
  std::cout << "  J     Jumps to the beginning of the linkedListBuffer"
            << std::endl;
  std::cout << "  E     Jumps to the end of the linkedListBuffer" << std::endl;
  std::cout << "  H     Prints this message" << std::endl;
  std::cout << "  W     Indicate a word motion (used with F,B and D)"
            << std::endl;
  std::cout << "  Enter Exits the current editor program" << std::endl;
}
