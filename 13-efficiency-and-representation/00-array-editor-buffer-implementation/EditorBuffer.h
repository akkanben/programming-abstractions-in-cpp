// Array-based implementation

#ifndef _editorbuffer_h
#define _editorbuffer_h

#include <string>

class EditorBuffer {
public:
  EditorBuffer();
  ~EditorBuffer();
  void moveCursorForward();
  void moveCursorBackward();
  void moveCursorToStart();
  void moveCursorToEnd();
  void insertCharacter(char ch);
  void deleteCharacter();
  std::string getText() const;
  int getCursor() const;

private:
  static const int INITIAL_CAPACITY = 10;

  char *array;
  int capacity;
  int length;
  int cursor;

  // Illegal to copy
  EditorBuffer(const EditorBuffer &value) {}
  const EditorBuffer &operator=(const EditorBuffer &rhs) { return *this; }

  void expandCapacity();
};

#endif
