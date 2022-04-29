#include <iostream>
#include "action.h"
using namespace std;

int main() {
    cout << "\n---===Simulation Operation===---\n";
    string answer;
    point begin, end;
    cout << "For start the operation enter 2 coordinates to make a cut.\n";
    scalpel(begin, end);
    while (answer != "suture") {
        cout << "If you want to make a cut enter 'scalpel'\n";
        cout << "If you want use a clamp enter 'hemostat'\n";
        cout << "If you want take a tweezers enter 'tweezers'\n";
        cout << "If you want sew up patient and end operation enter 'suture'\n";
        cout << "=>";
        cin >> answer;
        if (answer == "scalpel") scalpel(begin, end);
        else if (answer == "hemostat") hemostat(begin);
        else if (answer == "tweezers") tweezers(begin);
        else if (answer == "suture") suture(begin, end);
        else cerr << "Error! Incorrect input.";
    }
    cout << "Operation completed. Excellent!\n";
}