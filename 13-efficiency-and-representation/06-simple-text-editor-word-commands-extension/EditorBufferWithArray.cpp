// Array-based implementation

#include <iostream>
#include <string>

#include "EditorBufferWithArray.h"

EditorBufferWithArray::EditorBufferWithArray() {
  capacity = INITIAL_CAPACITY;
  array = new char[capacity];
  length = 0;
  cursor = 0;
}

EditorBufferWithArray::~EditorBufferWithArray() { delete[] array; }

void EditorBufferWithArray::moveCursorForward() {
  if (cursor < length)
    cursor++;
}

void EditorBufferWithArray::moveCursorBackward() {
  if (cursor > 0)
    cursor--;
}

void EditorBufferWithArray::moveCursorToStart() { cursor = 0; }

void EditorBufferWithArray::moveCursorToEnd() { cursor = length; }

void EditorBufferWithArray::insertCharacter(char ch) {
  if (length == capacity)
    expandCapacity();
  for (int i = length; i > cursor; i--) {
    array[i] = array[i - 1];
  }
  array[cursor] = ch;
  length++;
  cursor++;
}

void EditorBufferWithArray::deleteCharacter() {
  if (cursor < length) {
    for (int i = cursor + 1; i < length; i++) {
      array[i - 1] = array[i];
    }
    length--;
  }
}

std::string EditorBufferWithArray::getText() const {
  return std::string(array, length);
}

int EditorBufferWithArray::getCursor() const { return cursor; }

void EditorBufferWithArray::expandCapacity() {
  char *oldArray = array;
  capacity *= 2;
  array = new char[capacity];
  for (int i = 0; i < length; i++) {
    array[i] = oldArray[i];
  }
  delete[] oldArray;
}

void EditorBufferWithArray::moveCursorForwardToEndOfWord() {
  this->moveCursorForward();
  while (cursor < length) {
    if (std::isspace(array[cursor]))
      break;
    this->moveCursorForward();
  }
}

void EditorBufferWithArray::moveCursorBackwardToBeginningOfWord() {
  this->moveCursorBackward();
  while (cursor > 0) {
    if (std::isspace(array[cursor - 1]))
      break;
    this->moveCursorBackward();
  }
}
void EditorBufferWithArray::deleteWord() {
  this->deleteCharacter();
  while (cursor < length) {
    if (std::isspace(array[cursor]))
      break;
    this->deleteCharacter();
  }
}
