/* Programming Abstractions in C++
 *
 * Exercise 08-12
 *
 * These days, the letters on a telephone keypad are not used for mnemonics as
 * much as they are for texting. Entering text using a keypad is problematic,
 * because there are fewer keys than there are letters in the alphabet. Some
 * cell phones use a “multi-tap” user interface, in which you tap the 2 key once
 * for a, twice for b, and three times for c, which can get tedious. A
 * streamlined alternative is to use a predictive strategy in which the cell
 * phone guesses which of the possible letter you intended, based on the
 * sequence so far and its possible completions.
 *
 * For example, if you type the digit sequence 72, there are 12 possibilities:
 * pa, pb, pc, qa, qb, qc, ra, rb, rc, sa, sb, and sc. Only four of these letter
 * pairs—pa, ra, sa, and sc—seem promising because they are prefixes of
 * common English words like party, radio, sandwich, and scanner. The
 * others can be ignored because there are no common words that begin with
 * those sequences of letters. If the user enters 9956, there are 144 (4 x 4 x 3
 * x 3) possible letter sequences, but you can be assured the user meant xylo
 * since that is the only sequence that is a prefix of any English words.
 *
 * Write a function
 *
 *  void listCompletions(string digits, Lexicon & lex);
 *
 * that prints all words from the lexicon that can be formed by extending the
 * given digit sequence. For example, calling
 *
 *  listCompletions("72547", english)
 *
 * should generate the following sample run:
 *
 *  <image of sample run>
 *
 * If your only concern is getting the answer, the easiest way to solve this
 * problem is to iterate through the words in the lexicon and print out each
 * word that matches the specified digit string. That solution requires no
 * recursion and very little thinking. Your managers, however, believe that
 * looking through every word in the dictionary is slow and insist that your
 * code use the lexicon only to test whether a given string is a word or a
 * prefix of an English word. With that restriction, you need to figure out how
 * to generate all possible letter sequences from the string of digits. That
 * task is easiest to solve recursively.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/lexicon.h"
#include "../../StanfordCPPLib/include/set.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/vector.h"

void createKeypad(Vector<std::string> &keys);
void fillKeyPresses(Vector<std::string> pad, Vector<std::string> &presses,
                    std::string number);
std::string getMnemonics(Lexicon &lex, Set<std::string> &failed,
                         Set<std::string> &success,
                         Vector<std::string> &presses, std::string str,
                         int index);
void listCompletions(std::string digits, Lexicon &lex);
std::string findCompletions(Lexicon dictionary, Vector<std::string> completions,
                            Set<std::string> &failed, Set<std::string> &success,
                            std::string str, int index);

int main() {
  Lexicon english;
  english.addWordsFromFile("../../extras/dictionary.txt");
  std::string str = getLine("Enter a multi-tap sequence of digits: ");
  listCompletions(str, english);
  return 0;
}

// The failed and success sets are used to reduce the number of lexicon lookups

void listCompletions(std::string digits, Lexicon &lex) {
  Vector<std::string> keypad;
  Vector<std::string> keyPresses;
  createKeypad(keypad);
  fillKeyPresses(keypad, keyPresses, digits);
  Set<std::string> failed;
  Set<std::string> success;
  getMnemonics(lex, failed, success, keyPresses, digits, 0);
  Vector<std::string> completions;
  for (std::string element : success) {
    if (element.length() == digits.length()) {
      completions.add(element);
    }
  }
  failed.clear();
  success.clear();
  std::cout << "The valid dictionary prefix mnemonics of \"" << digits
            << "\" are:" << std::endl;
  std::cout << completions << std::endl;
  std::cout << findCompletions(lex, completions, failed, success, "", 0)
            << std::endl;
}

std::string findCompletions(Lexicon dictionary, Vector<std::string> completions,
                            Set<std::string> &failed, Set<std::string> &success,
                            std::string str, int index) {
  std::string output = "";
  if (index == completions.size()) {
    return output;
  }
  if (str == "") {
    str = completions[index];
    if (!success.contains(completions[index]) &&
        dictionary.contains(completions[index])) {
      success.add(completions[index]);
      std::cout << "Intial Valid Word:    " << completions[index] << std::endl;
    }
  }
  for (char i = 'A'; i <= 'Z'; i++) {
    std::string temp = str + i;
    if (!failed.contains(temp) && !success.contains(temp) &&
        dictionary.containsPrefix(temp)) {
      success.add(temp);
      if (dictionary.contains(temp))
        std::cout << "Possible Completions: " << temp << std::endl;
      output += findCompletions(dictionary, completions, failed, success, temp,
                                index);
    } else {
      failed.add(temp);
    }
  }
  output +=
      findCompletions(dictionary, completions, failed, success, "", index + 1);
  return output;
}

std::string getMnemonics(Lexicon &lex, Set<std::string> &failed,
                         Set<std::string> &success,
                         Vector<std::string> &presses, std::string str,
                         int index) {
  if (index == presses.size())
    return "";
  std::string output = "";
  for (int i = 0; i < presses[index].length(); i++) {
    str[index] = presses[index][i];
    std::string test = str.substr(0, index + 1);
    if (!failed.contains(test) && !success.contains(test) &&
        lex.containsPrefix(test)) {
      success.add(test);
      output += getMnemonics(lex, failed, success, presses, str, index + 1);
    } else
      failed.add(test);
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
