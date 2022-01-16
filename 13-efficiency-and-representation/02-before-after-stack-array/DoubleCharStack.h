#ifndef _doublecharstack_h
#define _doublecharstack_h

class DoubleCharStack {
public:
  DoubleCharStack();
  ~DoubleCharStack();
  int size() const;
  void print() const;
  int beforeSize() const;
  int afterSize() const;
  bool isEmpty() const;
  bool beforeIsEmpty() const;
  bool afterIsEmpty() const;
  void clear();
  void pushBefore(char ch);
  void pushAfter(char ch);
  char popBefore();
  char popAfter();
  char peekBefore() const;
  char peekAfter() const;
  DoubleCharStack(const DoubleCharStack &src);
  DoubleCharStack &operator=(const DoubleCharStack &src);

private:
  static const int INITIAL_CAPACITY = 10;
  char *array;
  int capacity;
  int beforeCount;
  int afterCount;
  int count;

  void deepCopy(const DoubleCharStack &src);
  void expandCapacity();
};

#endif
