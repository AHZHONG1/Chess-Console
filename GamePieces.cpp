#include "GamePieces.h"
#include "GameBoard.h"

GamePieces::GamePieces() {

}

GamePieces::GamePieces(GamePieces* piece, GameBoard* boardState) : color(piece->color), boardState(boardState), name(piece->name) {

}

GamePieces::GamePieces(Color color, GameBoard* board) : color(color), boardState(board) {

}

GamePieces::~GamePieces() {

}

string GamePieces::getName() {
    return name;
}

Color GamePieces::getColor() {
    return color;
}

GameBoard* GamePieces::getBoardState() {
    return boardState;
}

