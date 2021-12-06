/* Programming Abstractions in C++
 *
 * Exercise
 *
 * For certain applications, it is useful to be able to generate a series of
 * names that form a sequential pattern. For example, if you were writing a
 * program to number figures in a paper, having some mechanism to return the
 * sequence of strings "Figure 1", "Figure 2", "Figure 3", and so on, would be
 * very handy. However, you might also need to label points in a geometric
 * diagram in which case you would want a similar but independent set of labels
 * for points such as "P0", "P1", "P2", and so forth.
 *
 * If you think about this problem more generally, the tool you need is a label
 * generator that allows the client to define arbitrary sequences of labels,
 * each of which consists of a prefix string ( "Figure " or "P" for the examples
 * in the preceding paragraph) coupled with an integer used as a sequence
 * number. Because the client may want different sequences to be active
 * simultaneously, it makes sense to define the label generator as a
 * LabelGenerator class. To initialize a new generator, the client provides the
 * prefix string and the initial index as arguments to the LabelGenerator
 * constructor. Once the generator has been created, the client can return new
 * labels in the sequence by calling nextLabel on the LabelGenerator.
 *
 * As an illustration of how the interface works, the main program shown in
 * Figure 6-14 produces the following sample run:
 *
 *  <image of sample run>
 *
 * Write the files labelgen.h and labelgen.cpp to support this class.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "LabelGenerator.h"

int main() {
  LabelGenerator figureNumbers("Figure ", 1);
  LabelGenerator pointNumbers("P", 0);
  std::cout << "Figure numbers: ";
  for (int i = 0; i < 3; i++) {
    if (i > 0)
      std::cout << ", ";
    std::cout << figureNumbers.nextLabel();
  }
  std::cout << std::endl << "Point numbers:  ";
  for (int i = 0; i < 5; i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << pointNumbers.nextLabel();
  }
  std::cout << std::endl << "More figures:   ";
  for (int i = 0; i < 3; i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << figureNumbers.nextLabel();
  }
  std::cout << std::endl;
  return 0;
}
