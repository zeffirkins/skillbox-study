#include <iostream>
#include <string>
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
using namespace std;

int main() {
    cout << "\n---===Simulator Computer===---\n";
    string buffer = "11111111";
    int answer = 0;
    while (answer != 6) {
        cout << "Please choose needed action.\n";
        cout << "1. INPUT\n";
        cout << "2. SUM\n";
        cout << "3. SAVE\n";
        cout << "4. LOAD\n";
        cout << "5. DISPLAY\n";
        cout << "6. EXIT\n";
        cout << "=>";
        cin >> answer;
        if (answer == 1) input (buffer);
        else if (answer == 2) compute (buffer);
        else if (answer == 3) save (buffer);
        else if (answer == 4) load (buffer);
        else if (answer == 5) display(buffer);
    }
    cout << "Simulator is finished.\n";
}