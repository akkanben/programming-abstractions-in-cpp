// Linked-list-based implementation

#include <iostream>
#include <string>

#include "EditorBufferWithLinkedList.h"

EditorBufferWithLinkedList::EditorBufferWithLinkedList() {
  start = cursor = new Cell;
  start->next = NULL;
  start->previous = NULL;
}

EditorBufferWithLinkedList::~EditorBufferWithLinkedList() {
  Cell *cp = start;
  while (cp != NULL) {
    Cell *temp = cp->next;
    delete cp;
    cp = temp;
  }
}

void EditorBufferWithLinkedList::moveCursorForward() {
  if (cursor->next != NULL)
    cursor = cursor->next;
}

void EditorBufferWithLinkedList::moveCursorBackward() {
  if (cursor != start)
    cursor = cursor->previous;
}

void EditorBufferWithLinkedList::moveCursorToStart() { cursor = start; }

void EditorBufferWithLinkedList::moveCursorToEnd() {
  while (cursor->next != NULL)
    cursor = cursor->next;
}

void EditorBufferWithLinkedList::insertCharacter(char ch) {
  Cell *cp = new Cell;
  cp->ch = ch;
  cp->next = cursor->next;
  cp->previous = cursor;
  cursor->next = cp;
  cursor = cp;
}

void EditorBufferWithLinkedList::deleteCharacter() {
  if (cursor->next != NULL) {
    Cell *oldCell = cursor->next;
    cursor->next = cursor->next->next;
    delete oldCell;
  }
}

std::string EditorBufferWithLinkedList::getText() const {
  std::string str = "";
  for (Cell *cp = start->next; cp != NULL; cp = cp->next)
    str += cp->ch;
  return str;
}

int EditorBufferWithLinkedList::getCursor() const {
  int nChars = 0;
  for (Cell *cp = start; cp != cursor; cp = cp->next)
    nChars++;
  return nChars;
}
void EditorBufferWithLinkedList::moveCursorForwardToEndOfWord() {
  this->moveCursorForward();
  while (cursor->next != NULL) {
    if (std::isspace(cursor->next->ch))
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
  while (cursor->next != NULL) {
    if (std::isspace(cursor->next->ch))
      break;
    this->deleteCharacter();
  }
}

void EditorBufferWithLinkedList::clearClipboard() {
  Cell *cp = clipboardStart;
  while (cp->next != NULL) {
    Cell *temp = cp->next;
    delete cp;
    cp = temp;
  }
}

void EditorBufferWithLinkedList::copy(int count) {
  this->clearClipboard();
  clipboardStart = clipboardCursor = new Cell;
  clipboardStart->next = NULL;
  int i = count;
  while (cursor->next != NULL) {
    if (i-- > 0) {
      Cell *cp = new Cell;
      cp->ch = cursor->next->ch;
      cp->next = clipboardCursor->next;
      clipboardCursor->next = cp;
      clipboardCursor = cp;
      cursor = cursor->next;
    } else
      break;
  }
  while (count-- > 0)
    this->moveCursorBackward();
}

void EditorBufferWithLinkedList::paste() {
  clipboardCursor = clipboardStart;
  while (clipboardCursor->next != NULL) {
    this->insertCharacter(clipboardCursor->next->ch);
    clipboardCursor = clipboardCursor->next;
  }
}

bool EditorBufferWithLinkedList::search(std::string str) {
  Cell *tempCursor = cursor->next;
  while (tempCursor != NULL) {
    int pos = 0;
    if (tempCursor->ch == str[pos]) {
      while (tempCursor->ch == str[pos++]) {
        if (pos == str.length()) {
          cursor = tempCursor;
          return true;
        }
        tempCursor = tempCursor->next;
      }
    }
    tempCursor = tempCursor->next;
  }
  return false;
}
