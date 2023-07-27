#pragma once
#include "GamePieces.h"

class Pawn : public GamePieces {
public:

    bool bMove;


public:

    Pawn();

    Pawn(Pawn*);

    Pawn(Color, GameBoard*);

    ~Pawn();

    void setMove();

    virtual bool moveValidate(int, int, int, int);

    virtual bool checkOccupy(int, int, int, int);

};