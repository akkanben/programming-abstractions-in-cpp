#ifndef _linkedlistbasedqueue_h
#define _linkedlistbasedqueue_h

#include "../../StanfordCPPLib/include/error.h"

template <typename ValueType> class LinkedListBasedQueue {
public:
  LinkedListBasedQueue();
  ~LinkedListBasedQueue();
  int size() const;
  bool isEmpty() const;
  void clear();
  void enqueue(ValueType value);
  ValueType dequeue();
  ValueType peek() const;
  LinkedListBasedQueue(const LinkedListBasedQueue<ValueType> &src);
  LinkedListBasedQueue<ValueType> &
  operator=(const LinkedListBasedQueue<ValueType> &src);

private:
  struct Cell {
    ValueType data;
    Cell *link;
  };
  Cell *head;
  Cell *tail;
  int count;
  void deepCopy(const LinkedListBasedQueue<ValueType> &src);
};

template <typename ValueType>
LinkedListBasedQueue<ValueType>::LinkedListBasedQueue() {
  head = tail = NULL;
  count = 0;
}

template <typename ValueType>
LinkedListBasedQueue<ValueType>::~LinkedListBasedQueue() {
  clear();
}

template <typename ValueType>
int LinkedListBasedQueue<ValueType>::size() const {
  return count;
}

template <typename ValueType>
bool LinkedListBasedQueue<ValueType>::isEmpty() const {
  return count == 0;
}

template <typename ValueType> void LinkedListBasedQueue<ValueType>::clear() {
  while (count > 0)
    dequeue();
}

template <typename ValueType>
void LinkedListBasedQueue<ValueType>::enqueue(ValueType value) {
  Cell *cp = new Cell;
  cp->data = value;
  cp->link = NULL;
  if (head == NULL)
    head = cp;
  else
    tail->link = cp;
  tail = cp;
  count++;
}

template <typename ValueType>
ValueType LinkedListBasedQueue<ValueType>::dequeue() {
  if (isEmpty())
    error("dequeue: Attempting to dequeue an empty queue");
  Cell *cp = head;
  ValueType result = cp->data;
  head = cp->link;
  if (head == NULL)
    tail = NULL;
  delete cp;
  count--;
  return result;
}

template <typename ValueType>
ValueType LinkedListBasedQueue<ValueType>::peek() const {
  if (isEmpty())
    error("peek: Attempting to peek at an empty queue");
  return head->data;
}

template <typename ValueType>
LinkedListBasedQueue<ValueType>::LinkedListBasedQueue(
    const LinkedListBasedQueue<ValueType> &src) {
  deepCopy(src);
}

template <typename ValueType>
LinkedListBasedQueue<ValueType> &LinkedListBasedQueue<ValueType>::operator=(
    const LinkedListBasedQueue<ValueType> &src) {
  if (this != &src) {
    clear();
    deepCopy(src);
  }
  return *this;
}

template <typename ValueType>
void LinkedListBasedQueue<ValueType>::deepCopy(
    const LinkedListBasedQueue<ValueType> &src) {
  head = NULL;
  tail = NULL;
  count = 0;
  for (Cell *cp = src.head; cp != NULL; cp = cp->link)
    enqueue(cp->data);
}

#endif
