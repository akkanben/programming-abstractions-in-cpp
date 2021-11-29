/* Programming Abstractions in C++
 *
 * Exercise 03-15
 *
 * As written, the PigLatin program in Figure 3-2 behaves oddly if you enter a
 * string that includes words beginning with an uppercase letter. For example,
 * if you were to capitalize the first word in the sentence and the name of the
 * Pig Latin language, you would see the following output:
 *
 * "This is Pig Latin" >>> "isThay isway igPay atinLay"
 *
 * Rewrite the wordToPigLatin function so that any word that begins with a
 * capital letter in the English line still begins with a capital letter in Pig
 * Latin. Thus, after making your changes in the program, the output should look
 * like this:
 *
 * "This is Pig Latin" >>> "Isthay isway Igpay Atinlay"
 *
 *
 * Solution 2021 Ben Mills
 *
 */

#include "../../StanfordCPPLib/include/simpio.h"
#include <cctype>
#include <iostream>
#include <string>

std::string lineToPigLatin(std::string line);
std::string wordToPigLatin(std::string word);
int findFirstVowel(std::string word);
bool isVowel(char ch);

int main() {
  std::cout << "This program translates English to Pig Latin." << std::endl;
  std::string line;
  std::cout << "Enter English text: ";
  getline(std::cin, line);
  std::string translation = lineToPigLatin(line);
  std::cout << "Pig Latin output: " << translation << std::endl;
  return 0;
}

std::string lineToPigLatin(std::string line) {
  std::string result;
  int start = -1;
  for (int i = 0; i < line.length(); i++) {
    char ch = line[i];
    if (isalpha(ch)) {
      if (start == -1)
        start = i;
    } else {
      if (start >= 0) {
        result += wordToPigLatin(line.substr(start, i - start));
        start = -1;
      }
      result += ch;
    }
  }
  if (start >= 0)
    result += wordToPigLatin(line.substr(start));
  return result;
}

std::string wordToPigLatin(std::string word) {
  int vp = findFirstVowel(word);
  if (vp == -1) {
    return word;
  } else if (vp == 0) {
    return word + "way";
  } else {
    if (isupper(word[0])) {
      std::string head = word.substr(0, vp);
      std::string tail = word.substr(vp);
      head[0] = tolower(head[0]);
      tail[0] = toupper(tail[0]);
      return tail + head + "ay";
    }
    std::string head = word.substr(0, vp);
    std::string tail = word.substr(vp);
    return tail + head + "ay";
  }
}

int findFirstVowel(std::string word) {
  for (int i = 0; i < word.length(); i++) {
    if (isVowel(word[i]))
      return i;
  }
  return -1;
}

bool isVowel(char ch) {
  switch (ch) {
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
    return true;
  default:
    return false;
  }
}
