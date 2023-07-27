#pragma once
#include <iostream>
#include "GameUtilities.h"
using namespace std;

class GameBoard;

class GamePieces {

private:

    GameBoard* boardState;

    Color color;

protected:

    string name;


public:

    GamePieces();

    GamePieces(GamePieces*);

    GamePieces(Color, GameBoard*);

    virtual ~GamePieces();

    string getName();

    Color getColor();

    GameBoard* getBoardState();

    virtual bool moveValidate(int, int, int, int) = 0;

    virtual bool checkOccupy(int, int, int, int) = 0;

};