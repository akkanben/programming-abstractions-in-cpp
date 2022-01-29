#ifndef _sort_h
#define _sort_h

#include "../../StanfordCPPLib/include/vector.h"

template <typename ValueType> void sort(Vector<ValueType> &vec) {
  quicksort(vec, 0, vec.size() - 1);
}

template <typename ValueType>
void quicksort(Vector<ValueType> &vec, int start, int finish) {
  if (start >= finish)
    return;
  int boundary = partition(vec, start, finish);
  quicksort(vec, start, boundary - 1);
  quicksort(vec, boundary + 1, finish);
}

template <typename ValueType>
int partition(Vector<ValueType> &vec, int start, int finish) {
  ValueType pivot = vec[start];
  int lh = start + 1;
  int rh = finish;
  while (true) {
    while (lh < rh && vec[rh] >= pivot)
      rh--;
    while (lh < rh && vec[lh] < pivot)
      lh++;
    if (lh == rh)
      break;
    ValueType tmp = vec[lh];
    vec[lh] = vec[rh];
    vec[rh] = tmp;
  }
  if (vec[lh] >= pivot)
    return start;
  vec[start] = vec[lh];
  vec[lh] = pivot;
  return lh;
}

#endif
