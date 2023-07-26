#pragma once

#include <iostream>
#include "GameUtilities.h"
using namespace std;

class GamePieces;

class GameBoard {

private:
    
    GamePieces* board[8][8];

    int en_passant;

public:

    GameBoard();

    ~GameBoard();

    void printBoard();

    bool move(string, string, Color);

    bool checkOccupy(int, int);

    bool checkPawn(int, int);

    bool checkRook(int, int);

    Color getSpecificColor(int, int);

    int getEn_passant();

    void checkDebug(string, string);

};