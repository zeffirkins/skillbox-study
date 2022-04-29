#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    string path;
    cout << "Enter the path to the file (Example: C:\\Skillbox\\words.txt):";
    cin >> path;
    ifstream vedomost;
    vedomost.open(path);

    if(!vedomost.is_open()){
        std::cerr<<"Error! File not open or not found.\n";
        exit(0);
    }

    int sum = 0, rich = 0;
    string nameRich;

    while (!vedomost.eof()) {
        int rub = 0;
        string firstName, lastName, date;
        vedomost >> firstName >> lastName >> rub >> date;
        sum += rub;
        if (rub > rich) {
            rich = rub;
            nameRich = firstName + " " + lastName;
        }

    }
    vedomost.close();
    cout << "Sum: " << sum << "\n";
    cout << "Rich: " << rich << "\n";
    cout << "Name: " << nameRich << "\n";
}