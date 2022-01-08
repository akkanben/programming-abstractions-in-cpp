#include "IntArray.h"
#include "../../StanfordCPPLib/include/error.h"

IntArray::IntArray(int n) {
  array = new int[n];
  count = n;
  while (n-- >= 0)
    array[n] = 0;
}

IntArray::~IntArray() { delete[] array; }

int IntArray::size() const { return count; }

int IntArray::get(int k) const {
  if (k < 0 || k > count)
    error("Index out of bounds.");
  return array[k];
}

void IntArray::put(int k, int value) {
  if (k < 0 || k > count)
    error("Index out of bounds.");
  array[k] = value;
}

int IntArray::operator[](int index) {
  if (index < 0 || index > count)
    error("Index out of bounds.");
  return array[index];
}

IntArray::IntArray(const IntArray &src) { deepCopy(src); }

IntArray &IntArray::operator=(const IntArray &src) { return *this; }

void IntArray::deepCopy(const IntArray &src) {
  array = new int[src.count];
  for (int i = 0; i < src.count; i++)
    array[i] = src.array[i];
  count = src.count;
}
