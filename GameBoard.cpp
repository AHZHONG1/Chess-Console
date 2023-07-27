#include "GameBoard.h"
#include "GamePieces.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

GameBoard::GameBoard() : en_passant(-1) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = nullptr;
        }
    }
    for (int j = 0; j < 8; ++j) {
        board[1][j] = new Pawn(Color::Black, this);
    }
    for (int j = 0; j < 8; ++j) {
        board[6][j] = new Pawn(Color::White, this);
    }
    board[0][0] = new Rook(Color::Black, this);
    board[0][7] = new Rook(Color::Black, this);
    board[7][0] = new Rook(Color::White, this);
    board[7][7] = new Rook(Color::White, this);
    board[0][1] = new Knight(Color::Black, this);
    board[0][6] = new Knight(Color::Black, this);
    board[7][1] = new Knight(Color::White, this);
    board[7][6] = new Knight(Color::White, this);
    board[0][2] = new Bishop(Color::Black, this);
    board[0][5] = new Bishop(Color::Black, this);
    board[7][2] = new Bishop(Color::White, this);
    board[7][5] = new Bishop(Color::White, this);
    board[0][3] = new Queen(Color::Black, this);
    board[7][3] = new Queen(Color::White, this);
    board[0][4] = new King(Color::Black, this);
    board[7][4] = new King(Color::White, this);



}

GameBoard::~GameBoard() {

}

void GameBoard::printBoard() {
    cout << "----------------------------------" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << 8 - i << "|";
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == nullptr) {
                cout << "   " << "|";
                continue;
            }
            cout << board[i][j]->getName() << "|";
        }
        cout << endl;
        cout << "----------------------------------" << endl;
    }
    cout << "   A   B   C   D   E   F   G   H" << endl;
}

bool GameBoard::move(string start, string end, Color turn) {
    int start1 = '8' - start[1];
    int start2 = start[0] - 'A';
    int end1 = '8' - end[1];
    int end2 = end[0] - 'A';

    if (board[start1][start2] == nullptr) {
        return false;
    }

    if (board[start1][start2]->getColor() != turn) {
        cout << "You cannot move your opponent's piece" << endl;
        return false;
    }
    if (!board[start1][start2]->moveValidate(start1, start2, end1, end2)) {
        cout << "Your move is against the rule" << endl;
        return false;
    }
    if (board[start1][start2]->checkOccupy(start1, start2, end1, end2)) {
        cout << "Your move has been blocked" << endl;
        return false;
    }

    if (board[start1][start2] != nullptr && typeid(*board[start1][start2]) == typeid(Pawn)) {
        dynamic_cast<Pawn*>(board[start1][start2])->setMove();
    }

    if (board[start1][start2] != nullptr && typeid(*board[start1][start2]) == typeid(King)) {
        dynamic_cast<King*>(board[start1][start2])->setMove();
    }

    if (board[end1][end2] == nullptr && board[start1][start2] != nullptr && typeid(*board[start1][start2]) == typeid(Pawn) && start2 != end2) {
        board[end1][end2] = board[start1][start2];
        board[start1][start2] = nullptr;
        delete board[start1][end2];
        board[start1][end2] = nullptr;
    } else if (board[start1][start2] != nullptr && typeid(*board[start1][start2]) == typeid(King) && absolute(start2, end2) > 1) {
        board[end1][end2] = board[start1][start2];
        board[start1][start2] = nullptr;
        if (end2 == 1) {
            board[end1][3] = board[end1][0];
            board[end1][0] = nullptr;
        }
        if (end2 == 6) {
            board[end1][5] = board[end1][7];
            board[end1][7] = nullptr;
        }
    } else if (board[end1][end2] == nullptr) {
        board[end1][end2] = board[start1][start2];
        board[start1][start2] = nullptr;
    } else {
        delete board[end1][end2];
        board[end1][end2] = board[start1][start2];
        board[start1][start2] = nullptr;
    }

    if (typeid(*board[end1][end2]) == typeid(Pawn) && absolute(start1, end1) == 2) {
        en_passant = start2;
    } else {
        en_passant = -1;
    }

    return true;
}

bool GameBoard::checkOccupy(int i, int j) {
    if (board[i][j] == nullptr) {
        return false;
    }
    return true;
}

bool GameBoard::checkPawn(int i, int j) {
    if (board[i][j] == nullptr) return false;
    return typeid(*board[i][j]) == typeid(Pawn);
}

bool GameBoard::checkRook(int i, int j) {
    if (board[i][j] == nullptr) return false;
    return typeid(*board[i][j]) == typeid(Rook);
}

Color GameBoard::getSpecificColor(int i, int j) {
    if (board[i][j] == nullptr) {
        return Color::None;
    }
    return board[i][j]->getColor();
}

int GameBoard::getEn_passant() {
    return en_passant;
}

void GameBoard::checkDebug(string i, string j) {
    int start1 = '8' - j[0];
    int start2 = i[0] - 'A';
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            if (board[start1][start2]->moveValidate(start1, start2, x, y)) {
                cout << "Case1:(" << x << ", " << y << ")" << endl;
            }
            if (!(board[start1][start2]->checkOccupy(start1, start2, x, y))) {
                cout << "Case2:(" << x << ", " << y << ")" << endl;
            }
            if ((board[start1][start2]->moveValidate(start1, start2, x, y) && !(board[start1][start2]->checkOccupy(start1, start2, x, y)))) {
                cout << "(" << x << ", " << y << ")" << endl;
            }
        }
    }
}

