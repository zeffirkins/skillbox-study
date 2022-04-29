#include <iostream>
#include <sstream>
using namespace std;

int main() {
    stringstream stream_number;

    cout << "Input integer part:";
    int integer;
    cin >> integer;

    cout << "Input fraction part:";
    int fraction;
    cin >> fraction;

    stream_number << integer << "." << fraction;

    double number;
    stream_number >> number;

    cout << "Total number:" << fixed << number << "\n";
}