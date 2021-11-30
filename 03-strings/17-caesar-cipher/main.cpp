/* Programming Abstractions in C++
 *
 * Exercise 03-17
 *
 * If you played around with codes and ciphers as a child, the odds are good
 * that you at some point used a cyclic cipher—which is often called a Caesar
 * cipher because the Roman historian Suetonius records that Julius Caesar used
 * this technique—in which you replace each letter in the original message by
 * the letter that appears a fixed distance ahead in the alphabet. As an
 * example, suppose that you wanted to encode a message by shifting every letter
 * ahead three places. In this cipher, each A becomes an D, B becomes E, and so
 * on. If you reach the end of the alphabet, the process cycles around to the
 * beginning, so that X becomes A, Y becomes B, and Z becomes C.
 *
 * To implement a Caesar cipher, you should first define a function
 *
 *  string encodeCaesarCipher(string str, int shift);
 *
 * that returns a new string formed by shifting every letter in str forward the
 * number of letters indicated by shift, cycling back to the beginning of the
 * alphabet if necessary. After you have implemented encodeCaesarCipher,
 * write a program that generates the following sample run:
 *
 *  <image of sample run>
 *
 * Note that the transformation applies only to letters; any other characters
 * are copied unchanged to the output. Moreover, the case of letters is
 * unaffected: lowercase letters come out as lowercase, and uppercase letters
 * come out as uppercase. You should also write your program so that a negative
 * value of shift means that letters are shifted toward the beginning of the
 * alphabet instead of toward the end, as illustrated by the following sample
 * run:
 *
 *  <image of numbers not being effected>
 *
 *
 * Solution 2021 Ben Mills
 *
 * NOTE: ASCII lowercase = 97-122 and uppercase = 65-90
 *
 */

#include "../../StanfordCPPLib/include/simpio.h"
#include <cctype>
#include <iostream>
#include <string>

std::string encodeCaesarCipher(std::string str, int shift);

int main() {
  while (true) {
    int shift = getInteger("Enter the number of charater positions to shift: ");
    std::string str = getLine("Enter a message: ");
    if (str == "")
      break;
    std::cout << "Encoded message: " << encodeCaesarCipher(str, shift)
              << std::endl;
  }
  std::cout << "Program End." << std::endl;
  return 0;
}

std::string encodeCaesarCipher(std::string str, int shift) {
  std::string encoded = "";
  if (shift < 0) {
    // changes a negative shift into a positive value
    // (e.g. -1 --> 25, so 'a' becomes 'z')
    shift = shift % 26;
  }
  for (int i = 0; i < str.length(); i++) {
    if (isupper(str.at(i))) {
      encoded += ('A' + (str.at(i) - 'A' + shift) % 26);
    } else if (islower(str.at(i))) {
      encoded += ('a' + (str.at(i) - 'a' + shift) % 26);
    } else {
      encoded += str.at(i);
    }
  }
  return encoded;
}
