#pragma once
#include "GamePieces.h"

class King : public GamePieces {
private:

    bool bMove;



public:

    King();

    King(Color, GameBoard* board);

    ~King();

    void setMove();

    virtual bool moveValidate(int, int, int, int);

    virtual bool checkOccupy(int, int, int, int);



};