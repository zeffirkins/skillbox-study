#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
    cout << "Please, enter the path to the file: ";
    string patch;
    cin >> patch;

    ifstream file(patch, ios::binary);

    if(!file.is_open()){
        cerr << "Error open file name "<< patch << "\n";
        exit(1);
    }
    char buff[100];

    while(!file.eof()) {
        file.read(buff, sizeof(buff)-1);
        buff[file.gcount()] = 0;
        cout << buff;
    }
    file.close();
}