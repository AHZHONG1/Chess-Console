#include "Chess.h"
#include "GameUtilities.h"


Chess::Chess() : bEnd(false), turn(Color::White) {

}

Chess::~Chess() {

}

void Chess::start() {
    while (!bEnd) {
        gameboard.printBoard();
        cout << ((turn == Color::White) ? "White" : "Black") << "'s turn" << endl;
        string move;
        bool validation;
        do {
            cout << "Enter Beginning and Destination (e.g. E2 E4)" << endl;
            getline(cin, move, '\n');
            validation = (move.length() == 5 && move[0] >= 'A' && move[0] <= 'H' && move[1] >= '1' && move[1] <= '8' && move[2] == ' ' && move[3] >= 'A' && move[3] <= 'H' && move[4] >= '1' && move[4] <= '8') || (move.length() == 3 && move[0] == 'T' && move[1] >= 'A' && move[1] <= 'H' && move[2] >= '1' && move[2] <= '8');

            if (validation) {
                break;
            }
            cout << "Wrong input, please type again" << endl;
        } while (true);
        cout << "Success" << endl;
        if (move.length() == 3) {
            gameboard.checkDebug(move.substr(1, 1), move.substr(2, 1));
            continue;
        }
        if (move.length() == 5) {
            if (!gameboard.move(move.substr(0, 2), move.substr(3, 2), turn)) {
                continue;
            }

            turn = (turn == Color::White) ? Color::Black : Color::White;
        }


        
    }
}

void Chess::checkDebug() {
    while (!bEnd) {
        gameboard.printBoard();
        cout << ((turn == Color::White) ? "White" : "Black") << "'s turn" << endl;
        string position;
        bool validation;
        do {
            cout << "Enter Pieces for checking" << endl;
            getline(cin, position, '\n');
            validation = !(position.length() != 2 || position[0] < 'A' || position[0] > 'H' || position[1] < '1' || position[1] > '8');
            if (validation) {
                break;
            }
            cout << "Wrong input, please type again" << endl;
        } while (!validation);

        gameboard.checkDebug(position.substr(0, 1), position.substr(1, 1));
    }
}
