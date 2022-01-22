#include <cctype>
#include <iostream>

#include "../../StanfordCPPLib/include/foreach.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "EditorBufferWithArray.h"

void executeCommand(EditorBufferWithArray &arrayBuffer, std::string line,
                    bool wordFlag);
void displayBuffer(EditorBufferWithArray &arrayBuffer);
void printArrayHelpText();
int getActionCount(std::string &str);

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
  int count = getActionCount(line);
  switch (toupper(line[0])) {
  case 'I':
    line = line.substr(1);
    foreach (char ch in line) { arrayBuffer.insertCharacter(ch); }
    displayBuffer(arrayBuffer);
    break;
  case 'D':
    while (count-- > 0) {
      if (wordFlag)
        arrayBuffer.deleteWord();
      else
        arrayBuffer.deleteCharacter();
    }
    displayBuffer(arrayBuffer);
    break;
  case 'F':
    while (count-- > 0) {
      if (wordFlag)
        arrayBuffer.moveCursorForwardToEndOfWord();
      else
        arrayBuffer.moveCursorForward();
    }
    displayBuffer(arrayBuffer);
    break;
  case 'B':
    while (count-- > 0) {
      if (wordFlag)
        arrayBuffer.moveCursorBackwardToBeginningOfWord();
      else
        arrayBuffer.moveCursorBackward();
    }
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
  case 'C':
    arrayBuffer.copy(count);
    displayBuffer(arrayBuffer);
    break;
  case 'P':
    while (count-- > 0) {
      arrayBuffer.paste();
    }
    displayBuffer(arrayBuffer);
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
  std::cout << "  C     Copies character under the cursor" << std::endl;
  std::cout << "  P     Pastes characters that have been saved to memory"
            << std::endl;
  std::cout << "  J     Jumps to the beginning of the arrayBuffer" << std::endl;
  std::cout << "  E     Jumps to the end of the arrayBuffer" << std::endl;
  std::cout << "  H     Prints this message" << std::endl;
  std::cout << "  W     Indicate a word motion (used with F,B and D)"
            << std::endl;
  std::cout << "  #     Use number prefix with F, B, C, and D for repetition."
            << std::endl;
  std::cout << "  Enter Exits the current editor program" << std::endl;
}

int getActionCount(std::string &str) {
  std::string count = "";
  while (isdigit(str[0])) {
    count = count + str[0];
    str = str.substr(1);
  }
  return count == "" ? 1 : stringToInteger(count);
}
