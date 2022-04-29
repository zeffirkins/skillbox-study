#include <iostream>
#include <string>
#include <map>
using namespace std;

void toMap(multimap<char, int> &mapAnogram, string &str) {
    for (int i = 0; i < str.size(); i++) {
        mapAnogram.insert(pair<char,int> (str[i], 1));
    }
}

bool isAnogram (string &str1, string &str2) {
    multimap<char, int> firstStr;
    multimap <char, int> secondStr;

    toMap(firstStr, str1);
    toMap(secondStr, str2);

    if(firstStr.size() != secondStr.size()) {
        return false;
    }
    if (firstStr != secondStr){
        return false;
    }
    return true;
}

int main () {
    cout << "\n---=== Anagram ===---\n";
    string str1, str2;
    cout << "Enter first string =>";
    cin >> str1;
    cout << "Enter second string =>";
    cin >> str2;

    cout << boolalpha << isAnogram(str1, str2) << "\n";
}