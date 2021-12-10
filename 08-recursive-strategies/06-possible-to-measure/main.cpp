/* Programming Abstractions in C++
 *
 * Exercise 08-06
 *
 *    I am the only child of parents who weighed, measured,
 *    and priced everything; for whom what could not be
 *    weighed, measured, and priced had no existence.
 *       — Charles Dickens, Little Dorrit, 1857
 *
 * In Dickens’s time, merchants measured many commodities using weights and
 * a two-pan balance—a practice that continues in many parts of the world today.
 * If you are using a limited set of weights, however, you can only measure
 * certain quantities accurately. For example, suppose that you have only two
 * weights: a 1-ounce weight and a 3-ounce weight. With these you can easily
 * measure out 4 ounces, as shown:
 *
 * It is somewhat more interesting to discover that you can also measure out 2
 * ounces by shifting the 1-ounce weight to the other side, as follows:
 *
 * Write a recursive function
 *
 *  bool isMeasurable(int target, Vector<int> & weights)
 *
 * that determines whether it is possible to measure out the desired target
 * amount with a given set of weights, which is stored in the vector weights.
 *
 * For example, suppose that sampleWeights has been initialized like this:
 *
 *  Vector<int> sampleWeights;
 *  sampleWeights += 1, 3;
 *
 * Given these values, the function call
 *
 *  isMeasurable(2, sampleWeights)
 *
 * should return true because it is possible to measure out 2 ounces using the
 * sample weight set as illustrated in the preceding diagram. On the other hand,
 * calling
 *
 *  isMeasurable(5, sampleWeights)
 *
 * should return false because it is impossible to use the 1- and 3-ounce
 * weights to measure out 5 ounces.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/vector.h"

bool isMeasurable(int target, Vector<int> &weights);
void printResults(Vector<int> vec);

int main() {
  Vector<int> weightsA;
  Vector<int> weightsB;
  weightsA += 1, 3;
  weightsB += 3, 1, 10;
  std::cout << "Measurable with a 1 lb. and a 3 lb. weight:" << std::endl;
  printResults(weightsA);
  std::cout << "Measurable with a 3 lb. a 1 lb and a 10 lb. weight:"
            << std::endl;
  printResults(weightsB);

  return 0;
}

bool isMeasurable(int target, Vector<int> &weights) {
  if (weights.isEmpty())
    return target == 0;
  else {
    int element = weights[0];
    Vector<int> rest = weights;
    rest.removeAt(0);
    return isMeasurable(target + element, rest) ||
           isMeasurable(target - element, rest) || isMeasurable(target, rest);
  }
}

void printResults(Vector<int> vec) {
  int totalWeight = 0;
  for (int i = 0; i < vec.size(); i++) {
    totalWeight += vec[i];
  }
  for (int i = 1; i <= totalWeight + 1; i++) {
    std::string possible = isMeasurable(i, vec) ? "true" : "false";
    std::cout << i << " lb. " << possible << std::endl;
  }
}
