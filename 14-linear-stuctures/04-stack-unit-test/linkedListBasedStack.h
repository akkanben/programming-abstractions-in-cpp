#ifndef _linkedlistedbasedstack_h
#define _linkedlistedbasedstack_h

#include "../../StanfordCPPLib/include/error.h"

template <typename ValueType> class LinkedListBasedStack {
public:
  LinkedListBasedStack();
  ~LinkedListBasedStack();
  int size() const;
  bool isEmpty() const;
  void clear();
  void push(ValueType value);
  ValueType pop();
  ValueType peek() const;
  LinkedListBasedStack(const LinkedListBasedStack<ValueType> &src);
  LinkedListBasedStack<ValueType> &
  operator=(const LinkedListBasedStack<ValueType> &src);

private:
  struct Cell {
    ValueType data;
    Cell *link;
  };
  Cell *list;
  int count;
  void deepCopy(const LinkedListBasedStack<ValueType> &src);
};

template <typename ValueType>
LinkedListBasedStack<ValueType>::LinkedListBasedStack() {
  list = NULL;
  count = 0;
}

template <typename ValueType>
LinkedListBasedStack<ValueType>::~LinkedListBasedStack() {
  clear();
}

template <typename ValueType>
int LinkedListBasedStack<ValueType>::size() const {
  return count;
}

template <typename ValueType>
bool LinkedListBasedStack<ValueType>::isEmpty() const {
  return count == 0;
}

template <typename ValueType> void LinkedListBasedStack<ValueType>::clear() {
  while (count > 0) {
    pop();
  }
}

template <typename ValueType>
void LinkedListBasedStack<ValueType>::push(ValueType value) {
  Cell *cp = new Cell;
  cp->data = value;
  cp->link = list;
  list = cp;
  count++;
}

template <typename ValueType> ValueType LinkedListBasedStack<ValueType>::pop() {
  if (isEmpty())
    error("pop: Attempting to pop an empty stack");
  Cell *cp = list;
  ValueType result = cp->data;
  list = list->link;
  count--;
  delete cp;
  return result;
}

template <typename ValueType>
ValueType LinkedListBasedStack<ValueType>::peek() const {
  if (isEmpty())
    error("peek: Attempting to peek at an empty stack");
  return list->data;
}

template <typename ValueType>
LinkedListBasedStack<ValueType>::LinkedListBasedStack(
    const LinkedListBasedStack<ValueType> &src) {
  deepCopy(src);
}

template <typename ValueType>
LinkedListBasedStack<ValueType> &LinkedListBasedStack<ValueType>::operator=(
    const LinkedListBasedStack<ValueType> &src) {
  if (this != &src) {
    clear();
    deepCopy(src);
  }
  return *this;
}

#endif
