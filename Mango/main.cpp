#include <iostream>


bool  is_match (std::string text, std::string word, int startPos) {
    for (int i = 0; i < word.length(); i++) {
        if (i + startPos >= text.length() || word[i] != text[i + startPos]) {
            return false;
        }
    }
    return true;
}

int find(std::string text, std::string word) {
    for (int startPos = 0; startPos < text.length(); startPos++) {
        if (is_match(text, word, startPos)) {
            return startPos;
        }
    }
    return -1;
}

void found() {
    std::cout << "Found!\n";
}

std::string reversed(std::string str) {
    int len = str.length();
    int n = len - 1;
    for (int i = 0; i < (len / 2); i++) {
        std::swap(str[i], str[n]);
        n = n - 1;
    }
    return str;
}

int rfind(std::string str, std::string substr) {
    return str.length() - (find(reversed(str), reversed(substr)) + substr.length());
}

int exponenta (int a, int b, int c) {
    for (int i = 0; i < b; i++) {
        c = c * a;
    }
    return c;
}

int main() {
    int a, b, c = 1;
    std::cout << "Input number and exponent:\n";
    std::cin >> a >> b;


    std::cout << "Answer:" << exponenta(a, b, c) << "\n";
}


