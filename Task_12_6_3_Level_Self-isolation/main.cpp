#include <iostream>
using namespace std;

int main() {
    int house[5];
    int residents;
    cout << "Enter count residents in the house:";
    cin >> residents;

    int sumResidents = 0;
    for (int i = 0; i < 5; i++){
        cout << "Enter count residents " << i + 1 << " floor in the house:";
        cin >> house[i];
        sumResidents += house[i];
    }

    cout << "Level self-isolation in the house " << float(sumResidents) * 100 / float (residents) << "%\n";
}