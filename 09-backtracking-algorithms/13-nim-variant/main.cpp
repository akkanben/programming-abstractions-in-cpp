/* Programming Abstractions in C++
 *
 * Exercise 09-13
 *
 * Modify the code for the simple Nim game you wrote for exercise 11 so that it
 * plays a different variant of Nim. In this version, the pile begins with 17
 * coins. On each turn, players alternate taking one, two, three, or four coins
 * from the pile. In the simple Nim game, the coins the players took away were
 * simply ignored; in this game, the coins go into a pile for each player. The
 * player whose pile contains an even number of coins after the last coin is
 * taken wins the game.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "../../StanfordCPPLib/include/vector.h"

enum Player { HUMAN, COMPUTER };

const int N_COINS = 17;
const int MAX_MOVE = 4;
const int WINNING_POSITION = 100;
const int LOSING_POSITION = -WINNING_POSITION;
const int MAX_DEPTH = 20;
const Player STARTING_PLAYER = HUMAN;

Player opponent(Player player) { return (player == HUMAN) ? COMPUTER : HUMAN; }

struct Move {
  int nTaken;
};

class Nim {

public:
  void play() {
    initGame();
    while (!gameIsOver()) {
      displayGame();
      if (getCurrentPLayer() == HUMAN) {
        makeMove(getUserMove());
      } else {
        Move move = getComputerMove();
        displayMove(move);
        makeMove(move);
      }
      switchTurn();
    }
    announceResult();
  }

  void printInsructions() {
    std::cout << "Welcome to the game of Nim!" << std::endl;
    std::cout << "In this game, we will start with a pile of" << std::endl;
    std::cout << N_COINS << " coins on the table.  On each turn, you"
              << std::endl;
    std::cout << "and I will alternately take between 1 and" << std::endl;
    std::cout << MAX_MOVE << " coins from the table.  The player who"
              << std::endl;
    std::cout << "has an even number of coins at the end wins." << std::endl
              << std::endl;
  }

private:
  void initGame() {
    nCoins = N_COINS;
    whoseTurn = STARTING_PLAYER;
  }

  bool gameIsOver() { return (nCoins == 0); }

  void displayGame() {
    std::cout << "There are " << nCoins << " coins left." << std::endl;
    std::cout << "You have " << playerCoins << " coins." << std::endl;
    std::cout << "I have " << computerCoins << " coins." << std::endl
              << std::endl;
  }

  Player getCurrentPLayer() { return whoseTurn; }

  void makeMove(int move) {
    nCoins -= move;
    playerCoins += move;
  }

  Move getComputerMove() { return findBestMove(); }

  void displayMove(Move move) {
    std::cout << "I'll take " << move.nTaken << "." << std::endl;
  }

  void makeMove(Move move) {
    nCoins -= move.nTaken;
    computerCoins += move.nTaken;
  }

  void switchTurn() { whoseTurn = opponent(whoseTurn); }

  Move findBestMove() {
    int rating;
    return findBestMove(0, rating);
  }

  Move findBestMove(int depth, int &rating) {
    Vector<Move> moveList;
    Move bestMove;
    int minRating = WINNING_POSITION + 1;
    generateMoveList(moveList);
    if (moveList.isEmpty())
      error("No moves available");
    for (Move move : moveList) {
      makeMove(move);
      int moveRating = evaluatePosition(depth + 1);
      if (moveRating < minRating) {
        bestMove = move;
        minRating = moveRating;
      }
      retractMove(move);
    }
    rating = -minRating;
    return bestMove;
  }

  int evaluatePosition(int depth) {
    if (gameIsOver() || depth >= MAX_DEPTH) {
      return evaluateStaticPosition();
    }
    int rating;
    findBestMove(depth, rating);
    return rating;
  }

  int getUserMove() {
    while (true) {
      int nTaken = getInteger("How many would you like: ");
      int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
      if (nTaken > 0 && nTaken <= limit)
        return nTaken;
      std::cout << "That's cheating! Please choose a number";
      std::cout << " between 1 and " << limit << "." << std::endl;
      std::cout << "There are " << nCoins << " coins in the pile." << std::endl;
    }
  }

  void generateMoveList(Vector<Move> &moveList) {
    Move move;
    int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
    for (int i = 1; i <= limit; i++) {
      move.nTaken = i;
      moveList.add(move);
    }
  }

  void retractMove(Move move) {
    nCoins += move.nTaken;
    computerCoins -= move.nTaken;
  }

  int evaluateStaticPosition() {
    if (playerCoins % 2 == 0) {
      return WINNING_POSITION;
    }
    if (computerCoins % 2 == 0) {
      return LOSING_POSITION;
    }
    return 0;
  }

  void announceResult() {
    if (playerCoins % 2 == 0) {
      std::cout << "Your pile of " << playerCoins << " is even.  You win."
                << std::endl;
    } else {
      std::cout << "Your pile of " << computerCoins << " is odd.  I win."
                << std::endl;
    }
  }

  int nCoins;
  int playerCoins = 0;
  int computerCoins = 0;
  Player whoseTurn;
};

int main() {
  Nim game;
  game.printInsructions();
  game.play();
  return 0;
}
