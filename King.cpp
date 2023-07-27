#include "King.h"
#include "GameUtilities.h"
#include "GameBoard.h"

King::King() : bMove(false) {}

King::King(King* piece, GameBoard* boardState) : GamePieces(piece, boardState), bMove(piece->bMove) {

}

King::King(Color color, GameBoard* board) : GamePieces(color, board), bMove(false) {
    if (color == Color::White) {
        name = "W K";
    } else {
        name = "B K";
    }
}

King::~King() {}

void King::setMove() {
    bMove = true;
}

bool King::moveValidate(int start1, int start2, int end1, int end2) {
    if ((absolute(start1, end1) <= 1 && absolute(start2, end2) <= 1) || (!bMove && (end2 == 1 || end2 == 6) && start1 == end1)) {
        return true;
    }
    return false;
}


bool King::checkOccupy(int start1, int start2, int end1, int end2) {
    if (absolute(start2, end2) <= 1) {
        if (getBoardState()->getSpecificColor(end1, end2) == getColor()) {
            return true;
        }
        return false;
    }
    if (end2 == 1 && getBoardState()->checkRook(end1, 0)) {
        for (int i = start2 - 1; i >= end2; --i) {
            if (getBoardState()->checkOccupy(end1, i)) {
                return true;
            }
        }
        return false;
    }
    if (end2 == 6 && getBoardState()->checkRook(end1, 7)) {
        for (int i = start2 + 1; i <= end2; ++i) {
            if (getBoardState()->checkOccupy(end1, i)) {
                return true;
            }
        }
        return false;
    }
    return true;
}