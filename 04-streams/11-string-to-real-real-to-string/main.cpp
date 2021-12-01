/* Programming Abstractions in C++
 *
 * Exercise 04-11
 *
 * Using the functions stringToInteger and integerToString as a model,
 * write the code necessary to implement stringToReal and realToString.
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/error.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>

double stringToReal(std::string str);
std::string realToString(double real);

int main() {
  std::string realTest = realToString(3.1415);
  double stringTest = stringToReal("0.0005");
  std::cout << "realToString(3.1415) Result: " << realTest << std::endl;
  std::cout << "realToString(3.1415) Type: " << typeid(realTest).name()
            << std::endl;
  std::cout << "stringToReal(\"0.005\") Result: " << stringTest << std::endl;
  std::cout << "stringToReal(\"0.005\") Type: " << typeid(stringTest).name()
            << std::endl;
  return 0;
}

double stringToReal(std::string str) {
  std::istringstream stream(str);
  double value;
  stream >> value >> std::ws;
  if (stream.fail() || !stream.eof()) {
    error("stringToReal: Illegal real format.");
  }
  return value;
}

std::string realToString(double real) {
  std::ostringstream stream;
  stream << real;
  return stream.str(); // the book says this "str()" function copies and returns
                       // the stream as a string
}
