#include <iostream>
#include <cmath>
using namespace std;

int main() {
    bool shop[1];
    bool gym[2];
    bool cottage[3];
    bool apartmentHouse[15];
    bool skyscraper[50];

    int sumFloor = sizeof(shop) + sizeof(gym) + sizeof(cottage) + sizeof(apartmentHouse) + sizeof(skyscraper);
    float average = sumFloor / 5.0f;

    cout << "Average height  buildings: " << floor(average) << "\n";
}