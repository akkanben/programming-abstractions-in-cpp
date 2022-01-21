// Linked-list-based implementation

#ifndef _editorbufferwithlinkedlist_h
#define _editorbufferwithlinkedlist_h

#include <string>

class EditorBufferWithLinkedList {
public:
  EditorBufferWithLinkedList();
  ~EditorBufferWithLinkedList();
  void moveCursorForward();
  void moveCursorBackward();
  void moveCursorToStart();
  void moveCursorToEnd();
  void insertCharacter(char ch);
  void deleteCharacter();
  std::string getText() const;
  int getCursor() const;

  void moveCursorForwardToEndOfWord();
  void moveCursorBackwardToBeginningOfWord();
  void deleteWord();

private:
  struct Cell {
    char ch;
    Cell *link;
  };

  Cell *start;
  Cell *cursor;

  // Illegal to copy
  EditorBufferWithLinkedList(const EditorBufferWithLinkedList &value) {}
  const EditorBufferWithLinkedList &
  operator=(const EditorBufferWithLinkedList &rhs) {
    return *this;
  }
};

#endif
