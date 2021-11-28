/* Programming Abstractions in C++
 *
 * Exercise 03-05
 *
 * In most word games, each letter in a word is scored according to its point
 * value, which is inversely proportional to its frequency in English words. In
 * ScrabbleTM, the points are allocated as follows:
 *
 * 01: A, E, I, L, N, O, R, S, T, U
 * 02: D, G
 * 03: B, C, M, P
 * 04: F, H, V, W, Y
 * 05: K
 * 08: J, X
 * 10: Q, Z
 *
 * For example, the word "FARM" is worth 9 points in Scrabble: 4 for the F, 1
 * each for the A and the R, and 3 for the M. Write a program that reads in
 * words and prints out their score in Scrabble, not counting any of the other
 * bonuses that occur in the game. You should ignore any characters other than
 * uppercase letters in computing the score. In particular, lowercase letters
 * are assumed to represent blank tiles, which can stand for any letter but have
 * a score of 0.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

int getScrabbleScore(std::string word);

int main() {
  std::cout << "FARM is worth " << getScrabbleScore("FARM") << " points."
            << std::endl;
  std::cout << "POTATO is worth " << getScrabbleScore("POTATO") << " points."
            << std::endl;
  std::cout << "EXPRESS is worth " << getScrabbleScore("EXPRESS") << " points."
            << std::endl;
  std::cout << "ExPRESS is worth " << getScrabbleScore("ExPRESS") << " points."
            << std::endl;
  std::cout << "LETTER is worth " << getScrabbleScore("LETTER") << " points."
            << std::endl;
  std::cout << "hELLO is worth " << getScrabbleScore("hELLO") << " points."
            << std::endl;
}

int getScrabbleScore(std::string word) {
  int score = 0;
  for (int i = 0; i < word.length(); i++) {
    if (isupper(word.at(i))) {
      switch (word.at(i)) {
      case 'Q':
      case 'Z':
        score += 10;
        break;
      case 'J':
      case 'X':
        score += 8;
        break;
      case 'K':
        score += 5;
        break;
      case 'F':
      case 'H':
      case 'V':
      case 'W':
      case 'Y':
        score += 4;
        break;
      case 'B':
      case 'C':
      case 'M':
      case 'P':
        score += 3;
        break;
      case 'D':
      case 'G':
        score += 2;
        break;
      default:
        score += 1;
        break;
      }
    }
  }

  return score;
}
