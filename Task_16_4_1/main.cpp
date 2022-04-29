#include <iostream>
#include <sstream>
using namespace std;

const int MIN_SPEED = 0;
const int MAX_SPEED = 150;
const float precision = 0.01f;


 float showSpeed (float speed, float delta) {
    if (speed + delta >= MAX_SPEED - precision) {
        cout << "Can't so fast!";
        return MAX_SPEED;
    }else if (speed + delta > MIN_SPEED + precision) {
        return (speed + delta);
    }else return MIN_SPEED;
}

int main() {
    float delta;
    float speed = MIN_SPEED;
    stringstream auto_speed;

    do {
        cout << "Input delta speed: ";
        cin >> delta;

        auto_speed << showSpeed(speed, delta) << " km/h";
        cout << "Current speed: " << auto_speed.str() << "\n";

        auto_speed >> speed;
        auto_speed.str("");
    } while (speed > MIN_SPEED + precision);

    cout << "Car stopped!\n";
}