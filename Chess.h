#pragma once

#include "GameBoard.h"

class Chess {
    
private:

    GameBoard gameboard;

    bool bEnd;

    Color turn;

public:

    Chess();

    ~Chess();

    void start();

    void checkDebug();

    bool checkEndGameCondition(Color);


};