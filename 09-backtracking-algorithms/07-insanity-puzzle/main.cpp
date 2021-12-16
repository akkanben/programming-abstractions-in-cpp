/* Programming Abstractions in C++
 *
 * Exercise 09-07
 *
 * In the 1960s, a puzzle called Instant Insanity was popular for some years
 * before it faded from view. The puzzle consisted of four cubes whose faces
 * were each painted with one of the colors red, blue, green, and white,
 * represented in the rest of this problem by their initial letter. The goal of
 * the puzzle was to arrange the cubes into a line so that if you looked at the
 * line from any of its edges, you would see no duplicated colors.
 *
 * Cubes are hard to draw in two dimensions, but the following diagram
 * shows what the cubes would look like if you unfolded them and placed them
 * flat on the page:
 *
 *      G           R
 *  W B B R     W W G B
 *      G           G
 *
 *      W           B
 *  R R W B     G R R R
 *      G           W
 *
 * Write a program that uses backtracking to solve the Instant Insanity puzzle.
 *
 * Solution 2021 Ben Mills
 */

#include <string>

#include "../../StanfordCPPLib/include/set.h"
#include "../../StanfordCPPLib/include/vector.h"
#include "cube.h"

const int TOTAL_CUBES = 4;
const int MAX_ROTATION = 4;
const int TOTAL_SIDES_PER_CUBE = 6;

bool isUnique(Vector<char> vec);
bool solveInsanity(Vector<Cube> fourCubes, Vector<std::string> &answer,
                   int cubeIndex, int rotationIndex, int sideIndex);
bool puzzleCheck(Vector<Cube> fourCubes, Vector<std::string> &answer,
                 int cubeIndex, int rotationIndex, int sideIndex);
void printResults(Vector<std::string> &answer);

int main() {
  Cube cubeA('G', 'W', 'B', 'B', 'R', 'G');
  Cube cubeB('R', 'W', 'W', 'G', 'B', 'G');
  Cube cubeC('W', 'R', 'R', 'W', 'B', 'G');
  Cube cubeD('B', 'G', 'R', 'R', 'R', 'W');
  Vector<Cube> fourCubes;
  fourCubes += cubeA, cubeB, cubeC, cubeD;
  Vector<int> sideIndex(TOTAL_CUBES);
  Vector<std::string> answer(TOTAL_CUBES);
  if (solveInsanity(fourCubes, answer, 0, 0, 0)) {
    std::cout << "Instant Insanity was solved." << std::endl;
    printResults(answer);
  } else {
    std::cout << "Instant Insanity could not be solved." << std::endl;
  }
  return 0;
}

bool solveInsanity(Vector<Cube> fourCubes, Vector<std::string> &answer,
                   int cubeIndex, int rotationIndex, int sideIndex) {
  if (cubeIndex >= TOTAL_CUBES) {
    return true;
  }
  for (int s = 0; s < TOTAL_SIDES_PER_CUBE; s++) {
    for (int r = 0; r < MAX_ROTATION; r++) {
      if (puzzleCheck(fourCubes, answer, cubeIndex, r, s)) {
        if (solveInsanity(fourCubes, answer, cubeIndex + 1, r, s)) {
          return true;
        }
        answer[cubeIndex] = "";
      }
      if (s == TOTAL_SIDES_PER_CUBE - 1 && r == MAX_ROTATION - 1) {
        cubeIndex--;
      }
    }
  }
  return false;
}

bool puzzleCheck(Vector<Cube> fourCubes, Vector<std::string> &answer,
                 int cubeIndex, int rotationIndex, int sideIndex) {
  Vector<char> sideA;
  Vector<char> sideB;
  Vector<char> sideC;
  Vector<char> sideD;
  for (int i = 0; i <= cubeIndex; i++) {
    if (i == cubeIndex) {
      sideA +=
          fourCubes[i].getRotationSides(sideIndex)[(rotationIndex + 0) % 4];
      sideB +=
          fourCubes[i].getRotationSides(sideIndex)[(rotationIndex + 1) % 4];
      sideC +=
          fourCubes[i].getRotationSides(sideIndex)[(rotationIndex + 2) % 4];
      sideD +=
          fourCubes[i].getRotationSides(sideIndex)[(rotationIndex + 3) % 4];
    } else {
      sideA += answer[i][0];
      sideB += answer[i][1];
      sideC += answer[i][2];
      sideD += answer[i][3];
    }
  }
  if (isUnique(sideA) && isUnique(sideB) && isUnique(sideC) &&
      isUnique(sideD)) {
    answer[cubeIndex] += sideA[cubeIndex];
    answer[cubeIndex] += sideB[cubeIndex];
    answer[cubeIndex] += sideC[cubeIndex];
    answer[cubeIndex] += sideD[cubeIndex];
    return true;
  }
  return false;
}

bool isUnique(Vector<char> vec) {
  Set<char> test;
  for (int i = 0; i < vec.size(); i++) {
    test.add(vec[i]);
  }
  if (test.size() == vec.size()) {
    return true;
  } else {
    return false;
  }
}

void printResults(Vector<std::string> &answer) {
  std::cout << "\nThe four cubes rotations: ." << std::endl;
  std::cout << answer << std::endl;
  std::cout << "\nThe four visible connected sides:" << std::endl;
  std::string a, b, c, d;
  for (int i = 0; i < answer.size(); i++) {
    a += answer[i][0];
    b += answer[i][1];
    c += answer[i][2];
    d += answer[i][3];
  }
  std::cout << "{\"" << a << ", " << b << ", " << c << ", " << d << "\"}"
            << std::endl;
}
