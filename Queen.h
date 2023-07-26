#pragma once
#include "GamePieces.h"

class Queen : public GamePieces {
private:




public:

    Queen();

    Queen(Color, GameBoard*);

    ~Queen();

    virtual bool moveValidate(int, int, int, int);

    virtual bool checkOccupy(int, int, int, int);

};