// Stack-based implementation

#ifndef _editorbuffer_h
#define _editorbuffer_h

#include "DoubleCharStack.h"
#include <string>

class EditorBufferWithStack {
public:
  EditorBufferWithStack();
  ~EditorBufferWithStack();
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

  DoubleCharStack stack;
  DoubleCharStack clipboard;

  // Illegal to copy
  EditorBufferWithStack(const EditorBufferWithStack &value) {}
  const EditorBufferWithStack &operator=(const EditorBufferWithStack &rhs) {
    return *this;
  }
};

#endif
