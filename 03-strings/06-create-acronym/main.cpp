/* Programming Abstractions in C++
 *
 * Exercise 03-06
 *
 * An acronym is a new word formed by combining, in order, the initial letters
 * of a series of words. For example, the word scuba is an acronym formed from
 * the first letters in self-contained underwater breathing apparatus.
 * Similarly, AIDS is an acronym for Acquired Immune Deficiency Syndrome.
 *
 * Write a function acronym that takes a string and returns the acronym formed
 * from that string. To ensure that your function treats hyphenated compounds
 * like self-contained as two words, it should define the beginning of a word as
 * any alphabetic character that appears either at the beginning of the string
 * or after a nonalphabetic character.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

std::string const phrases[8] = {
    "In real life",
    "Self-contained underwater breathing apparatus",
    "In my humble opinion",
    "What do you mean by that",
    "Too long didn\'t read",
    "Completely automated public turing test to tell computers and humans "
    "apart",
    "Graphics interchange format",
    "Don\'t forget to be awesome",
};

std::string acronymGenerator(std::string line);

int main() {
  int phrasesLength = sizeof phrases / sizeof phrases[0];
  for (int i = 0; i < phrasesLength; i++) {
    std::cout << "\"" << phrases[i] << "\""
              << " as an acronym is " << acronymGenerator(phrases[i])
              << std::endl;
  }
}

std::string acronymGenerator(std::string line) {
  std::string acronym;
  for (int i = 0; i < line.length(); i++) {
    if (i == 0) {
      acronym += toupper(line.at(i));
    } else if (!isalpha(line.at(i)) && line.at(i) != '\'') {
      acronym += toupper(line.at(i + 1));
    }
  }
  return acronym;
}
