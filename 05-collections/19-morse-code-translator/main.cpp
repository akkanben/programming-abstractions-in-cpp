/* Programming Abstractions in C++
 *
 * Exercise
 *
 * In May of 1844, Samuel F. B. Morse sent the message “What hath God
 * wrought!” by telegraph from Washington to Baltimore, heralding the
 * beginning of the age of electronic communication. To make it possible to
 * communicate information using only the presence or absence of a single tone,
 * Morse designed a coding system in which letters and other symbols are
 * represented as coded sequences of short and long tones, traditionally called
 * dots and dashes. In Morse code, the 26 letters of the alphabet are
 * represented by the codes shown in Figure 5-15.
 *
 * Write a program that reads in lines from the user and translates each line
 * either to or from Morse code depending on the first character of the line:
 *
 *  • If the line starts with a letter, you want to translate it to Morse code.
 * Any characters other than the 26 letters should simply be ignored. • If the
 * line starts with a period (dot) or a hyphen (dash), it should be read as a
 * series of Morse code characters that you need to translate back to letters.
 *    Each sequence of dots and dashes is separated by spaces, but any other
 *    characters should be ignored. Because there is no encoding for the space
 *    between words, the characters of the translated message will be run
 *    together when your program translates in this direction.
 *
 * The program should end when the user enters a blank line. A sample run of
 * this program (taken from the messages between the Titanic and the Carpathia
 * in 1912) might look like this:
 *
 * Solution 2021 Ben Mills
 */

#include <cctype>
#include <stdio.h>
#include <string.h>

#include "../../StanfordCPPLib/include/map.h"
#include "../../StanfordCPPLib/include/simpio.h"

void initMaps(Map<string, string> &toMorse, Map<string, string> &fromMorse);
void transFromMorse(string line, Map<string, string> fromMorse);
void transToMorse(string line, Map<string, string> toMorse);
void printMaps(Map<string, string> toMorse, Map<string, string> fromMorse);

int main() {
  Map<string, string> toMorse;
  Map<string, string> fromMorse;
  initMaps(toMorse, fromMorse);
  printMaps(toMorse, fromMorse);
  std::cout << "MORSE CODE TRANSLATOR" << std::endl;
  while (true) {
    string line = getLine("> ");
    if (line.at(0) == '-' || line.at(0) == '.') {
      transFromMorse(line, fromMorse);
    } else if (isalpha(line.at(0))) {
      transToMorse(line, toMorse);
    } else {
      std::cout << "Only dots dashes or alpha please!" << std::endl;
    }
  }
}

void initMaps(Map<string, string> &toMorse, Map<string, string> &fromMorse) {
  // To
  toMorse.put("A", ".-");
  toMorse.put("B", "-...");
  toMorse.put("C", "-.-.");
  toMorse.put("D", "-..");
  toMorse.put("E", ".");
  toMorse.put("F", "..-.");
  toMorse.put("G", "--.");
  toMorse.put("H", "....");
  toMorse.put("I", "..");
  toMorse.put("J", ".---");
  toMorse.put("K", "-.-");
  toMorse.put("L", ".-..");
  toMorse.put("M", "--");
  toMorse.put("N", "-.");
  toMorse.put("O", "---");
  toMorse.put("P", ".--.");
  toMorse.put("Q", "--.-");
  toMorse.put("R", ".-.");
  toMorse.put("S", "...");
  toMorse.put("T", "-");
  toMorse.put("U", "..-");
  toMorse.put("V", "...-");
  toMorse.put("W", ".--");
  toMorse.put("X", "-..-");
  toMorse.put("Y", "-.--");
  toMorse.put("Z", "--..");
  // From
  fromMorse.put(".-", "A");
  fromMorse.put("-...", "B");
  fromMorse.put("-.-.", "C");
  fromMorse.put("-..", "D");
  fromMorse.put(".", "E");
  fromMorse.put("-...", "F");
  fromMorse.put("--.", "G");
  fromMorse.put("....", "H");
  fromMorse.put("..", "I");
  fromMorse.put(".---", "J");
  fromMorse.put("-.-", "K");
  fromMorse.put(".-..", "L");
  fromMorse.put("--", "M");
  fromMorse.put("-.", "N");
  fromMorse.put("---", "O");
  fromMorse.put(".--.", "P");
  fromMorse.put("--.-", "Q");
  fromMorse.put(".-.", "R");
  fromMorse.put("...", "S");
  fromMorse.put("-", "T");
  fromMorse.put("..-", "U");
  fromMorse.put("...-", "V");
  fromMorse.put(".--", "W");
  fromMorse.put("-..-", "X");
  fromMorse.put("-.--", "Y");
  fromMorse.put("--..", "Z");
}

void transFromMorse(string line, Map<string, string> fromMorse) {
  string letterPieces = "";
  string fullLetter = "";
  for (int i = 0; i < line.length(); i++) {
    if (line.at(i) != ' ') {
      letterPieces += line.at(i);
    } else {
      fullLetter += fromMorse.get(letterPieces);
      cout << fullLetter;
      letterPieces = "";
      fullLetter = "";
    }
  }
  fullLetter += fromMorse.get(letterPieces);
  std::cout << fullLetter << std::endl;
}

void transToMorse(string line, Map<string, string> toMorse) {
  string translation;
  for (int i = 0; i < line.length(); i++) {
    string letter = "";
    letter += line.at(i);
    translation += toMorse.get(letter);
    translation += ' ';
  }
  std::cout << translation << std::endl;
}

void printMaps(Map<string, string> toMorse, Map<string, string> fromMorse) {
  for (int i = 0; i < 26; i++) {
    char ch = 'A' + i;
    string letter = "";
    letter += ch;
    std::cout << ch << " : " << toMorse.get(letter) << " " << std::endl;
  }
}
