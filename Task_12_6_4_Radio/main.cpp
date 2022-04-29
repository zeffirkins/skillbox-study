#include <iostream>
using namespace std;

int radio (float *frequency, int button){
    if (button >= 1 && button <= 10) {
        cout << "You listening frequency " << frequency[button - 1] << "Hz\n";
        return 1;
    }
    if (button == 0) {
        cout << "Radio shutdown.\n";
        return 0;
    }
    else cout << "Range not found. Choose from 1 to 10, press 0 for shutdown:\n";
    return -1;
}

int main() {
    float frequency[] = {87.5f, 88.9f, 90.6f, 92.4f, 95.0f, 100.5f, 102.4f, 102.8f, 106.3f, 107.8f};
    int button = 10;
    cout << "Radio ON\n";
    while (radio(frequency, button)) {
        cout << "For shutdown press 0. Choose frequency for listening:";
        cin >> button;
        cout << "==========\n";
    }
}