// Array-based implementation

#ifndef _editorbufferwitharray_h
#define _editorbufferwitharray_h

#include <string>

class EditorBufferWithArray {
public:
  EditorBufferWithArray();
  ~EditorBufferWithArray();
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
  static const int INITIAL_CAPACITY = 10;

  char *array;
  char *clipboard;
  int clipboardLength;
  int capacity;
  int length;
  int cursor;

  // Illegal to copy
  EditorBufferWithArray(const EditorBufferWithArray &value) {}
  const EditorBufferWithArray &operator=(const EditorBufferWithArray &rhs) {
    return *this;
  }

  void expandCapacity();
};

#endif
