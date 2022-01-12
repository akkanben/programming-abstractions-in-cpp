/* Programming Abstractions in C++
 *
 * Exercise 12-10
 *
 * As a preliminary test of the MyString class from exercise 9, rewrite the Pig
 * Latin program from Figure 3-2 on page 143 so that it uses MyString instead
 * of string.
 *
 * Solution 2021 Ben Mills
 */

#include <cctype>
#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/simpio.h"
#include "MyString.h"

MyString lineToPigLatin(MyString line);
MyString wordToPigLatin(MyString word);
int findFirstVowel(MyString word);
bool isVowel(char ch);

int main() {
  std::cout << "This program translates English to Pig Latin." << std::endl;
  MyString line = MyString(getLine("Enter English text: "));
  MyString translation = lineToPigLatin(line);
  std::cout << "Pig Latin output: " << translation << std::endl;
  return 0;
}

MyString lineToPigLatin(MyString line) {
  MyString result = MyString("");
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

MyString wordToPigLatin(MyString word) {
  int vp = findFirstVowel(word);
  if (vp == -1) {
    return word;
  } else if (vp == 0) {
    return word + MyString("way");
  } else {
    MyString head = word.substr(0, vp);
    MyString tail = word.substr(vp);
    return MyString(tail + head + MyString("ay"));
  }
}

int findFirstVowel(MyString word) {
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
