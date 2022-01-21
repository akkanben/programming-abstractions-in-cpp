// Linked-list-based implementation

#include <iostream>
#include <string>

#include "EditorBufferWithLinkedList.h"

EditorBufferWithLinkedList::EditorBufferWithLinkedList() {
  start = cursor = new Cell;
  start->link = NULL;
}

EditorBufferWithLinkedList::~EditorBufferWithLinkedList() {
  Cell *cp = start;
  while (cp != NULL) {
    Cell *next = cp->link;
    delete cp;
    cp = next;
  }
}

void EditorBufferWithLinkedList::moveCursorForward() {
  if (cursor->link != NULL)
    cursor = cursor->link;
}

void EditorBufferWithLinkedList::moveCursorBackward() {
  Cell *cp = start;
  if (cursor != start) {
    while (cp->link != cursor)
      cp = cp->link;
  }
  cursor = cp;
}

void EditorBufferWithLinkedList::moveCursorToStart() { cursor = start; }

void EditorBufferWithLinkedList::moveCursorToEnd() {
  while (cursor->link != NULL)
    cursor = cursor->link;
}

void EditorBufferWithLinkedList::insertCharacter(char ch) {
  Cell *cp = new Cell;
  cp->ch = ch;
  cp->link = cursor->link;
  cursor->link = cp;
  cursor = cp;
}

void EditorBufferWithLinkedList::deleteCharacter() {
  if (cursor->link != NULL) {
    Cell *oldCell = cursor->link;
    cursor->link = cursor->link->link;
    delete oldCell;
  }
}

std::string EditorBufferWithLinkedList::getText() const {
  std::string str = "";
  for (Cell *cp = start->link; cp != NULL; cp = cp->link)
    str += cp->ch;
  return str;
}

int EditorBufferWithLinkedList::getCursor() const {
  int nChars = 0;
  for (Cell *cp = start; cp != cursor; cp = cp->link)
    nChars++;
  return nChars;
}
void EditorBufferWithLinkedList::moveCursorForwardToEndOfWord() {
  this->moveCursorForward();
  while (cursor->link != NULL) {
    if (std::isspace(cursor->link->ch))
      break;
    this->moveCursorForward();
  }
}

void EditorBufferWithLinkedList::moveCursorBackwardToBeginningOfWord() {
  this->moveCursorBackward();
  while (cursor != start) {
    if (std::isspace(cursor->ch))
      break;
    this->moveCursorBackward();
  }
}

void EditorBufferWithLinkedList::deleteWord() {
  this->deleteCharacter();
  while (cursor->link != NULL) {
    if (std::isspace(cursor->link->ch))
      break;
    this->deleteCharacter();
  }
}
