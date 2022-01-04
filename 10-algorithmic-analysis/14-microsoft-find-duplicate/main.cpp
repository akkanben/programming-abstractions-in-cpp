/* Programming Abstractions in C++
 *
 * Exercise
 *
 * If you enjoyed the previous problem, here’s an even more challenging one that
 * used to be an interview question at Microsoft. Suppose that you have a vector
 * of N elements, in which each element has a value in the inclusive range 1 to
 * N – 1. Given that there are N elements in the vector and only N – 1 possible
 * values to store in each slot, there must be at least one value that is
 * duplicated in the vector. There may, of course, be many duplicated values,
 * but you know that there must be at least one by virtue of what mathematicians
 * call the pigeonhole principle: if you have more items to put into a set of
 * pigeonholes than the number of pigeonholes, there must be some pigeonhole
 * that ends up with more than one item. Your task in this problem is to write a
 * function
 *
 *  int findDuplicate(Vector<int> vec);
 *
 * that takes a vector whose values are constrained to be in the 1 to N – 1
 * range and returns one of the duplicated values. The hard part of this problem
 * is to design an algorithm so that your implementation adheres to the same set
 * of conditions as the solution to the preceding exercise:
 *
 *  • It must run in O(N) time.
 *  • It must use O(1) additional space. In other words, it may use individual
 *    temporary variables but may not allocate any additional array or vector
 *    storage. Moreover, this condition rules out recursive solutions, because
 *    the space required to store the stack frames would grow with the depth of
 *    the recursion.
 *  • It may not change any of the values in the vector.
 *
 * It’s easy, for example, to write a quadratic-time solution to this problem,
 * which looks like this:
 *
 *  int findDuplicate(Vector<int> & vec) {
 *    for (int i = 0; i < vec.size(); i++) {
 *      for (int j = 0; j < i; j++) {
 *        if (vec[i] == vec[j]) return vec[i];
 *      }
 *    }
 *    error("Vector has no duplicates");
 *    return -1;
 *  }
 *
 * The hard part is optimizing it so that it runs in linear time.
 *
 * Solution 2021 Ben Mills
 *
 * If the vector only contains elements between 1 and n-1 then we can calculate
 * the difference between an expected total sum and the actual sum of all the
 * vectors. We can use this to find the duplicate value. Back in exercise 1-3
 * there mention of Friedrich Gauss and the story of his teacher asking him to
 * add 1-100 this gave me the idea of finding an expected sum.
 */

#include <iostream>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/vector.h"

int findDuplicate(Vector<int> &vec);

int main() {
  Vector<int> vec;
  vec += 5, 2, 1, 6, 3, 6, 4;
  std::cout << vec << std::endl;
  std::cout << "Duplicate: " << findDuplicate(vec) << std::endl;
  return 0;
}

int findDuplicate(Vector<int> &vec) {
  int size = vec.size();
  int sum = 0;
  for (int i = 0; i < vec.size(); i++) {
    sum += vec[i];
  }
  int expected = size * (size + 1) / 2;
  int duplicate = sum - expected + size;
  if (expected > sum)
    duplicate = sum - expected + size;
  else
    duplicate = expected - sum + size;
  if (duplicate == vec.size()) {
    error("No duplicate found.");
    return -1;
  }
  return duplicate;
}
