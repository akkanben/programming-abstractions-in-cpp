/* Programming Abstractions in C++
 *
 * Exercise 13-11
 *
 * The dummy cell strategy described in the text is useful because it reduces
 * the number of special cases in the code, but it is not strictly necessary.
 * Write a new implementation of linked-list version of buffer.cpp in which you
 * make the following changes:
 *
 *  • The linked list contains no dummy cell—just a cell for every character.
 *  • A buffer in which the cursor occurs before the first character is
 *    indicated by storing NULL in the cursor field.
 *  • Every method that checks the
 *    position of the cursor makes a special test for NULL and performs whatever
 *    special actions are necessary in that case.
 *
 *
 * Solution 2021 Ben Mills
 */

#include <cstddef>
#include <iostream>
#include <string>

#include "EditorBufferWithLinkedList.h"

EditorBufferWithLinkedList::EditorBufferWithLinkedList() {}

EditorBufferWithLinkedList::~EditorBufferWithLinkedList() {
  Cell *cp = start;
  while (cp != NULL) {
    Cell *next = cp->link;
    delete cp;
    cp = next;
  }
}

void EditorBufferWithLinkedList::moveCursorForward() {
  if (cursor == NULL)
    cursor = start;
  else if (cursor->link != NULL)
    cursor = cursor->link;
}

void EditorBufferWithLinkedList::moveCursorBackward() {
  Cell *cp = start;
  if (cursor == start)
    cursor = NULL;
  else if (cursor != NULL) {
    while (cp->link != cursor)
      cp = cp->link;
    cursor = cp;
  }
}

void EditorBufferWithLinkedList::moveCursorToStart() { cursor = NULL; }

void EditorBufferWithLinkedList::moveCursorToEnd() {
  if (start != NULL) {
    if (cursor == NULL)
      cursor = start;
    while (cursor->link != NULL)
      cursor = cursor->link;
  }
}

void EditorBufferWithLinkedList::insertCharacter(char ch) {
  Cell *cp = new Cell;
  cp->ch = ch;
  if (cursor == NULL) {
    cp->link = start;
    start = cp;
  } else {
    cp->link = cursor->link;
    cursor->link = cp;
  }
  cursor = cp;
}

void EditorBufferWithLinkedList::deleteCharacter() {
  Cell *oldCell;
  if (start != NULL) {
    if (cursor == NULL) {
      oldCell = start;
      start = start->link;
      delete oldCell;
    } else if (cursor->link != NULL) {
      oldCell = cursor->link;
      cursor->link = cursor->link->link;
      delete oldCell;
    }
  }
}

std::string EditorBufferWithLinkedList::getText() const {
  std::string str = "";
  for (Cell *cp = start; cp != NULL; cp = cp->link)
    str += cp->ch;
  return str;
}

int EditorBufferWithLinkedList::getCursor() const {
  int nChars = 1;
  if (cursor == NULL)
    return 0;
  for (Cell *cp = start; cp != cursor; cp = cp->link)
    nChars++;
  return nChars;
}
void EditorBufferWithLinkedList::moveCursorForwardToEndOfWord() {
  if (start != NULL) {
    this->moveCursorForward();
    while (cursor->link != NULL) {
      if (std::isspace(cursor->link->ch))
        break;
      this->moveCursorForward();
    }
  }
}

void EditorBufferWithLinkedList::moveCursorBackwardToBeginningOfWord() {
  if (start != NULL) {
    this->moveCursorBackward();
    while (cursor != NULL) {
      if (std::isspace(cursor->ch))
        break;
      this->moveCursorBackward();
    }
  }
}

void EditorBufferWithLinkedList::deleteWord() {
  if (start != NULL) {
    this->deleteCharacter();
    if (cursor == NULL) {
      while (start != NULL && !std::isspace(start->ch))
        this->deleteCharacter();
    } else {
      while (cursor->link != NULL) {
        if (std::isspace(cursor->link->ch))
          break;
        this->deleteCharacter();
      }
    }
  }
}

void EditorBufferWithLinkedList::clearClipboard() {
  Cell *cp = clipboardStart;
  while (cp != NULL) {
    Cell *next = cp->link;
    delete cp;
    cp = next;
  }
}

void EditorBufferWithLinkedList::copy(int count) {
  clearClipboard();
  clipboardStart = clipboardCursor = new Cell;
  clipboardStart->link = NULL;
  int i = count;
  while (cursor->link != NULL) {
    if (i-- > 0) {
      Cell *cp = new Cell;
      cp->ch = cursor->link->ch;
      cp->link = clipboardCursor->link;
      clipboardCursor->link = cp;
      clipboardCursor = cp;
      cursor = cursor->link;
    } else
      break;
  }
  while (count-- > 0)
    this->moveCursorBackward();
}

void EditorBufferWithLinkedList::paste() {
  clipboardCursor = clipboardStart;
  while (clipboardCursor->link != NULL) {
    this->insertCharacter(clipboardCursor->link->ch);
    clipboardCursor = clipboardCursor->link;
  }
}

bool EditorBufferWithLinkedList::search(std::string str) {
  Cell *tempCursor;
  if (cursor == NULL)
    tempCursor = start;
  else
    tempCursor = cursor;
  while (tempCursor != NULL) {
    int pos = 0;
    if (tempCursor->ch == str[pos]) {
      while (tempCursor->ch == str[pos++]) {
        if (pos == str.length()) {
          cursor = tempCursor;
          return true;
        }
        tempCursor = tempCursor->link;
      }
    }
    tempCursor = tempCursor->link;
  }
  return false;
}
