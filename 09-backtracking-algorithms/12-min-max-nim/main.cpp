/* Programming Abstractions in C++
 *
 * Exercise 09-12
 *
 * Rewrite the simple Nim game so that it uses the generalized minimax
 * algorithm presented in Figure 9-6. Your program should not change the code
 * for findBestMove or evaluatePosition. Your job is to come up with an
 * appropriate definition of the Move type and the various game-specific methods
 * so that the program still plays a perfect game of Nim.
 *
 * Solution 2021 Ben Mills
 */

#include <iostream>

#include "../../StanfordCPPLib/include/error.h"
#include "../../StanfordCPPLib/include/simpio.h"
#include "../../StanfordCPPLib/include/strlib.h"
#include "../../StanfordCPPLib/include/vector.h"

enum Player { HUMAN, COMPUTER };

const int N_COINS = 13;
const int MAX_MOVE = 3;
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
    std::cout << "takes the last coin loses." << std::endl << std::endl;
  }

private:
  void initGame() {
    nCoins = N_COINS;
    whoseTurn = STARTING_PLAYER;
  }

  bool gameIsOver() { return (nCoins <= 1); }

  void displayGame() {
    std::cout << "There are " << nCoins << " coins in the pile" << std::endl;
  }

  Player getCurrentPLayer() { return whoseTurn; }

  void makeMove(int move) { nCoins -= move; }

  Move getComputerMove() { return findBestMove(); }

  void displayMove(Move move) {
    std::cout << "I'll take " << move.nTaken << "." << std::endl;
  }

  void makeMove(Move move) { nCoins -= move.nTaken; }

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

  void retractMove(Move move) { nCoins += move.nTaken; }

  int evaluateStaticPosition() {
    switch (nCoins) {
    case 1:
      return LOSING_POSITION;
      break;
    case 2:
      return WINNING_POSITION;
      break;
    case 3:
      return 50;
      break;
    case 4:
      return 25;
      break;
    case 5:
      return LOSING_POSITION;
      break;
    default:
      return 0;
      break;
    }
  }

  void announceResult() {
    if (nCoins == 0) {
      std::cout << "You took the last coin.  You lose." << std::endl;
    } else {
      std::cout << "There is only one coin left." << std::endl;
      if (whoseTurn == HUMAN) {
        std::cout << "I win." << std::endl;
      } else {
        std::cout << "I lose." << std::endl;
      }
    }
  }

  int nCoins;
  Player whoseTurn;
};

int main() {
  Nim game;
  game.printInsructions();
  game.play();
  return 0;
}
