/* Programming Abstractions in C++
 *
 * Exercise 08-04
 *
 * In the subset-sum problem introduced in section 8-2, there are often several
 * ways to generate the desired target number. For example, given the set
 * { 1, 3, 4, 5 }, there are two different ways to produce the target value 5:
 *
 *  • Select the 1 and the 4
 *  • Select just the 5
 *
 * By contrast, there is no way to partition the set { 1, 3, 4, 5 } to get 11.
 *
 *  Write a function
 *
 *    int countSubsetSumWays(Set<int> & set, int target);
 *
 * that returns the number of ways in which you can produce the target value by
 * choosing a subset of the specified set. For example, suppose that sampleSet
 * has been initialized as follows:
 *
 *    Set<int> sampleSet;
 *    sampleSet += 1, 3, 4, 5;
 *
 * Given this definition of sampleSet, calling
 *
 *    countSubsetSumWays(sampleSet, 5);
 *
 * should return 2 (there are two ways to make 5), and calling
 *
 *    countSubsetSumWays(sampleSet, 11)
 *
 * should return 0 (there are no ways to make 11).
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/set.h"

int countSubsetSumWays(Set<int> &s, int target);

int main() {
  Set<int> numbers;
  numbers.add(1);
  numbers.add(3);
  numbers.add(4);
  numbers.add(5);
  std::cout << "In the set {1, 3, 4, 5} subsets that add up to" << std::endl;
  std::cout << "5: " << countSubsetSumWays(numbers, 5) << std::endl;
  std::cout << "1: " << countSubsetSumWays(numbers, 1) << std::endl;
  std::cout << "9: " << countSubsetSumWays(numbers, 9) << std::endl;
  std::cout << "11: " << countSubsetSumWays(numbers, 11) << std::endl;
  return 0;
}

int countSubsetSumWays(Set<int> &s, int target) {
  if (s.isEmpty())
    return target == 0 ? 1 : 0;
  else {
    int element = s.first();
    Set<int> rest = s - element;
    return countSubsetSumWays(rest, target) +
           countSubsetSumWays(rest, target - element);
  }
}
