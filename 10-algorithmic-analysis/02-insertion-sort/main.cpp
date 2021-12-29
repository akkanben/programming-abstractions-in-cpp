/* Programming Abstractions in C++
 *
 * Exercise 10-02
 *
 * There are several other sorting algorithms that exhibit the O (N 2) behavior
 * of selection sort. Of these, one of the most important is insertion sort,
 * which operates as follows. You go through each element in the vector in turn,
 * as with the selection sort algorithm. At each step in the process, however,
 * the goal is not to find the smallest remaining value and switch it into its
 * correct position, but rather to ensure that the values considered so far are
 * correctly ordered with respect to each other. Although those values may shift
 * as more elements are processed, they form an ordered sequence in and of
 * themselves.
 *
 * For example, if you consider again the data used in the sorting examples
 * from this chapter, the first cycle of the insertion sort algorithm requires
 * no work, because a vector of one element is always sorted:
 *
 *  in
 * order
 *  /\
 *  56 25 37 58 95 19 73 30
 *  0  1  2  3  4  5  6  7
 *
 * On the next cycle, you need to put 25 into the correct position with respect
 * to the elements you have already seen, which means that you need to exchange
 * the 56 and 25 to reach the following configuration:
 *
 *   in
 *  order
 *   ___
 *  /   \
 *  25 56 37 58 95 19 73 30
 *  0  1  2  3  4  5  6  7
 *
 * On the third cycle, you need to find where the value 37 should go. To do so,
 * you need to move backward through the earlier elements—which you know
 * are in order with respect to each other—looking for the position where 37
 * belongs. As you go, you need to shift each of the larger elements one
 * position to the right, which eventually makes room for the value you’re
 * trying to insert. In this case, the 56 gets shifted by one position, and the
 * 37 winds up in position 1. Thus, the configuration after the third cycle
 * looks like this:
 *
 *  in order
 *   ______
 *  /      \
 *  25 37 56 58 95 19 73 30
 *  0  1  2  3  4  5  6  7
 *
 *
 * After each cycle, the initial portion of the vector is always sorted, which
 * implies that cycling through all the positions in this way will sort the
 * entire vector.
 *
 * The insertion sort algorithm is important in practice because it runs in
 * linear time if the vector is already more or less in the correct order. It
 * therefore makes sense to use insertion sort to restore order to a large
 * vector in which only a few elements are out of sequence.
 *
 * Write an implementation of sort that uses the insertion sort algorithm.
 * Construct an informal argument to show that the worst-case behavior of
 * insertion sort is O(N^2).
 *
 * Solution 2021 Ben Mills
 *
 * In the best case the vector is already sorted and this algorithm will run in
 * linear time passing through the vector one time. In the worst case it will
 * need to move each item in the vector back to the first position, creating
 * something similar to two nested for loops.
 *
 */

#include <iostream>

#include "../../StanfordCPPLib/include/vector.h"

void sort(Vector<int> &vec);

int main() {
  Vector<int> vec;
  vec += 56, 25, 37, 58, 95, 19, 73, 30;
  std::cout << "Unsorted: " << vec << std::endl;
  sort(vec);
  std::cout << "Sorted: " << vec << std::endl;
  return 0;
}

void sort(Vector<int> &vec) {
  if (vec.size() <= 1)
    return;
  for (int i = 1; i < vec.size(); i++) {
    int backPosition = i;
    while (backPosition > 0 && vec[backPosition] < vec[backPosition - 1]) {
      int temp = vec[backPosition - 1];
      vec[backPosition - 1] = vec[backPosition];
      vec[backPosition] = temp;
      backPosition--;
    }
  }
}
