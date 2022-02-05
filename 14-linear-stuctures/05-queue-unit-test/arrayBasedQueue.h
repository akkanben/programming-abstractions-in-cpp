#ifndef _arraybasedqueue_h
#define _arraybasedqueue_h

#include "../../StanfordCPPLib/include/error.h"

template <typename ValueType> class ArrayBasedQueue {
public:
  ArrayBasedQueue();
  ~ArrayBasedQueue();
  int size() const;
  bool isEmpty() const;
  void clear();
  void enqueue(ValueType value);
  ValueType dequeue();
  ValueType peek() const;
  ArrayBasedQueue(const ArrayBasedQueue<ValueType> &src);
  ArrayBasedQueue<ValueType> &operator=(const ArrayBasedQueue<ValueType> &src);

private:
  static const int INITIAL_CAPACITY = 10;
  ValueType *array;
  int capacity;
  int head;
  int tail;

  void deepCopy(const ArrayBasedQueue<ValueType> &src);
  void expandCapacity();
};

template <typename ValueType> ArrayBasedQueue<ValueType>::ArrayBasedQueue() {
  capacity = INITIAL_CAPACITY;
  array = new ValueType[capacity];
  head = 0;
  tail = 0;
}

template <typename ValueType> ArrayBasedQueue<ValueType>::~ArrayBasedQueue() {
  delete[] array;
}

template <typename ValueType> int ArrayBasedQueue<ValueType>::size() const {
  return (tail + capacity - head) % capacity;
}

template <typename ValueType> bool ArrayBasedQueue<ValueType>::isEmpty() const {
  return head == tail;
}

template <typename ValueType> void ArrayBasedQueue<ValueType>::clear() {
  head = tail = 0;
}

template <typename ValueType>
void ArrayBasedQueue<ValueType>::enqueue(ValueType value) {
  if (size() == capacity - 1)
    expandCapacity();
  array[tail] = value;
  tail = (tail + 1) % capacity;
}

template <typename ValueType> ValueType ArrayBasedQueue<ValueType>::dequeue() {
  if (isEmpty())
    error("dequeue: Attempting to dequeue an empty queue");
  ValueType result = array[head];
  head = (head + 1) % capacity;
  return result;
}

template <typename ValueType>
ValueType ArrayBasedQueue<ValueType>::peek() const {
  if (isEmpty())
    error("peek: Attempting to peek at an empty queue");
  return array[head];
}

template <typename ValueType>
ArrayBasedQueue<ValueType>::ArrayBasedQueue(
    const ArrayBasedQueue<ValueType> &src) {
  deepCopy(src);
}

template <typename ValueType>
ArrayBasedQueue<ValueType> &
ArrayBasedQueue<ValueType>::operator=(const ArrayBasedQueue<ValueType> &src) {
  if (this != &src) {
    delete[] array;
    deepCopy(src);
  }
  return *this;
}

template <typename ValueType>
void ArrayBasedQueue<ValueType>::deepCopy(
    const ArrayBasedQueue<ValueType> &src) {
  int count = src.size();
  capacity = count + INITIAL_CAPACITY;
  array = new ValueType[capacity];
  for (int i = 0; i < count; i++)
    array[i] = src.array[(src.head + i) % src.capacity];
  head = 0;
  tail = count;
}

template <typename ValueType>
void ArrayBasedQueue<ValueType>::expandCapacity() {
  int count = size();
  ValueType *oldArray = array;
  array = new ValueType[2 * capacity];
  for (int i = 0; i < count; i++)
    array[i] = oldArray[(head + i) % capacity];
  capacity *= 2;
  head = 0;
  tail = count;
  delete[] oldArray;
}

#endif
