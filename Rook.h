#pragma once
#include "GamePieces.h"

class Rook : public GamePieces {
private:




public:

    Rook();

    Rook(Color, GameBoard*);

    ~Rook();

    virtual bool moveValidate(int, int, int, int);

    virtual bool checkOccupy(int, int, int, int);

};