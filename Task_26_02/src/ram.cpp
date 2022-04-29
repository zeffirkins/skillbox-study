#include "ram.h"
#include <iostream>
#include <string>
using namespace std;

void write (string& buffer) {
    bool correct = false;
    while (!correct) {
        cout << "Please enter only 8 integer:\n";
        cin >> buffer;
        if (buffer.size() != 8) cerr << "Error!\n";
        else correct = true;
    }
}

void read (string& buffer) {
    cout << buffer << "\n";
}