/* Programming Abstractions in C++
 *
 * Exercise 03-18
 *
 * Although they are certainly simple, Caesar ciphers are also extremely easy to
 * break. There are, after all, only 25 values for the number of characters to
 * shift. If you want to break a Caesar cipher, all you have to do is try each
 * of the 25 possibilities and see which one translates the original message
 * into something readable. A better scheme is to allow each letter in the
 * original message to be represented by an arbitrary letter instead of one a
 * fixed distance from the original. In this case, the key for the encoding
 * operation is a translation table that shows what each of the 26 letters
 * becomes in the encrypted form. Such a coding scheme is called a
 * letter-substitution cipher.
 *
 * The key in a letter-substitution cipher is a 26-character string that
 * indicates the translation for each character in the alphabet in order. For
 * example, the key "QWERTYUIOPASDFGHJKLZXCVBNM" indicates that the encoding
 * process should use the following translation rule:
 *
 *  ABCDEFGHIJKLMNOPQRSTUVWXYZ
 *  ||||||||||||||||||||||||||
 *  QWERTYUIOPASDFGHJKLZXCVBNM
 *
 * Write a program that implements encryption using a letter-substitution
 * cipher. Your program should be able to duplicate the following sample run:
 *
 *  <image of sample run>
 *
 * Solution 2021 Ben Mills
 */

#include "../../StanfordCPPLib/include/simpio.h"
#include <cctype>
#include <iostream>
#include <string>

std::string encodeLetterSubCipher(std::string str, std::string key);

int main() {
  while (true) {
    std::string key = getLine("Enter 26-letter key: ");
    std::string str = getLine("Enter a message: ");
    if (str == "")
      break;
    std::cout << "Encoded message: " << encodeLetterSubCipher(str, key)
              << std::endl;
  }
  std::cout << "Program End.";
  return 0;
}

std::string encodeLetterSubCipher(std::string str, std::string key) {
  std::string encoded;
  for (int i = 0; i < str.length(); i++) {
    if (isupper(str.at(i)))
      encoded += key.at(str.at(i) - 'A');
    else
      encoded += str.at(i);
  }
  return encoded;
}
