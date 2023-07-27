#include "Rook.h"
#include "GameBoard.h"

Rook::Rook() : bMove(false) {}

Rook::Rook(Rook* piece) : GamePieces(piece), bMove(piece->bMove) {
    
}

Rook::Rook(Color color, GameBoard* board) : GamePieces(color, board), bMove(false) {
    if (color == Color::White) {
        name = "W R";
    } else {
        name = "B R";
    }
}

Rook::~Rook() {}

void Rook::setMove() {
    bMove = true;
}

bool Rook::getMove() {
    return bMove;
}

bool Rook::moveValidate(int start1, int start2, int end1, int end2) {
    if (start1 == end1 || start2 == end2) {
        return true;
    }
    return false;
}

bool Rook::checkOccupy(int start1, int start2, int end1, int end2) {
    if (start1 == end1) {
        if (start2 > end2) {
            for (int i = end2 + 1; i < start2; ++i) {
                if (getBoardState()->checkOccupy(start1, i) == true) {
                    return true;
                }
            }
        }
        if (end2 > start2) {
            for (int i = start2 + 1; i < end2; ++i) {
                if (getBoardState()->checkOccupy(start1, i) == true) {
                    return true;
                }
            }
        }
    }
    if (start2 == end2) {
        if (start1 > end1) {
            for (int i = end1 + 1; i < start1; ++i) {
                if (getBoardState()->checkOccupy(i, start2) == true) {
                    return true;
                }
            }
        }
        if (end1 > start1) {
            for (int i = start1 + 1; i < end1; ++i) {
                if (getBoardState()->checkOccupy(i, start2) == true) {
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