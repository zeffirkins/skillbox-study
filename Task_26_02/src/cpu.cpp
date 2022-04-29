#include "cpu.h"
#include <iostream>
#include <string>
using namespace std;

void compute (string& buffer) {
    int sum=0;
    int buf = stoi(buffer);
    while (buf >0) {
        sum += buf % 10;
        buf /= 10;
    }
    cout << sum << "\n";
}