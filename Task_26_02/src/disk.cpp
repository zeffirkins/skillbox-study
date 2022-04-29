#include "disk.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void save (string& buffer) {
    ofstream file("data.txt");
    file << buffer;
    file.close();
}

void load (string& buffer) {
    ifstream file("data.txt");
    file >> buffer;
    file.close();
}