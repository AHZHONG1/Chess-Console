#pragma once
#include "GamePieces.h"

class Bishop : public GamePieces {
private:




public:

    Bishop();

    Bishop(Bishop*);

    Bishop(Color, GameBoard*);

    ~Bishop();

    virtual bool moveValidate(int, int, int, int);

    virtual bool checkOccupy(int, int, int, int);

};