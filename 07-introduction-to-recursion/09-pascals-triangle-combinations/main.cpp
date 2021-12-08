/* Programming Abstractions in C++
 *
 * Exercise
 *
 * As you know from Chapter 2, the mathematical combinations function c(n, k) is
 * usually defined in terms of factorials, as follows:
 *
 *              n!
 * c(n, k) = ----------
 *           k! (n-k)!
 *
 * The values of c(n, k) can also be arranged geometrically to form a triangle
 * in which n increases as you move down the triangle and k increases as you
 * move from left to right. The resulting structure, which is called Pascal’s
 * Triangle after the French mathematician Blaise Pascal, is arranged like this:
 *
 *                c(0, 0)
 *
 *            c(1, 0) c(1, 1)
 *
 *        c(2, 0) c(2, 1) c(2, 2)
 *
 *    c(3, 0) c(3, 1) c(3, 2) c(3, 3)
 *
 * c(4, 0) c(4, 1) c(4, 2) c(4, 3) c(4, 4)
 *
 * Pascal’s Triangle has the interesting property that every entry is the sum of
 * the two entries above it, except along the left and right edges, where the
 * values are always 1. Consider, for example, the circled entry in the
 * following display of Pascal’s Triangle:
 *
 *                1
 *              1   1
 *            1   2   1
 *          1   3   3   1
 *        1   4   6   4   1
 *      1   5   10  10  5   1
 *    1   6  (15) 20  15  6   1
 *  1   7   21  35  35  21  7   1
 *
 * This entry, which corresponds to c(6, 2), is the sum of the two entries—5 and
 * 10—that appear above it to either side. Use this relationship between entries
 * in Pascal’s Triangle to write a recursive implementation of the c(n, k)
 * function that uses no loops, no multiplication, and no calls to fact.
 *
 * Solution 2021 Ben Mills
 */

#include <iomanip>
#include <iostream>

int c(int n, int k);

int main() {
  int size = 15;
  for (int i = 0; i < size; i++) {
    std::cout << std::setw((size / 2 * (size - i)) / 2) << " ";
    for (int j = 0; j <= i; j++) {
      std::cout << std::right << std::setw(size / 2) << c(i, j);
      // std::cout << "c(" << i << ", " << j << ")";
    }
    std::cout << std::endl;
    std::cout << std::endl;
  }
  return 0;
}

int c(int n, int k) {
  if (n == k || k == 0)
    return 1;
  else
    return c(n - 1, k - 1) + c(n - 1, k);
}
