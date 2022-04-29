#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string path;
    cout << "Enter the path to the file (Example: C:\\Skillbox\\words.txt):";
    cin >> path;
    ifstream words;
    words.open(path);

    string word;
    cout << "Enter the word you want to find:";
    cin >> word;

    int count = 0;
    while (!words.eof()) {
        string text;
        words >> text;
        if (text == word) {
            count++;
        }
    }

    words.close();
    cout << count << " such words were found in the file!";
}