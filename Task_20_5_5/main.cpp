#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
    srand(time(nullptr));

    int height, width;
    cout << "Input height and width picture: ";
    cin >> height >> width;

    ofstream picture("C:\\Skillbox\\pic.txt");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            picture << rand() % 2;
        }
        picture << "\n";
    }

    picture.close();
    cout << "Picture is ready!";
}