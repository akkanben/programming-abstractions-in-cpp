
#ifndef _tokenscanner_h
#define _tokenscanner_h

#include <string>

#include "../../StanfordCPPLib/include/stack.h"

enum TokenType { SEPARATOR, WORD, NUMBER, STRING, OPERATOR };

class TokenScanner {

public:
  TokenScanner();
  TokenScanner(std::string str);
  void setInput(std::string str);
  bool hasMoreTokens();
  std::string nextToken();
  void saveToken(std::string token);
  void ignoreWhitespace();
  void scanStrings();

private:
  std::string buffer;
  int cp;
  bool ignoreWhitespaceFlag;
  bool scanStringsFlag;
  Stack<std::string> savedTokens;

  void skipWhitespace();
  std::string gatherString();
};

#endif
