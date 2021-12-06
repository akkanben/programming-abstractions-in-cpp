#ifndef _label_generator_h
#define _label_generator_h

#include <ostream>
#include <string>

class LabelGenerator {
public:
  LabelGenerator();
  LabelGenerator(std::string name_i, int number_i);
  std::string nextLabel();
  std::string toString();

private:
  std::string name;
  int number;
};

#endif
