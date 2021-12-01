/* Programming Abstractions in C++
 *
 * Exercise 05-01
 *
 * Write the overloaded functions
 *
 *  void readVector(istream & is, Vector<int> & vec);
 *  void readVector(istream & is, Vector<double> & vec);
 *  void readVector(istream & is, Vector<string> & vec);
 *
 * each of which reads lines from the input stream specified by is into the
 * vector vec. In the input stream, each element of the vector appears on a line
 * of its own. The function should read elements until it encounters a blank
 * line or the end of the file.
 *
 * To illustrate the operation of this function, suppose that you have the data
 * file
 *
 *  <image of sample run>
 *
 * and that you have opened infile as an ifstream on that file. In addition,
 * suppose that you have declared the variable roots as follows:
 *
 * Vector<double> roots;
 *
 * The first call to readVector(infile, roots) should initialize roots so
 * that it contains the four elements shown at the beginning of the file. The
 * second call should change the value of roots so that it contains the eight
 * elements shown at the end of the file. Calling readVector a third time
 * should set roots to an empty vector.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/filelib.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "../../StanfordCPPLib/include/vector.h"
#include <iostream>
#include <string>

void readVector(std::istream &is, Vector<int> &vec);
void readVector(std::istream &is, Vector<double> &vec);
void readVector(std::istream &is, Vector<std::string> &vec);
void printVector(Vector<double> &vec);

int main() {
  std::ifstream inFile;
  Vector<double> roots;
  inFile.open("roots.txt");
  if (inFile.fail())
    error("Can't open roots.txt");
  readVector(inFile, roots);
  printVector(roots);
  readVector(inFile, roots);
  printVector(roots);
  readVector(inFile, roots);
  printVector(roots);
  inFile.close();
  return 0;
}

void readVector(std::istream &is, Vector<int> &vec) {
  vec.clear();
  std::string line;
  int i;
  while (getline(is, line)) {
    if (line.length() < 1)
      break;
    i = stringToInteger(line);
    vec.add(i);
  }
}

void readVector(std::istream &is, Vector<double> &vec) {
  vec.clear();
  std::string line;
  double d;
  while (getline(is, line)) {
    if (line.length() < 1)
      break;
    d = stringToReal(line);
    vec.add(d);
  }
}

void readVector(std::istream &is, Vector<std::string> &vec) {
  vec.clear();
  std::string line;
  while (getline(is, line)) {
    if (line.length() < 1)
      break;
    vec.add(line);
  }
}

void printVector(Vector<double> &vec) {
  std::cout << "[";
  for (int i = 0; i < vec.size(); i++) {
    if (i > 0)
      std::cout << ", ";
    std::cout << vec[i];
  }
  std::cout << "]" << std::endl;
}
