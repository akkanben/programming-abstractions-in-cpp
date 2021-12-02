/* Programming Abstractions in C++
 *
 * Exercise 05-20 (actually a typo as 05-19 in the book and 05-21 is missing)
 *
 * Telephone numbers in the United States and Canada are organized into various
 * three-digit area codes. A single state or province will often have many area
 * codes, but a single area code will not cross a state boundary. This rule
 * makes it possible to list the geographical locations of each area code in a
 * data file. For this problem, assume that you have access to the file
 * AreaCodes.txt, which lists all the area codes paired with their locations as
 * illustrated by the first few lines of that file:
 *
 *  <image of AreaCodes.txt>
 *
 * Using the AirportCodes program as a model, write the code necessary to
 * read this file into a Map<int,string>, where the key is the area code and the
 * value is the location. Once you’ve read in the data, write a main program
 * that repeatedly asks the user for an area code and then looks up the
 * corresponding location, as illustrated in the following sample run:
 *
 *  <image of sample run with area code>
 *
 * As the prompt suggests, however, your program should also allow users to
 * enter the name of a state or province and have the program list all the area
 * codes that serve that area, as illustrated by the following sample run:
 *
 *  <image of sample run with state name>
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
void initMap(Map<int, std::string> &areaCodes, ifstream &infile);
void findAreaCode(Map<int, std::string> &areaCodes);
void printState(std::string line, Map<int, std::string> &areaCodes);
void printAreaCode(std::string line, Map<int, std::string> &areaCodes);

int main() {
  Map<int, std::string> areaCodes;
  ifstream infile;
  getFile(infile);
  initMap(areaCodes, infile);
  findAreaCode(areaCodes);
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

void initMap(Map<int, std::string> &areaCodes, ifstream &infile) {
  std::string line;
  std::string strCode = "";
  int code = 0;
  while (getline(infile, line)) {
    strCode = line.substr(0, 3);
    code = stringToInteger(strCode);
    areaCodes.put(code, line.substr(4));
  }
  infile.close();
}

void findAreaCode(Map<int, std::string> &areaCodes) {
  while (true) {
    std::string line = getLine("Enter area code or state name: ");
    if (isdigit(line[0])) {
      printState(line, areaCodes);
    } else if (isalpha(line[0])) {
      printAreaCode(line, areaCodes);
    } else {
      std::cout << "goodbye" << std::endl;
      break;
    }
  }
}

void printState(std::string line, Map<int, std::string> &areaCodes) {
  std::cout << areaCodes.get(stringToInteger(line)) << std::endl;
}

void printAreaCode(std::string line, Map<int, std::string> &areaCodes) {
  for (int code : areaCodes) {
    if (areaCodes.get(code) == line) {
      std::cout << code << std::endl;
    }
  }
}
