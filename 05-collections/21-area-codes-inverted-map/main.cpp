/* Programming Abstractions in C++
 *
 * Exercise 05-21 (05-20 in the book but only because there are two 05-19s)
 *
 * When you wrote the FindAreaCode program for the previous exercise, it is
 * likely that you generated the list of area codes for a state by looping
 * through the entire map and printing out any area codes that mapped to that
 * state. Although this strategy is fine for small maps like the area code
 * example, efficiency will become an issue in working with much larger data
 * maps.
 *
 * An alternative approach is to invert the map so that you can perform
 * lookup operations in either direction. You can’t, however, declare the
 * inverted map as a Map<string,int>, because there is often more than one area
 * code associated with a state. What you need to do instead is to make the
 * inverted map a Map< string,Vector<int> > that maps each state name to a
 * vector of the area codes that serve that state. Rewrite the FindAreaCode
 * program so that it creates an inverted map after reading in the data file and
 * then uses that map to list the area codes for a state.
 *
 * Solution 2021 Ben Mills
 */

#include <fstream>
#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/map.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"

const std::string FILE_NAME = "area-codes.txt";

std::string getFile(ifstream &infile);
void initMaps(Map<int, std::string> &areaCodes,
              Map<string, Vector<int>> &states, ifstream &infile);
void findAreaCode(Map<int, std::string> &areaCodes,
                  Map<std::string, Vector<int>> &states);
void printState(std::string line, Map<int, std::string> &areaCodes);
void printAreaCode(std::string line, Map<std::string, Vector<int>> &states);

int main() {
  Map<int, std::string> areaCodes;
  Map<std::string, Vector<int>> states;
  ifstream infile;
  getFile(infile);
  initMaps(areaCodes, states, infile);
  findAreaCode(areaCodes, states);
  return 0;
}

std::string getFile(ifstream &infile) {
  std::string filename = FILE_NAME;
  infile.open(filename.c_str());
  if (!infile.fail())
    return filename;
  infile.clear();
  std::cout << "Unable to locate" << filename << std::endl;
  return 0;
}

void initMaps(Map<int, std::string> &areaCodes,
              Map<string, Vector<int>> &states, ifstream &infile) {
  // Setup areaCodes
  std::string line;
  std::string strCode = "";
  int code = 0;
  while (getline(infile, line)) {
    strCode = line.substr(0, 3);
    code = stringToInteger(strCode);
    areaCodes.put(code, line.substr(4));
  }
  infile.close();
  // Setup states (invert map)
  for (int code : areaCodes) {
    Vector<int> allCurrentCodes;
    if (states.containsKey(areaCodes.get(code))) {
      allCurrentCodes += states.get(areaCodes.get(code));
    }
    allCurrentCodes.add(code);
    std::string currentState = areaCodes.get(code);
    states.put(currentState, allCurrentCodes);
  }
}

void findAreaCode(Map<int, std::string> &areaCodes,
                  Map<std::string, Vector<int>> &states) {
  while (true) {
    std::string line = getLine("Enter area code or state name: ");
    if (isdigit(line[0])) {
      printState(line, areaCodes);
    } else if (isalpha(line[0])) {
      printAreaCode(line, states);
    } else {
      std::cout << "goodbye" << std::endl;
      break;
    }
  }
}

void printState(std::string line, Map<int, std::string> &areaCodes) {
  std::cout << areaCodes.get(stringToInteger(line)) << std::endl;
}

void printAreaCode(std::string line, Map<std::string, Vector<int>> &states) {
  std::cout << states.get(line) << std::endl;
}
