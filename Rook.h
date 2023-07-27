#pragma once
#include "GamePieces.h"

class Rook : public GamePieces {
private:

    bool bMove;


public:

    Rook();

    Rook(Rook*);

    Rook(Color, GameBoard*);

    ~Rook();

    void setMove();

    bool getMove();

    virtual bool moveValidate(int, int, int, int);

    virtual bool checkOccupy(int, int, int, int);

};