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
  void copy(int count);
  void paste();
  bool search(std::string str);

private:
  struct Cell {
    char ch;
    Cell *link;
  };

  Cell *start;
  Cell *cursor;
  Cell *clipboardStart;
  Cell *clipboardCursor;

  // Illegal to copy
  EditorBufferWithLinkedList(const EditorBufferWithLinkedList &value) {}
  const EditorBufferWithLinkedList &
  operator=(const EditorBufferWithLinkedList &rhs) {
    return *this;
  }

  void clearClipboard();
};

#endif
