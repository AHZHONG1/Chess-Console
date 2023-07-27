#include <iostream>
#include "Chess.h"

using namespace std;

int main() {
    while (true) {
        Chess chess;
        string input;
        bool condition;
        do {
            cout << "Menu" << endl;
            cout << "Press P to play. Press Q to leave game" << endl;
            getline(cin, input, '\n');
            condition = (input[0] == 'P' || input[0] == 'Q' || input[0] == 'p' || input[0] == 'q' || input.length() == 1);
            if (condition) {
                break;
            }
        } while (!condition);
        input[0] = toupper(input[0]);
        if (input[0] == 'P') {
            chess.start();
        }
        if (input[0] == 'Q') {
            break;
        }  
    }
    
    return 0;
}