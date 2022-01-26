#include <cctype>
#include <iostream>

#include "../../StanfordCPPLib/include/foreach.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "EditorBufferWithStack.h"

void executeCommand(EditorBufferWithStack &stackBuffer, std::string line,
                    bool wordFlag);
void displayBuffer(EditorBufferWithStack &stackBuffer);
void printStackHelpText();
int getStackActionCount(std::string &str);
void replaceStack(std::string str);

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
  int count = getStackActionCount(line);
  switch (toupper(line[0])) {
  case 'I':
    line = line.substr(1);
    foreach (char ch in line) { stackBuffer.insertCharacter(ch); }
    displayBuffer(stackBuffer);
    break;
  case 'D':
    while (count-- > 0) {
      if (wordFlag)
        stackBuffer.deleteWord();
      else
        stackBuffer.deleteCharacter();
    }
    displayBuffer(stackBuffer);
    break;
  case 'F':
    while (count-- > 0) {
      if (wordFlag)
        stackBuffer.moveCursorForwardToEndOfWord();
      else
        stackBuffer.moveCursorForward();
    }
    displayBuffer(stackBuffer);
    break;
  case 'B':
    while (count-- > 0) {
      if (wordFlag)
        stackBuffer.moveCursorBackwardToBeginningOfWord();
      else
        stackBuffer.moveCursorBackward();
    }
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
  case 'C':
    stackBuffer.copy(count);
    break;
  case 'X':
    stackBuffer.copy(count);
    while (count-- > 0)
      stackBuffer.deleteCharacter();
    displayBuffer(stackBuffer);
    break;
  case 'P':
    while (count-- > 0) {
      stackBuffer.paste();
    }
    displayBuffer(stackBuffer);
    break;
  case 'R':
    replaceStack(line.substr(1));
    displayBuffer(stackBuffer);
    break;
  case 'S':
    if (!stackBuffer.search(line.substr(1)))
      std::cout << "Search Failed." << std::endl;
    displayBuffer(stackBuffer);
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
  std::cout << "  Iabc      Inserts the characters abc at the cursor position"
            << std::endl;
  std::cout << "  Sabc      Searches forward for characters abc" << std::endl;
  std::cout << "  F         Moves the curosr forward one character"
            << std::endl;
  std::cout << "  B         Moves the curosr backward one character"
            << std::endl;
  std::cout << "  D         Deletes the character after the cursor"
            << std::endl;
  std::cout << "  C         Copies character under the cursor" << std::endl;
  std::cout << "  X         Cuts character under the cursor" << std::endl;
  std::cout << "  P         Pastes characters that have been saved to memory"
            << std::endl;
  std::cout << "  Rabc/def  Replaces abc with def, must use slash "
            << std::endl;
  std::cout << "  J         Jumps to the beginning of the buffer" << std::endl;
  std::cout << "  E         Jumps to the end of the buffer" << std::endl;
  std::cout << "  H         Prints this message" << std::endl;
  std::cout << "  W         Indicate a word motion (used with F,B and D)"
            << std::endl;
  std::cout
      << "  #         Use number prefix with F, B, C, X, and D for repetition."
      << std::endl;
  std::cout << "  Enter     Exits the current editor program" << std::endl;
}

int getStackActionCount(std::string &str) {
  std::string count = "";
  while (isdigit(str[0])) {
    count = count + str[0];
    str = str.substr(1);
  }
  return count == "" ? 1 : stringToInteger(count);
}

void replaceStack(std::string str) {
  std::string before;
  std::string after;
  bool beforeSlash = true;
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if (ch == '/')
      beforeSlash = false;
    else if (beforeSlash)
      before += str[i];
    else
      after += str[i];
  }
  if (beforeSlash)
    std::cout << "Must use slash for replace" << std::endl;
  if (stackBuffer.search(before)) {
    int count = before.length();
    while (count-- > 0)
      stackBuffer.moveCursorBackward();
    count = before.length();
    while (count-- > 0)
      stackBuffer.deleteCharacter();
    for (int i = 0; i < after.length(); i++)
      stackBuffer.insertCharacter(after[i]);
  }
}
