// Stack-based implementation

#include <iostream>
#include <string>

#include "DoubleCharStack.h"
#include "EditorBuffer.h"

EditorBuffer::EditorBuffer() {}

EditorBuffer::~EditorBuffer() {}

void EditorBuffer::moveCursorForward() {
  if (!stack.afterIsEmpty())
    stack.pushBefore(stack.popAfter());
}

void EditorBuffer::moveCursorBackward() {
  if (!stack.beforeIsEmpty())
    stack.pushAfter(stack.popBefore());
}

void EditorBuffer::moveCursorToStart() {
  while (!stack.beforeIsEmpty())
    stack.pushAfter(stack.popBefore());
}

void EditorBuffer::moveCursorToEnd() {
  while (!stack.afterIsEmpty())
    stack.pushBefore(stack.popAfter());
}

void EditorBuffer::insertCharacter(char ch) { stack.pushBefore(ch); }

void EditorBuffer::deleteCharacter() {
  if (!stack.afterIsEmpty())
    stack.popAfter();
}

std::string EditorBuffer::getText() const {
  DoubleCharStack stackCopy = stack;
  std::string str = "";
  while (!stackCopy.beforeIsEmpty())
    str = stackCopy.popBefore() + str;
  while (!stackCopy.afterIsEmpty())
    str = str + stackCopy.popAfter();
  return str;
}

int EditorBuffer::getSize() const { return stack.size(); }

int EditorBuffer::getCursor() const { return stack.beforeSize(); }
