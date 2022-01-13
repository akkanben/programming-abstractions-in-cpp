#ifndef _charstack_h
#define _charstack_h

class CharStack {
public:
  CharStack();
  ~CharStack();
  int size() const;
  bool isEmpty() const;
  void clear();
  void push(char ch);
  char pop();
  char peek() const;
  CharStack(const CharStack &src);
  CharStack &operator=(const CharStack &src);

private:
  static const int INITIAL_CAPACITY = 10;
  char *array;
  int capacity;
  int count;

  void deepCopy(const CharStack &src);
  void expandCapacity();
};

#endif
