/* Programming Abstractions in C++
 *
 * Exercise 08-10
 *
 * On a telephone keypad, the digits are mapped onto the alphabet as shown in
 * the diagram below:
 *
 *  <image of keypad>
 *
 * In order to make their phone numbers more memorable, service providers like
 * to find numbers that spell out some word (called a mnemonic) appropriate to
 * their business that makes that phone number easier to remember.
 *
 * Imagine that you have just been hired by a local telephone company to
 * write a function listMnemonics that will generate all possible letter
 * combinations that correspond to a given number, represented as a string of
 * digits. For example, the call
 *
 *  listMnemonics("723")
 *
 * should list the following 36 possible letter combinations that correspond to
 * that prefix:
 *
 *  PAD PBD PCD QAD QBD QCD RAD RBD RCD SAD SBD SCD
 *  PAE PBE PCE QAE QBE QCE RAE RBE RCE SAE SBE SCE
 *  PAF PBF PCF QAF QBF QCF RAF RBF RCF SAF SBF SCF
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "../../StanfordCPPLib/include/vector.h"

void createKeypad(Vector<std::string> &keys);
void fillKeyPresses(Vector<std::string> pad, Vector<std::string> &presses,
                    std::string number);
void listMnemonics(std::string str);
std::string printMnemonics(Vector<std::string> &presses, std::string str,
                           int index);

int main() {
  std::string str = getLine("Enter a phone number: ");
  std::cout << "The mnemonics of \"" << str << "\" are:" << std::endl;
  listMnemonics(str);
  return 0;
}

void listMnemonics(std::string str) {
  Vector<std::string> keypad;
  Vector<std::string> keyPresses;
  createKeypad(keypad);
  fillKeyPresses(keypad, keyPresses, str);
  std::cout << printMnemonics(keyPresses, str, 0) << std::endl;
}

std::string printMnemonics(Vector<std::string> &presses, std::string str,
                           int index) {
  if (index == presses.size())
    return str + " ";
  std::string output = "";
  for (int i = 0; i < presses[index].length(); i++) {
    str[index] = presses[index][i];
    output += printMnemonics(presses, str, index + 1);
  }
  return output;
}

void fillKeyPresses(Vector<std::string> pad, Vector<std::string> &presses,
                    std::string number) {
  for (int i = 0; i < number.length(); i++) {
    int index = number[i] - '0';
    if (index > 9 || index < 0) {
      std::string other = number.substr(i, 1);
      presses.add(other);
    } else
      presses.add(pad[index]);
  }
}

void createKeypad(Vector<std::string> &keys) {
  keys.add("0");
  keys.add("1");
  keys.add("ABC");
  keys.add("DEF");
  keys.add("GHI");
  keys.add("JKL");
  keys.add("MNO");
  keys.add("PQRS");
  keys.add("TUV");
  keys.add("WXYZ");
}
