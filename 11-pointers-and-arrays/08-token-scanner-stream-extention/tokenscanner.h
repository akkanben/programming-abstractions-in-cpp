
#ifndef _tokenscanner_h
#define _tokenscanner_h

#include <string>

class TokenScanner {

public:
  TokenScanner();
  TokenScanner(std::string str);
  TokenScanner(std::istream &infile);
  void setInput(std::string str);
  void setInput(std::istream &infile);
  bool hasMoreTokens();
  std::string nextToken();
  void ignoreWhitespace();

private:
  std::string buffer;
  std::istream *streamPtr;
  int cp;
  bool isStreamInput;
  bool ignoreWhitespaceFlag;
  void skipWhitespace();
};

#endif
