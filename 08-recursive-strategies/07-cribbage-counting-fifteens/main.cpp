/* Programming Abstractions in C++
 *
 * Exercise 08-07
 *
 * In the card game called Cribbage, part of the game consists of adding up the
 * score from a set of five playing cards. One of the components of the score is
 * the number of distinct card combinations whose values add up to 15, with aces
 * counting as 1 and all face cards (jacks, queens, and kings) counting as 10.
 * Consider, for example, the following cards:
 *
 * .-------.  .-------.  .-------.  .-------.  .-------.
 * | A     |  | 5     |  | 10    |  | 4     |  | 9     |
 * |       |  |       |  |       |  |       |  |       |
 * | diamo |  | clubs |  | spade |  | heart |  | clubs |
 * |       |  |       |  |       |  |       |  |       |
 * |     A |  |     5 |  |    10 |  |     4 |  |     9 |
 * '-------'  '-------'  '-------'  '-------'  '-------'
 *
 *
 * There are three different combinations that sum to 15, as follows:
 *
 * AD + 10S + 4H   AD + 5C + 9C    5C + 10S
 *
 * As a second example, the cards
 *
 * .-------.  .-------.  .-------.  .-------.  .-------.
 * | 5     |  | 5     |  | 5     |  | 5     |  | J     |
 * |       |  |       |  |       |  |       |  |       |
 * | clubs |  | diamo |  | heart |  | spade |  | clubs |
 * |       |  |       |  |       |  |       |  |       |
 * |     5 |  |    5  |  |     5 |  |     5 |  |     J |
 * '-------'  '-------'  '-------'  '-------'  '-------'
 *
 * contain the following eight different combinations that add up to 15:
 *
 * 5C + JC        5D + JC         5H + JC         5S + JC
 * 5C + 5D + 5H   5C + 5D + 5S    5C + 5H + 5S    5D + 5H + 5S
 *
 * Write a function
 *
 *  int countFifteens(Vector<Card> & cards);
 *
 * that takes a vector of Card values (as defined in Chapter 6, exercise 2) and
 * returns the number of ways you can make 15 from that set of cards. You don’t
 * need to know much about the Card class to solve this problem. The only
 * thing you need is the getRank method, which returns the rank of the card as
 * an integer. You may assume that the card.h interface exports the constant
 * names ACE, JACK, QUEEN, and KING with the values 1, 11, 12, and 13,
 * respectively.
 *
 * Solution 2021 Ben Mills
 *
 */

#include <iostream>

#include "../../StanfordCPPLib/include/vector.h"
#include "Card.h"

int countFifteens(Vector<Card> &cards);
int subsetFifteenCount(Vector<Card> cards, int total);
std::string handToString(Vector<Card> cards);

int main() {
  Vector<Card> handA;
  Vector<Card> handB;
  handA += Card(ACE, DIAMONDS), Card(5, CLUBS), Card(10, SPADES),
      Card(4, HEARTS), Card(9, CLUBS);
  handB += Card(5, DIAMONDS), Card(5, CLUBS), Card(5, SPADES), Card(5, HEARTS),
      Card(JACK, CLUBS);
  std::cout << "Cribbage Hands -- Counting Fifteens" << std::endl;
  std::cout << "Hand A: " << handToString(handA) << " has "
            << countFifteens(handA) << " fifteens." << std::endl;
  std::cout << "Hand B: " << handToString(handB) << " has "
            << countFifteens(handB) << " fifteens." << std::endl;
  return 0;
}

int countFifteens(Vector<Card> &cards) {
  int total = 0;
  return subsetFifteenCount(cards, total);
}

int subsetFifteenCount(Vector<Card> cards, int total) {
  if (cards.isEmpty())
    return total == 15 ? 1 : 0;
  else {
    int element = cards[0].getRank();
    if (element > 10)
      element = 10;
    Vector<Card> rest = cards;
    rest.remove(0);
    total += element;
    return subsetFifteenCount(rest, total) +
           subsetFifteenCount(rest, total - element);
  }
}

std::string handToString(Vector<Card> cards) {
  std::string output = "[";
  for (int i = 0; i < cards.size(); i++) {
    output += cards[i].toString();
    if (i != cards.size() - 1)
      output += " ";
  }
  output += "]";
  return output;
}
