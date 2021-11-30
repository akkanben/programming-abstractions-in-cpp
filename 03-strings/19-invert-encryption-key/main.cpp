/* Programming Abstractions in C++
 *
 * Exercise 03-19
 *
 * Using the definition of keys for letter-substitution ciphers as described in
 * the preceding problem, write a function invertKey that takes an encryption
 * key and returns the 26-letter key necessary to decrypt a message encoded with
 * that encryption key.
 *
 * Solution 2021 Ben Mills
 *
 *  Alphabet:               ABCDEFGHIJKLMNOPQRSTUVWXYZ
 *  Encryption Key:         QWERTYUIOPASDFGHJKLZXCVBNM
 *  Expected Inverted Key:  KXVMCNOPHQRSZYIJADLEGWBUFT
 *
 */

#include "../../StanfordCPPLib/include/simpio.h"
#include <cctype>
#include <iostream>
#include <string>

std::string encodeLetterSubCipher(std::string str, std::string key);
std::string invertKey(std::string key);

int main() {
  std::string myString = "WORKERS OF THE WORLD UNITE!";
  std::string myKey = "QWERTYUIOPASDFGHJKLZXCVBNM";
  std::string encryptedStr = encodeLetterSubCipher(myString, myKey);
  std::string invertedKey = invertKey(myKey);
  std::cout << "Original string:          " << myString << std::endl;
  std::cout << "Encryption key:           " << myKey << std::endl;
  std::cout << "Encrypted string:         " << encryptedStr << std::endl;
  std::cout << "Inverted key:             " << invertedKey << std::endl;
  std::cout << "String from inverted key: "
            << encodeLetterSubCipher(encryptedStr, invertedKey) << std::endl;
  return 0;
}

std::string encodeLetterSubCipher(std::string str, std::string key) {
  std::string encoded;
  for (int i = 0; i < str.length(); i++) {
    int strPosToEncode = str.at(i) - 'A';
    if (isupper(str.at(i)))
      encoded += key.at(strPosToEncode);
    else
      encoded += str.at(i);
  }
  return encoded;
}

std::string invertKey(std::string key) {
  std::string decryptionKey;
  for (int i = 0; i < key.length(); i++) {
    int keyPos = key.find('A' + i, 1);
    if (keyPos == -1)
      decryptionKey += 'A';
    else
      decryptionKey += keyPos + 'A';
  }
  return decryptionKey;
}
