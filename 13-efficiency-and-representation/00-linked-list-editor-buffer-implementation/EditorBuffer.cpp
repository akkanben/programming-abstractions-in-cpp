// Linked-list-based implementation

#include <iostream>
#include <string>

#include "EditorBuffer.h"

EditorBuffer::EditorBuffer() {
  start = cursor = new Cell;
  start->link = NULL;
}

EditorBuffer::~EditorBuffer() {
  Cell *cp = start;
  while (cp != NULL) {
    Cell *next = cp->link;
    delete cp;
    cp = next;
  }
}

void EditorBuffer::moveCursorForward() {
  if (cursor->link != NULL)
    cursor = cursor->link;
}

void EditorBuffer::moveCursorBackward() {
  Cell *cp = start;
  if (cursor != start) {
    while (cp->link != cursor)
      cp = cp->link;
  }
  cursor = cp;
}

void EditorBuffer::moveCursorToStart() { cursor = start; }

void EditorBuffer::moveCursorToEnd() {
  while (cursor->link != NULL)
    cursor = cursor->link;
}

void EditorBuffer::insertCharacter(char ch) {
  Cell *cp = new Cell;
  cp->ch = ch;
  cp->link = cursor->link;
  cursor->link = cp;
  cursor = cp;
}

void EditorBuffer::deleteCharacter() {
  if (cursor->link != NULL) {
    Cell *oldCell = cursor->link;
    cursor->link = cursor->link->link;
    delete oldCell;
  }
}

std::string EditorBuffer::getText() const {
  std::string str = "";
  for (Cell *cp = start->link; cp != NULL; cp = cp->link)
    str += cp->ch;
  return str;
}

int EditorBuffer::getCursor() const {
  int nChars = 0;
  for (Cell *cp = start; cp != cursor; cp = cp->link)
    nChars++;
  return nChars;
}
