#include <iostream>
using namespace std;

bool analyzingInput(string line) {
    if (line.length() == 9) return true;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == 'X' || line[i] == 'O' || line[i] == '.') return true;
    }
    return false;
}

bool checkCol(string line, char symbol) {
    for (int i = 0; i < line.length(); i++) {
        if ((line[i] == line[i + 3]) && (line[i + 3] == line[i + 6])
            && (line[i] == symbol)) {
            return true;
        }
    }
    return false;
}

bool checkRow (string line, char symbol) {
    for (int i = 0; i < 3; ++i)
        if (((line[i + 2 * i]) == line[(i + 1) + 2 * i]) &&((line[(i + 1) + 2 * i]) == line[(i + 2) + 2 * i])
            && line[i + 2 * i] == symbol){
            return true;
        }
    return false;
}

bool checkDiag(string line, char symbol) {
    for (int i = 0; i < line.length(); i++) {
        if ((line[0] == line[4] && line[4] == line[8] && (line[0] == symbol))
            || (line[2] == line[4] && line[4] == line[6] && (line[2] == symbol))) {
            return true;
        }
    }
    return false;
}

bool thisWin (string line, char symbol) {
    return (checkCol(line, symbol) || checkRow(line, symbol) || checkDiag(line, symbol));
}


int main() {
    cout
            << "Hello! Welcome to program, analyzing game X&0. You must input 3 strings from game and program get answer.\n";
    cout << "Remember! Strings must have only 3 symbols. These symbols can be 'X', 'O' or '.'\n";
    string row1, row2, row3, line;
    cout << "Input row 1:";
    cin >> row1;
    cout << "Input row 2:";
    cin >> row2;
    cout << "Input row 3:";
    cin >> row3;
    line = row1 + row2 + row3;

    if (analyzingInput(line)) {
        int countX = 0, countO = 0;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == 'X') countX++;
            else if (line[i] == 'O') countO++;
        }
        if ((countX - countO == 0) || (countX - countO == 1)) {
            bool winX = thisWin(line, 'X');
            bool winO = thisWin(line, 'O');

            if ((winX && winO) || (winO && (countX - countO == 1)) || (winX && (countX - countO == 0))) {
                cout << "Incorrect!\n";
            } else if (!winX && !winO) {
                cout << "Nobody.\n";
            } else {
                cout << (winX ? "Petya won!" : "Vanya won!") << "\n";
            }
        } else {
            cout << "Incorrect!\n";
        }
    } else {
        cout << "Error! Try again.\n";
    }
}