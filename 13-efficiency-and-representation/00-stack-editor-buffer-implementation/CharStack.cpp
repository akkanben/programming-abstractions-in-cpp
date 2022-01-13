#include "CharStack.h"
#include "../../StanfordCPPLib/include/error.h"

CharStack::CharStack() {
  capacity = INITIAL_CAPACITY;
  array = new char[capacity];
  count = 0;
}

CharStack::~CharStack() { delete[] array; }

int CharStack::size() const { return count; }

bool CharStack::isEmpty() const { return count == 0; }

void CharStack::clear() { count = 0; }

void CharStack::push(char ch) {
  if (count == capacity)
    expandCapacity();
  array[count++] = ch;
}

char CharStack::pop() {
  if (isEmpty())
    error("pop: Attempting to pop an empty stack");
  return array[--count];
}

char CharStack::peek() const {
  if (isEmpty())
    error("peek: Attempting to peek at an empty stack");
  return array[count - 1];
}

CharStack::CharStack(const CharStack &src) { deepCopy(src); }

CharStack &CharStack::operator=(const CharStack &src) {
  if (this != &src) {
    delete[] array;
    deepCopy(src);
  }
  return *this;
}

void CharStack::deepCopy(const CharStack &src) {
  array = new char[src.count];
  for (int i = 0; i < src.count; i++) {
    array[i] = src.array[i];
  }
  count = src.count;
  capacity = src.capacity;
}

void CharStack::expandCapacity() {
  char *oldArray = array;
  capacity *= 2;
  array = new char[capacity];
  for (int i = 0; i < count; i++) {
    array[i] = oldArray[i];
  }
  delete[] oldArray;
}
