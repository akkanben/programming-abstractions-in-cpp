// Stack-based implementation

#include <cctype>
#include <iostream>
#include <string>

#include "DoubleCharStack.h"
#include "EditorBufferWithStack.h"

EditorBufferWithStack::EditorBufferWithStack() {}

EditorBufferWithStack::~EditorBufferWithStack() {}

void EditorBufferWithStack::moveCursorForward() {
  if (!stack.afterIsEmpty())
    stack.pushBefore(stack.popAfter());
}

void EditorBufferWithStack::moveCursorBackward() {
  if (!stack.beforeIsEmpty())
    stack.pushAfter(stack.popBefore());
}

void EditorBufferWithStack::moveCursorToStart() {
  while (!stack.beforeIsEmpty())
    stack.pushAfter(stack.popBefore());
}

void EditorBufferWithStack::moveCursorToEnd() {
  while (!stack.afterIsEmpty())
    stack.pushBefore(stack.popAfter());
}

void EditorBufferWithStack::insertCharacter(char ch) { stack.pushBefore(ch); }

void EditorBufferWithStack::deleteCharacter() {
  if (!stack.afterIsEmpty())
    stack.popAfter();
}

std::string EditorBufferWithStack::getText() const {
  DoubleCharStack stackCopy = stack;
  std::string str = "";
  while (!stackCopy.beforeIsEmpty())
    str = stackCopy.popBefore() + str;
  while (!stackCopy.afterIsEmpty())
    str = str + stackCopy.popAfter();
  return str;
}

int EditorBufferWithStack::getCursor() const { return stack.beforeSize(); }

void EditorBufferWithStack::moveCursorForwardToEndOfWord() {
  this->moveCursorForward();
  while (!stack.afterIsEmpty()) {
    if (std::isspace(stack.peekAfter()))
      break;
    this->moveCursorForward();
  }
}

void EditorBufferWithStack::moveCursorBackwardToBeginningOfWord() {
  this->moveCursorBackward();
  while (!stack.beforeIsEmpty()) {
    if (std::isspace(stack.peekBefore()))
      break;
    this->moveCursorBackward();
  }
}
void EditorBufferWithStack::deleteWord() {
  this->deleteCharacter();
  while (!stack.afterIsEmpty()) {
    if (std::isspace(stack.peekAfter()))
      break;
    this->deleteCharacter();
  }
}
