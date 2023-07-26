#include "Pawn.h"
#include "GameUtilities.h"
#include "GameBoard.h"

Pawn::Pawn() : bMove(false) {}

Pawn::Pawn(Color color, GameBoard* board) : GamePieces(color, board), bMove(false) {
    if (color == Color::White) {
        name = "W P";
    } else {
        name = "B P";
    }
}

Pawn::~Pawn() {}

void Pawn::setMove() {
    bMove = true;
}

bool Pawn::moveValidate(int start1, int start2, int end1, int end2) {
    if (getColor() == Color::White) {
        if (end1 == start1 - 1 && absolute(start2, end2) <= 1) {
            return true;
        }
        if (!bMove && end1 == start1 - 2 && start2 == end2) {
            return true;
        }
        return false;
    } else {
        if (end1 == start1 + 1 && absolute(start2, end2) <= 1) {
            return true;
        }
        if (!bMove && end1 == start1 + 2 && start2 == end2) {
            return true;
        }
        return false;
    }
}

bool Pawn::checkOccupy(int start1, int start2, int end1, int end2) {
    if (start2 == end2) {
        if (getBoardState()->checkOccupy(end1, end2)) {
            return true;
        }
        return false;
    }
    if (getColor() == Color::White) {
        if (getBoardState()->getSpecificColor(end1, end2) == Color::None && start1 == 3 && getBoardState()->getEn_passant() == end2) {
            return false;
        }
    } else {
        if (getBoardState()->getSpecificColor(end1, end2) == Color::None && start1 == 4 && getBoardState()->getEn_passant() == end2) {
            return false;
        }
    }
    if (getBoardState()->getSpecificColor(end1, end2) == getColor() || getBoardState()->getSpecificColor(end1, end2) == Color::None) {
        return true;
    }
    return false;
}