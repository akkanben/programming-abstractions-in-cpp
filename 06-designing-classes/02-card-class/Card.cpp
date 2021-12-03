#include <iostream>
#include <string>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "Card.h"
#include "Suit.h"

Suit suitFromShortName(std::string shortName);
int rankFromShortName(std::string shortName);
std::string rankToString(int r);

Card::Card() {
  suit = CLUBS;
  rank = 2;
}

Card::Card(std::string shortName) {
  suit = suitFromShortName(shortName);
  rank = rankFromShortName(shortName);
}

Card::Card(int rank_i, Suit suit_i) {
  suit = suit_i;
  rank = rank_i;
}

std::string Card::toString() { return rankToString(rank) + suitToString(suit); }

int Card::getRank() { return rank; }

Suit Card::getSuit() { return suit; }

Suit suitFromShortName(std::string shortName) {
  char letter = shortName[shortName.length() - 1];
  switch (letter) {
  case 'C':
    return CLUBS;
  case 'D':
    return DIAMONDS;
  case 'H':
    return HEARTS;
  case 'S':
    return SPADES;
  default:
    error("Card: invalid suit.");
    return CLUBS;
  };
}

int rankFromShortName(std::string shortName) {
  std::string rankStr = shortName.substr(0, shortName.length() - 2);
  if (rankStr == "A")
    return ACE;
  else if (rankStr == "J")
    return JACK;
  else if (rankStr == "Q")
    return QUEEN;
  else if (rankStr == "K")
    return KING;
  else {
    int rankInt = stringToInteger(rankStr);
    if (rankInt > 0 && rankInt < 10)
      return rankInt;
    else
      error("Card: invalid rank.");
  }
  return -1;
}

std::string rankToString(int r) {
  switch (r) {
  case 1:
    return "A";
  case 11:
    return "J";
  case 12:
    return "Q";
  case 13:
    return "K";
  default:
    return integerToString(r);
  }
}

std::ostream &operator<<(std::ostream &os, Card c) {
  return os << c.toString();
}
