#ifndef _suit_h
#define _suit_h

#include <string>

int const ACE = 1;
int const JACK = 11;
int const QUEEN = 12;
int const KING = 13;

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

std::string suitToString(Suit s);

#endif
