#include <iostream>
using namespace std;

int jump(int steps){

    if (steps < 0)
        return 0;
    if (steps == 0)
        return 1;

    return jump(steps - 3)  + jump(steps - 2) + jump(steps - 1);
}

int main() {
    cout << "Enter the number of steps: ";
    int steps;
    cin >> steps;

    cout << "You have " << jump(steps) << " ways to do it!\n";
}