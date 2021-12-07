#include <cctype>
#include <string>

#include "tokenscanner.h"

TokenScanner::TokenScanner() {
  // Empty
}

TokenScanner::TokenScanner(string str) { setInput(str); }

void TokenScanner::setInput(string str) {
  buffer = str;
  cp = 0;
}

bool TokenScanner::hasMoreTokens() {
  if (ignoreWhitespaceFlag) {
    skipWhitespace();
  }
  return cp < buffer.length();
}

string TokenScanner::nextToken() {
  if (!savedTokens.isEmpty()) {
    return savedTokens.pop();
  } else {
    if (ignoreWhitespaceFlag)
      skipWhitespace();
    if (scanStringsFlag && buffer[cp] == '"')
      return gatherString();
    if (scanNumbersFlag && isdigit(buffer[cp]))
      return gatherNumber();
    if (cp >= buffer.length()) {
      return "";
    } else if (isalnum(buffer[cp])) {
      int start = cp;
      while (cp < buffer.length() && isalnum(buffer[cp])) {
        cp++;
      }
      return buffer.substr(start, cp - start);
    } else {
      return std::string(1, buffer[cp++]);
    }
  }
}

void TokenScanner::saveToken(std::string str) { savedTokens.push(str); }

void TokenScanner::ignoreWhitespace() { ignoreWhitespaceFlag = true; }

void TokenScanner::scanStrings() { scanStringsFlag = true; }

void TokenScanner::scanNumbers() { scanNumbersFlag = true; }

void TokenScanner::skipWhitespace() {
  while (cp < buffer.length() && isspace(buffer[cp])) {
    cp++;
  }
}

std::string TokenScanner::gatherString() {
  std::string output = "";
  while (cp < buffer.length()) {
    output += buffer[cp];
    cp++;
    if (buffer[cp] == '"') {
      output += buffer[cp];
      cp++;
      break;
    }
  }
  return output;
}

std::string TokenScanner::gatherNumber() {
  std::string output = "";
  bool done = false;
  while (cp < buffer.length() && !done) {
    if (buffer[cp] == '.') {
      output += buffer[cp];
      cp++;
      while (cp < buffer.length() && !done) {
        if (buffer[cp] == 'E') {
          output += buffer[cp];
          cp++;
          if (buffer[cp] == '+' || buffer[cp] == '-') {
            output += buffer[cp];
            cp++;
          }
          while (cp < buffer.length() && !done) {
            if (isdigit(buffer[cp])) {
              output += buffer[cp];
              cp++;
            } else
              done = true;
          }
        }
        if (isdigit(buffer[cp])) {
          output += buffer[cp];
          cp++;
        } else
          done = true;
      }
    }
    if (isdigit(buffer[cp])) {
      output += buffer[cp];
      cp++;
    } else
      done = true;
  }
  return output;
}
