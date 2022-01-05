/* Programming Abstractions in C++
 *
 * Exercise 11-01
 *
 * As you know from the chapter, integers are represented inside the computer as
 * a sequence of bits, each of which is a single digit in the binary number
 * system and can therefore have only the value 0 or 1. With N bits, you can
 * represent 2N distinct integers. For example, three bits are sufficient to
 * represent the eight (23) integers between 0 and 7, as follows:
 *
 * 000 --> 0
 * 001 --> 1
 * 010 --> 2
 * 011 --> 3
 * 100 --> 4
 * 101 --> 5
 * 110 --> 6
 * 111 --> 7
 *
 * The bit patterns for these integers follow a recursive pattern. The binary
 * numbers with N bits consist of the following two sets in order:
 *
 *  • All binary numbers with N-1 bits preceded by a 0.
 *  • All binary numbers with N-1 bits preceded by a 1.
 *
 * Write a recursive function
 *
 *  void generateBinaryCode(int nBits);
 *
 * that generates the bit patterns for the binary representation of all integers
 * that can be represented using the specified number of bits. For example,
 * calling generateBinaryCode(3) should produce the following output:
 *
 *  <image of sample run>
 *
 * Solution 2021 Ben Mills
 *
 * Probably don't use a number over about 22ish
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/vector.h"

void generateBinaryCode(int nBits);
Vector<std::string> getBinaryCodes(Vector<std::string> &vec, int nBits);

int main() {
  std::cout << "This program generates all the integers represented in binary "
               "that fit in a given bit range."
            << std::endl;
  int bitSize = getInteger("Enter a number of bits to use: ");
  generateBinaryCode(bitSize);
  return 0;
}

Vector<std::string> getBinaryCodes(Vector<std::string> &vec, int nBits) {
  Vector<std::string> output;
  if (nBits == 0) {
    return Vector<std::string>(1);
  } else {
    Vector<std::string> temp = getBinaryCodes(vec, nBits - 1);
    for (int i = 0; i < temp.size(); i++) {
      output.add('0' + temp[i]);
    }
    for (int i = 0; i < temp.size(); i++) {
      output.add('1' + temp[i]);
    }
  }
  return output;
}

void generateBinaryCode(int nBits) {
  Vector<std::string> output;
  int count = 0;
  for (std::string s : getBinaryCodes(output, nBits)) {
    std::cout << s << " : " << count++ << std::endl;
  }
}
