#include <cctype>
#include <iostream>

#include "../../StanfordCPPLib/include/foreach.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "EditorBufferWithLinkedList.h"

void executeCommand(EditorBufferWithLinkedList &linkedListBuffer,
                    std::string line, bool wordFlag);
void displayBuffer(EditorBufferWithLinkedList &linkedListBuffer);
void printLinkedListHelpText();
int getLinkedListActionCount(std::string &str);
void replaceLinkedList(std::string str);

EditorBufferWithLinkedList linkedListBuffer;

int main() {
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
  int count = getLinkedListActionCount(line);
  switch (toupper(line[0])) {
  case 'I':
    line = line.substr(1);
    foreach (char ch in line) { linkedListBuffer.insertCharacter(ch); }
    displayBuffer(linkedListBuffer);
    break;
  case 'D':
    while (count-- > 0) {
      if (wordFlag)
        linkedListBuffer.deleteWord();
      else
        linkedListBuffer.deleteCharacter();
    }
    displayBuffer(linkedListBuffer);
    break;
  case 'F':
    while (count-- > 0) {
      if (wordFlag)
        linkedListBuffer.moveCursorForwardToEndOfWord();
      else
        linkedListBuffer.moveCursorForward();
    }
    displayBuffer(linkedListBuffer);
    break;
  case 'B':
    while (count-- > 0) {
      if (wordFlag)
        linkedListBuffer.moveCursorBackwardToBeginningOfWord();
      else
        linkedListBuffer.moveCursorBackward();
    }
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
    printLinkedListHelpText();
    break;
  case 'W':
    executeCommand(linkedListBuffer, line.substr(1), true);
    break;
  case 'C':
    linkedListBuffer.copy(count);
    break;
  case 'X':
    linkedListBuffer.copy(count);
    while (count-- > 0)
      linkedListBuffer.deleteCharacter();
    displayBuffer(linkedListBuffer);
    break;
  case 'P':
    while (count-- > 0) {
      linkedListBuffer.paste();
    }
    displayBuffer(linkedListBuffer);
    break;
  case 'S':
    if (!linkedListBuffer.search(line.substr(1)))
      std::cout << "Search Failed." << std::endl;
    displayBuffer(linkedListBuffer);
    break;
  case 'R':
    replaceLinkedList(line.substr(1));
    displayBuffer(linkedListBuffer);
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

int getLinkedListActionCount(std::string &str) {
  std::string count = "";
  while (isdigit(str[0])) {
    count = count + str[0];
    str = str.substr(1);
  }
  return count == "" ? 1 : stringToInteger(count);
}

void replaceLinkedList(std::string str) {
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
  if (linkedListBuffer.search(before)) {
    int count = before.length();
    while (count-- > 0)
      linkedListBuffer.moveCursorBackward();
    count = before.length();
    while (count-- > 0)
      linkedListBuffer.deleteCharacter();
    for (int i = 0; i < after.length(); i++)
      linkedListBuffer.insertCharacter(after[i]);
  }
}
