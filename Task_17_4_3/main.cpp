#include <iostream>
using namespace std;

bool substr (char* str1, char* str2) {
    bool match = false;
    for(int i = 0; *(str1 + i) != '\0' && !match; ++i){
        match = true;
        for(int j =0; *(str2 + j) != '\0' && match; ++j){
            (*(str1 + i) == *(str2 + j)) ? ++i : match = false;
        }
    }
    return match;
}

int main() {
    char* a = "Hello, world!";
    char* b = "wor";
    char* c = "banana";

    cout << boolalpha << substr(a, b) << " " << substr(a, c) << "\n";
}