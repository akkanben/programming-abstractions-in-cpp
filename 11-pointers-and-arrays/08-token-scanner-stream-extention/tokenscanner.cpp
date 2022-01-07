#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

#include "tokenscanner.h"

TokenScanner::TokenScanner() {
  // Empty
}

TokenScanner::TokenScanner(std::string str) { setInput(str); }

TokenScanner::TokenScanner(std::istream &infile) { setInput(infile); }

void TokenScanner::setInput(std::string str) {
  buffer = str;
  cp = 0;
}

void TokenScanner::setInput(std::istream &infile) {
  streamPtr = &infile;
  isStreamInput = true;
}

bool TokenScanner::hasMoreTokens() {
  if (ignoreWhitespaceFlag) {
    skipWhitespace();
  }
  if (isStreamInput) {
    char next = streamPtr->get();
    if (next != EOF) {
      streamPtr->unget();
      return true;
    }
    return false;
  } else
    return cp < buffer.length();
}

std::string TokenScanner::nextToken() {
  if (ignoreWhitespaceFlag)
    skipWhitespace();
  if (isStreamInput) {
    std::string token = "";
    char next = streamPtr->get();
    if (!std::isalnum(next)) {
      token += next;
      return token;
    } else {
      streamPtr->unget();
    }
    while (streamPtr->get(next) && std::isalnum(next)) {
      token += next;
    }
    if (!std::isalnum(next))
      streamPtr->unget();
    return token;
  } else {
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

void TokenScanner::ignoreWhitespace() { ignoreWhitespaceFlag = true; }

void TokenScanner::skipWhitespace() {
  if (isStreamInput) {
    while (true) {
      char next = streamPtr->get();
      if (next == EOF)
        return;
      if (!isspace(next)) {
        streamPtr->unget();
        return;
      }
    }
  } else {
    while (cp < buffer.length() && isspace(buffer[cp])) {
      cp++;
    }
  }
}
