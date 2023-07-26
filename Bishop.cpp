#include "Bishop.h"
#include "GameUtilities.h"
#include "GameBoard.h"

Bishop::Bishop() {}

Bishop::Bishop(Color color, GameBoard* board) : GamePieces(color, board) {
    if (color == Color::White) {
        name = "W B";
    } else {
        name = "B B";
    }
}

Bishop::~Bishop() {}

bool Bishop::moveValidate(int start1, int start2, int end1, int end2) {
    if (absolute(start1, end1) == absolute(start2, end2)) {
        return true;
    }
    return false;
}

bool Bishop::checkOccupy(int start1, int start2, int end1, int end2) {
    if (start1 > end1) {
        if (start2 > end2) {
            for (int i = 1; i < (absolute(start1, end1)) && start1 - i > end1; ++i) {
                if (getBoardState()->checkOccupy(start1 - i, start2 - i) == true) {
                    return true;
                }
            }
        }
        if (end2 > start2) {
            for (int i = 1; i < (absolute(start1, end1)) && start1 - i < end1; ++i) {
                if (getBoardState()->checkOccupy(start1 - i, start2 + i) == true) {
                    return true;
                }
            }
        }
    }
    if (end1 > start1) {
        if (start2 > end2) {
            for (int i = 1; i < (absolute(start1, end1)) && start1 + i > end1; ++i) {
                if (getBoardState()->checkOccupy(start1 + i, start2 - i) == true) {
                    return true;
                }
            }
        }
        if (end2 > start2) {
            for (int i = 1; i < (absolute(start1, end1)) && start1 + i < end1; ++i) {
                if (getBoardState()->checkOccupy(start1 + i, start2 + i) == true) {
                    return true;
                }
            }
        }
    }
    if (getBoardState()->getSpecificColor(end1, end2) == getColor()) {
        return true;
    }
    return false;
}