
#ifndef game_h
#define game_h
#include <iostream>

using namespace std;

const char human = 'X';
const char ai = 'O';

enum Player { HUMAN, AI };  //creating data type (human or AI)

struct Move{
    int x;
    int y;};

class Game {
    char board[3][3];
    
public:
    Game();
    void printBoard(); // Prints the board
    bool gameOver(); // Returns true if a winner has been found or there are no empty spaces
    bool checkWin(Player player);// Check for a win
    void play(); // Primary game driver, loops through until there's a winner
    void getHumanMove();// Takes in values from the input stream and places them on the board
   int score(); // Returns 10 for human win, -10 for AI win, 0 for draw
    Move minimax(char AIboard[3][3]);// Returns the best AI move's x, y coordinates
    int minSearch(char AIboard[3][3]);
    int maxSearch(char AIboard[3][3]);
  
};

#endif /* game_h */
