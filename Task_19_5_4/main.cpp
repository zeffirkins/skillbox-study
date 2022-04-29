#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    string path;
    cout << "Enter the path to the file (Example: C:\\Skillbox\\image.png):";
    cin >> path;

    if(".png" != path.substr(path.size()-4, 4)){
        std::cerr << "Not a file PNG!\n";
        exit(0);
    }

    ifstream image;
    image.open(path, ios::binary);

    if(!image.is_open()){
        std::cerr<<"Error! File not open or not found.\n";
        exit(0);
    }

    char head [4];
    image.read(head, sizeof(head));

    if ((int) head[0] != -119) {
        cout << "Not a file PNG!\n";
    }else if (head[1] != 'P' && head[2] != 'N' && head[3] != 'G') {
        cout << "Not a file PNG!\n";
    }else {
        cout << "This is file PNG!\n";
    }

    image.close();
}