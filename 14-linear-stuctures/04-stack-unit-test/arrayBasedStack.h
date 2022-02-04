#ifndef _arraybasedstack_h
#define _arraybasedstack_h

#include "../../StanfordCPPLib/include/error.h"

template <typename ValueType> class ArrayBasedStack {
public:
  ArrayBasedStack();
  ~ArrayBasedStack();
  int size() const;
  bool isEmpty() const;
  void clear();
  void push(ValueType value);
  ValueType pop();
  ValueType peek() const;
  ArrayBasedStack(const ArrayBasedStack<ValueType> &src);
  ArrayBasedStack<ValueType> &operator=(const ArrayBasedStack<ValueType> &src);

private:
  static const int INITIAL_CAPACITY = 10;

  ValueType *array;
  int capacity;
  int count;

  void deepCopy(const ArrayBasedStack<ValueType> &src);
  void expandCapacity();
};

template <typename ValueType> ArrayBasedStack<ValueType>::ArrayBasedStack() {
  capacity = INITIAL_CAPACITY;
  array = new ValueType[capacity];
  count = 0;
}

template <typename ValueType> ArrayBasedStack<ValueType>::~ArrayBasedStack() {
  delete[] array;
}

template <typename ValueType> int ArrayBasedStack<ValueType>::size() const {
  return count;
}

template <typename ValueType> bool ArrayBasedStack<ValueType>::isEmpty() const {
  return count == 0;
}

template <typename ValueType> void ArrayBasedStack<ValueType>::clear() {
  count = 0;
}

template <typename ValueType>
void ArrayBasedStack<ValueType>::push(ValueType value) {
  if (count == capacity)
    expandCapacity();
  array[count++] = value;
}

template <typename ValueType> ValueType ArrayBasedStack<ValueType>::pop() {
  if (isEmpty())
    error("pop: Attempting to pop an empty stack");
  return array[--count];
}

template <typename ValueType>
ValueType ArrayBasedStack<ValueType>::peek() const {
  if (isEmpty())
    error("peek: Attempting to peek at an empty stack");
  return array[count - 1];
}

template <typename ValueType>
ArrayBasedStack<ValueType>::ArrayBasedStack(
    const ArrayBasedStack<ValueType> &src) {
  deepCopy(src);
}

template <typename ValueType>
ArrayBasedStack<ValueType> &
ArrayBasedStack<ValueType>::operator=(const ArrayBasedStack<ValueType> &src) {
  if (this != &src) {
    delete[] array;
    deepCopy(src);
  }
  return *this;
}

template <typename ValueType>
void ArrayBasedStack<ValueType>::deepCopy(
    const ArrayBasedStack<ValueType> &src) {
  capacity = src.count + INITIAL_CAPACITY;
  this->array = new ValueType[capacity];
  for (int i = 0; i < src.count; i++)
    array[i] = src.array[i];
  count = src.count;
}

template <typename ValueType>
void ArrayBasedStack<ValueType>::expandCapacity() {
  ValueType *oldArray = array;
  capacity *= 2;
  array = new ValueType[capacity];
  for (int i = 0; i < count; i++)
    array[i] = oldArray[i];
  delete[] oldArray;
}

#endif
