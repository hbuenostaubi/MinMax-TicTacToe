//
//  main2.cpp
//  Tic-Tac-Toe
//
//  Created by Harrison  Bueno on 7/20/18.
//  Copyright © 2018 Harrison  Bueno. All rights reserved.
//

#include "game2.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

const int X = 1, O = -1, EMPTY = 0;
int board[3][3];
int currentPlayer;                // current player (X or O)

void clearBoard() {                // clear the board
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = EMPTY;            // every cell is empty
    currentPlayer = X;                // player X starts
}

void putMark(int i, int j) {
    board[i][j] = currentPlayer;
    currentPlayer = -currentPlayer;        // switch players
}

bool isWin(int mark) {            // is mark the winner?
    int win = 3*mark;                // +3 for X and -3 for O
    return ((board[0][0] + board[0][1] + board[0][2] == win)        // row 0
            || (board[1][0] + board[1][1] + board[1][2] == win)        // row 1
            || (board[2][0] + board[2][1] + board[2][2] == win)        // row 2
            || (board[0][0] + board[1][0] + board[2][0] == win)        // column 0
            || (board[0][1] + board[1][1] + board[2][1] == win)        // column 1
            || (board[0][2] + board[1][2] + board[2][2] == win)        // column 2
            || (board[0][0] + board[1][1] + board[2][2] == win)        // diagonal
            || (board[2][0] + board[1][1] + board[0][2] == win));        // diagonal
    }

int getWinner() {                // who wins? (EMPTY means tie)
    if (isWin(X)) return X;
    else if (isWin(O)) return O;
    else return EMPTY;
}

void printBoard() {                // print the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            switch (board[i][j]) {
                case X:        cout << "X"; break;
                case O:        cout << "O"; break;
                case EMPTY:    cout << " "; break;
            }
            if (j < 2) cout << "|";            
        }
        if (i < 2) cout << "\n-+-+-\n";        // row boundary
    }
}

int main() {                    // main program
    clearBoard();                // clear the board
    putMark(0,0);    putMark(1,1);        // add the marks
    putMark(0,1);    putMark(0,2);
    putMark(2,0);    putMark(1,2);
    putMark(2,2);    putMark(2,1);
    putMark(1,0);
    printBoard();                // print the final board
    int winner = getWinner();
    if (winner != EMPTY)            // print the winner
        cout << "  " << (winner == X ? 'X' : '0') << " wins" << endl;
    else
        cout << "  Tie" << endl;
    return EXIT_SUCCESS;
}
