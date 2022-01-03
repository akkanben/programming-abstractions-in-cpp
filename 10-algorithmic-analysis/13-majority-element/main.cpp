/* Programming Abstractions in C++
 *
 * Exercise
 *
 * If you’re ready for a real algorithmic challenge, write the function
 *
 *  int findMajorityElement(Vector<int> & vec);
 *
 * that takes a vector of nonnegative integers and returns the majority element,
 * which is defined to be a value that occurs in an absolute majority (at least
 * 50 percent plus one) of the element positions. If no majority element exists,
 * the function should return –1 to signal that fact. Your function must also
 * meet the following conditions:
 *
 *  • It must run in O (N ) time.
 *
 *  • It must use O (1 ) additional space. In other words, it may use individual
 *    temporary variables but may not allocate any additional array or vector
 *    storage. Moreover, this condition rules out recursive solutions, because
 * the space required to store the stack frames would grow with the depth of the
 *    recursion.
 *
 *  • It may not change any of the values in the vector.
 *
 * The hard part about this problem is coming up with the algorithm, not
 * implementing it. Play with some sample vectors and see if you can come up
 * with the right strategy.
 *
 * Solution 2021 Ben Mills
 *
 * I got something close to this on my own but ended up searching for more ideas
 * online. My solution uses the Boyer-Moore majority vote algorithm:
 * https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
 *
 * The main() while loop continues until a majority element is found. Currently
 * it is set building random vectors using 3 elements: 0, 1, or 2.
 */

#include <iostream>

#include "../../StanfordCPPLib/include/random.h"
#include "../../StanfordCPPLib/include/vector.h"

const int VEC_SIZE = 20;

int findMajorityElement(Vector<int> &vec);
Vector<int> randomVectorOfSize(int size, int max);

int main() {
  std::string MajorityElement = "none";
  while (MajorityElement == "none") {
    Vector<int> vec = randomVectorOfSize(VEC_SIZE, 2);
    int element = findMajorityElement(vec);
    if (element < 0)
      MajorityElement = "none";
    else
      MajorityElement = integerToString(element);
    std::cout << vec << std::endl;
    std::cout << "Majority Element: " << MajorityElement << std::endl;
  }
  return 0;
}

int findMajorityElement(Vector<int> &vec) {
  int majorityElementIndex = 0;
  int count = 1;
  for (int i = 1; i < vec.size(); i++) {
    if (vec[majorityElementIndex] == vec[i])
      count++;
    else
      count--;
    if (count == 0) {
      majorityElementIndex = i;
      count = 1;
    }
  }
  count = 0;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == vec[majorityElementIndex])
      count++;
  }
  return count > (vec.size() / 2) + 1 ? vec[majorityElementIndex] : -1;
}

Vector<int> randomVectorOfSize(int size, int max) {
  Vector<int> output;
  for (int i = 0; i < size; i++) {
    int randomNumber = randomInteger(0, max);
    output.add(randomNumber);
  }
  return output;
}
