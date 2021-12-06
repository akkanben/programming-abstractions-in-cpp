#include <ostream>
#include <string>

#include "../../StanfordCPPLib/include/strlib.h"
#include "LabelGenerator.h"

LabelGenerator::LabelGenerator() {
  name = "";
  number = 0;
};

LabelGenerator::LabelGenerator(std::string name_i, int number_i) {
  name = name_i;
  number = number_i;
};

std::string LabelGenerator::nextLabel() {
  int current = number;
  number += 1;
  return name + integerToString(current);
};

std::string LabelGenerator::toString() {
  std::string output = name + integerToString(number);
  return output;
};
