// Stack-based implementation

#include <iostream>
#include <string>

#include "CharStack.h"
#include "EditorBuffer.h"

EditorBuffer::EditorBuffer() {}

EditorBuffer::~EditorBuffer() {}

void EditorBuffer::moveCursorForward() {
  if (!after.isEmpty())
    before.push(after.pop());
}

void EditorBuffer::moveCursorBackward() {
  if (!before.isEmpty())
    after.push(before.pop());
}

void EditorBuffer::moveCursorToStart() {
  while (!before.isEmpty())
    after.push(before.pop());
}

void EditorBuffer::moveCursorToEnd() {
  while (!after.isEmpty())
    before.push(after.pop());
}

void EditorBuffer::insertCharacter(char ch) { before.push(ch); }

void EditorBuffer::deleteCharacter() {
  if (!after.isEmpty())
    after.pop();
}

std::string EditorBuffer::getText() const {
  CharStack beforeCopy = before;
  CharStack afterCopy = after;
  std::string str = "";
  while (!beforeCopy.isEmpty())
    str = beforeCopy.pop() + str;
  while (!afterCopy.isEmpty())
    str += afterCopy.pop();
  return str;
}

int EditorBuffer::getCursor() const { return before.size(); }
