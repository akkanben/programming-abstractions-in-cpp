/* Programming Abstractions in C++
 *
 * Exercise 09-09
 *
 * The game of dominos is played with rectangular pieces composed of two
 * connected squares, each of which is marked with a certain number of dots.
 * For example, each of the following four rectangles represents a domino:
 *
 *  <image of 4 dominos>
 *
 * Dominos can be connected end-to-end to form chains, subject to the condition
 * that two dominos can be linked together only if the numbers match. For
 * example, you can form a chain consisting of these four dominos by connecting
 * them in the following order:
 *
 *  <image of 4 domino chain>
 *
 * As in the traditional game, dominos can be rotated by 180 ̊ so that their
 * numbers are reversed. In this chain, for example, the 1–6 and 3–4 dominos
 * have been “turned over” so that they fit into the chain.
 *
 * Suppose that you have access to a Domino class (see Chapter 6, exercise 1)
 * that exports the methods getLeftDots and getRightDots. Given this
 * class, write a recursive function
 *
 *  bool formsDominoChain(Vector<Domino> & dominos);
 *
 * that returns true if it possible to build a chain consisting of every domino
 * in the vector.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/vector.h"
#include "domino.h"

const int NUM_SIDES = 6;

bool formsDominoChain(Vector<Domino> &dominos);
bool canGetDominoChain(Vector<Domino> &dominos, Vector<Domino> toBeSorted,
                       Vector<Domino> &solution);
bool isValidChain(Vector<Domino>(dominos));
Vector<Domino> subtract(Vector<Domino> vectA, Vector<Domino> vectB);

int main() {
  Vector<Domino> dominos = getVectorOfDominoes(NUM_SIDES);
  if (formsDominoChain(dominos)) {
    cout << "Domino chain possible." << endl;
  } else {
    cout << "Domino chain NOT possible." << endl;
  }
  return 0;
}

bool formsDominoChain(Vector<Domino> &dominos) {
  Vector<Domino> toBeSorted = dominos;
  Vector<Domino> solution;
  solution.add(Domino(0, 0));
  // remove first element since we start with it in solution.
  toBeSorted.remove(0);
  if (canGetDominoChain(dominos, toBeSorted, solution))
    return true;
  else
    return false;
}

bool canGetDominoChain(Vector<Domino> &dominos, Vector<Domino> toBeSorted,
                       Vector<Domino> &solution) {
  if (solution.size() >= dominos.size() && isValidChain(solution)) {
    cout << solution << endl;
    return true;
  }
  for (int i = 0; i < toBeSorted.size(); i++) {
    for (int j = 0; j < 2; j++) {
      Vector<Domino> tester;
      tester += solution[solution.size() - 1];
      tester += toBeSorted[i];
      if (j == 0 && isValidChain(tester)) {
        solution += toBeSorted[i];
        if (canGetDominoChain(dominos, subtract(dominos, solution), solution)) {
          return true;
        }
        solution.remove(solution.size() - 1);
      }
      tester.clear();
      tester += solution[solution.size() - 1];
      tester += toBeSorted[i];
      tester[tester.size() - 1].flip();
      if (j == 1 && isValidChain(tester)) {
        solution += toBeSorted[i];
        Vector<Domino> flippedSolution = solution;
        flippedSolution[flippedSolution.size() - 1].flip();
        if (canGetDominoChain(dominos, subtract(dominos, solution),
                              flippedSolution)) {
          return true;
        }
        solution.remove(solution.size() - 1);
      }
    }
  }
  return false;
}

bool isValidChain(Vector<Domino>(dominos)) {
  if (dominos.size() <= 1) {
    return true;
  } else {
    for (int i = 0; i < dominos.size() - 1; i++) {
      if (dominos[i].getDotB() != dominos[i + 1].getDotA()) {
        return false;
      }
    }
  }
  return true;
}

Vector<Domino> subtract(Vector<Domino> vectA, Vector<Domino> vectB) {
  Vector<int> indexes;
  for (int i = 0; i < vectA.size(); i++) {
    for (int j = 0; j < vectB.size(); j++) {
      Domino flipped = vectB[j];
      flipped.flip();
      if (vectA[i] == vectB[j] || vectA[i] == flipped) {
        indexes += i;
      }
    }
  }
  // proceeding backwards through vectA as to not mess with the index locations
  for (int i = indexes.size() - 1; i >= 0; i--) {
    vectA.remove(indexes[i]);
  }
  return vectA;
}
