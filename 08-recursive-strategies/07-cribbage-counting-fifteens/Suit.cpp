#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "Card.h"
#include "Suit.h"

Suit operator++(Suit &s, int) {
  Suit old = s;
  s = Suit(s + 1);
  return old;
}

std::string suitToString(Suit s) {
  switch (s) {
  case CLUBS:
    return "C";
  case DIAMONDS:
    return "D";
  case HEARTS:
    return "H";
  case SPADES:
    return "S";
  default:
    return "";
  }
}
