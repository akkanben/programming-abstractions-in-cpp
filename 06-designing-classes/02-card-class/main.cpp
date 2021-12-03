/* Programming Abstractions in C++
 *
 * Exercise
 *
 * Defines a Card class suitable for representing a standard playing card, which
 * is identified by two components: a rank and a suit. The rank is stored as an
 * integer between 1 and 13 in which an ace is a 1, a jack is an 11, a queen is
 * 12, and a king is 13. The suit is one of the four constants in the following
 * enumeration type:
 *
 * enum Suit = { CLUBS, DIAMONDS, HEARTS, SPADES };
 *
 * The Card class should export the following methods:
 *
 *  • A default constructor that creates a card that can later be assigned a
 *    value
 *  • A constructor that takes a short string name like "10S" or "JD"
 *  • A constructor that takes separate values for the rank and the suit
 *  • A toString method that returns the short string representation of the card
 *  • The getter methods getRank and getSuit
 *
 * Write the card.h interface and the card.cpp implementation necessary
 * to export the Card class. In addition to the Card class itself, the card.h
 * interface should export the Suit type, constant names for the ranks that are
 * usually named rather than numbered (ACE, JACK, QUEEN, KING), and any other
 * definitions you need to run the following main program:
 *
 *  int main() {
 *    for (Suit suit = CLUBS; suit <= SPADES; suit++) {
 *      for (int rank = ACE; rank <= KING; rank++) {
 *        cout << " " << Card(rank, suit);
 *      }
 *      cout << endl;
 *    }
 *    return 0;
 *  }
 *
 * This program should produce the following sample run:
 *
 * <image of sample run>
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "Card.h"

int main() {
  for (Suit suit = CLUBS; suit <= SPADES; suit++) {
    for (int rank = ACE; rank <= KING; rank++) {
      std::cout << " " << Card(rank, suit);
    }
    std::cout << std::endl;
  }
  return 0;
}
