#ifndef _card_h
#define _card_h

#include <iostream>
#include <string>

#include "Suit.h"

class Card {
private:
  Suit suit;
  int rank;

public:
  Card();
  Card(std::string shortName);
  Card(int rank_i, Suit suit_i);
  std::string toString();
  int getRank();
  Suit getSuit();
};

std::ostream &operator<<(std::ostream &os, Card c);

#endif
