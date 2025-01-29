#ifndef CHESS_H
#define CHESS_H

#include <string>

using namespace std;

class Chess
{
private:

    /* 
    * Positive = White
    * Negitive = Black
    * 
    * Empty  = 0
    * Pawn   = 1
    * Knight = 2
    * Bishop = 3
    * Rook   = 4
    * Queen  = 5
    * King   = 6
    * Block  = 7    This is for checkMove() 
    * Launch = 8    Moved form -> to
    */

    short int _board[64]; //A1, B1, ... , H8

    short int _myColor; // 1 = White, 0 = None, -1 = Black
    
    short int _pieceValue[6] = {1,3,3,5,9,0};

    int _score[2] {0,0}; // Player_1, Player_2

    enum Mode {
        Classic,
        BlackJack
    };

    void checkMove(); // Checks if you can move without hanging the king; Checks if the move is correct for the piece
    void promotion(); // Pawn changes to other piece
    void checkMate(); // Checks if their is a check -> if it's mate

public:
    Chess();            // Constructor
    Chess(Mode gameMode); // Overloaded constructor
    ~Chess();           // Destructor

    bool nextMove(); // TODO, intialize as index = -8, index += 8*row+column return true if move worked
};

#endif