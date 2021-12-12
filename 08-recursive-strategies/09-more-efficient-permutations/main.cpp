/* Programming Abstractions in C++
 *
 * Exercise 08-09
 *
 * The strategy used to implement the Permutations program in the text is
 * designed to emphasize its recursive character. The resulting code is not
 * particularly efficient, mostly because it ends up generating sets that are
 * later discarded and because it applies methods like substr that require
 * copying the characters in a string. It is possible to eliminate those
 * inefficiencies using the following recursive formulation:
 *
 *  a)  At each level, pass the entire string along with an index that indicates
 *      where the permutation process starts. Characters in the string before
 *      this index stay where they are; characters at or after that position
 *      must go through all their permutations.
 *
 *  b)  The simple case occurs when the index reaches the end of the string.
 *
 *  c)  The recursive case operates by swapping the character at the index
 *      position with every other character in the string and then generating
 *      every permutation starting with the next higher index and then swapping
 *      the characters back to ensure that the original order is restored.
 *
 * Use this strategy to implement a function
 *
 *  void listPermutations(string str);
 *
 * that lists on cout all permutations of the string str without generating any
 * sets at all or applying any string methods other than length or selection.
 * The listPermutations function itself must be a wrapper function for a second
 * function that includes the index.
 *
 * This function is relatively easy to implement if you don’t try to take
 * account of duplicated letters in the string. The interesting challenge comes
 * in adapting the structure of the algorithm so that it lists each unique
 * permutation exactly once without using sets to accomplish that task. You
 * should not, however, worry about the order in which listPermutations delivers
 * its output.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

void listPermutations(std::string str);
std::string generatePermutations(std::string str, int index);
void swapChar(char &a, char &b);

int main() {
  listPermutations("abc");
  return 0;
}

void listPermutations(std::string str) {
  std::cout << generatePermutations(str, 0) << std::endl;
}

std::string generatePermutations(std::string str, int index) {
  if (index == str.length())
    return str;
  std::string result;
  for (int i = index; i < str.length(); i++) {
    swapChar(str[index], str[i]);
    result += generatePermutations(str, index + 1) + " ";
    swapChar(str[index], str[i]);
  }
  return result;
}

void swapChar(char &a, char &b) {
  char temp = a;
  a = b;
  b = temp;
}
