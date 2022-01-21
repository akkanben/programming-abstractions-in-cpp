
#include "DoubleCharStack.h"
#include "../../StanfordCPPLib/include/error.h"

DoubleCharStack::DoubleCharStack() {
  capacity = INITIAL_CAPACITY;
  array = new char[capacity];
  count = 0;
  beforeCount = 0;
  afterCount = 0;
}

DoubleCharStack::~DoubleCharStack() { delete[] array; }

int DoubleCharStack::size() const { return count; }
int DoubleCharStack::beforeSize() const { return beforeCount; }
int DoubleCharStack::afterSize() const { return afterCount; }

bool DoubleCharStack::isEmpty() const { return count == 0; }
bool DoubleCharStack::beforeIsEmpty() const { return beforeCount == 0; }
bool DoubleCharStack::afterIsEmpty() const { return afterCount == 0; }

void DoubleCharStack::clear() {
  count = 0;
  beforeCount = 0;
  afterCount = 0;
}

void DoubleCharStack::pushBefore(char ch) {
  if (count == capacity)
    expandCapacity();
  array[beforeCount++] = ch;
  count++;
}

void DoubleCharStack::pushAfter(char ch) {
  if (count == capacity)
    expandCapacity();
  array[capacity - ++afterCount] = ch;
  count++;
}

char DoubleCharStack::popBefore() {
  if (beforeCount == 0)
    error("pop: Attempting to pop an empty stack");
  count--;
  return array[--beforeCount];
}

char DoubleCharStack::popAfter() {
  if (afterCount == -1)
    error("pop: Attempting to pop an empty stack");
  count--;
  return array[capacity - afterCount--];
}

char DoubleCharStack::peekBefore() const {
  if (beforeCount == 0)
    error("peek: Attempting to peek at an empty stack");
  return array[beforeCount - 1];
}

char DoubleCharStack::peekAfter() const {
  if (afterCount == 0)
    error("peek: Attempting to peek at an empty stack");
  return array[capacity - afterCount];
}

DoubleCharStack::DoubleCharStack(const DoubleCharStack &src) { deepCopy(src); }

DoubleCharStack &DoubleCharStack::operator=(const DoubleCharStack &src) {
  if (this != &src) {
    delete[] array;
    deepCopy(src);
  }
  return *this;
}

void DoubleCharStack::deepCopy(const DoubleCharStack &src) {
  array = new char[src.capacity];
  for (int i = 0; i < src.capacity; i++) {
    array[i] = src.array[i];
  }
  count = src.count;
  beforeCount = src.beforeCount;
  afterCount = src.afterCount;
  capacity = src.capacity;
}

// copy the front of the array then copy the back of the array to the end of the
// new capacity.
void DoubleCharStack::expandCapacity() {
  char *oldArray = array;
  capacity *= 2;
  array = new char[capacity];
  for (int i = 0; i < beforeCount; i++)
    array[i] = oldArray[i];
  for (int i = 0; i < afterCount; i++)
    array[capacity - i - 1] = oldArray[count - i - 1];
  delete[] oldArray;
}
