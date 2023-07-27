#pragma once
#include "GamePieces.h"

class Knight : public GamePieces {
private:




public:

    Knight();

    Knight(Knight*);

    Knight(Color, GameBoard*);

    ~Knight();

    virtual bool moveValidate(int, int, int, int);

    virtual bool checkOccupy(int, int, int, int);

};