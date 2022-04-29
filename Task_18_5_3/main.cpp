#include <iostream>
using namespace std;

int jump(int steps, int jumpLength = 3){

    if (steps < 0)
        return 0;
    if (steps == 0)
        return 1;

    int ways = 0;
    for (int i = jumpLength; i > 0; i--) {
        ways += (jump(steps - i, jumpLength));
    }
    return ways;
}

int main() {
    cout << "Enter the number of steps:";
    int steps;
    cin >> steps;

    cout << "You want input jump length(y/n)?";
    char answer;
    cin >> answer;

    if (answer == 'y'){
        cout << "Enter jump length: ";
        char jumpLength;
        cin >> jumpLength;

        cout << "You have " << jump(steps, jumpLength) << " ways to do it!\n";
    }else {
        cout << "Ok. Jump lenght = 3 by default.\n";
        cout << "You have " << jump(steps) << " ways to do it!\n";
    }
}