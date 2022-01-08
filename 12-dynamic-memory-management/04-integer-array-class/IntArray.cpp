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
