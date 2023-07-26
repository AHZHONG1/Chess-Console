#include "Knight.h"
#include "GameUtilities.h"
#include "GameBoard.h"

Knight::Knight() {}

Knight::Knight(Color color, GameBoard* board) : GamePieces(color, board) {
    if (color == Color::White) {
        name = "W N";
    } else {
        name = "B N";
    }
}

Knight::~Knight() {}

bool Knight::moveValidate(int start1, int start2, int end1, int end2) {
    if ((absolute(start1, end1) == 1 && absolute(start2, end2) == 2) || (absolute(start1, end1) == 2 && absolute(start2, end2) == 1)) {
        return true;
    }
    return false;
}

bool Knight::checkOccupy(int start1, int start2, int end1, int end2) {
    if (getBoardState()->getSpecificColor(end1, end2) == getColor()) {
        return true;
    }
    return false;
}