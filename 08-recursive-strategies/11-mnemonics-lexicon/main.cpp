/* Programming Abstractions in C++
 *
 * Exercise 08-11
 *
 * Rewrite the program from exercise 4 so that it uses the Lexicon class and the
 * EnglishWords.dat file so that the program only lists mnemonics that are
 * valid English words.
 *
 * Solution 2021 Ben Mills
 *
 * Likely this is refering to the previous exercise (exercise 08-10) and
 * "exercise 4" is a typo.
 *
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/lexicon.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/vector.h"

void createKeypad(Vector<std::string> &keys);
void fillKeyPresses(Vector<std::string> pad, Vector<std::string> &presses,
                    std::string number);
std::string getMnemonics(Vector<std::string> &presses, std::string str,
                         int index);
Vector<std::string> buildVector(std::string str);

int main() {
  Lexicon english;
  english.addWordsFromFile("../../extras/dictionary.txt");
  std::string str = getLine("Enter a phone number: ");
  std::cout << "The valid dictionary mnemonics of \"" << str
            << "\" are:" << std::endl;
  Vector<std::string> keypad;
  Vector<std::string> keyPresses;
  createKeypad(keypad);
  fillKeyPresses(keypad, keyPresses, str);
  std::string mnemonics = getMnemonics(keyPresses, str, 0);
  Vector<std::string> candidates = buildVector(mnemonics);
  for (std::string element : candidates) {
    if (english.contains(element))
      std::cout << element << std::endl;
  }
  return 0;
}

std::string getMnemonics(Vector<std::string> &presses, std::string str,
                         int index) {
  if (index == presses.size())
    return str + " ";
  std::string output = "";
  for (int i = 0; i < presses[index].length(); i++) {
    str[index] = presses[index][i];
    output += getMnemonics(presses, str, index + 1);
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

// Converts a string of space separated mnemonics into a vector
Vector<std::string> buildVector(std::string str) {
  Vector<std::string> output;
  std::string temp = "";
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ') {
      output.add(temp);
      temp = "";
    } else {
      temp += str[i];
    }
  }
  return output;
}
