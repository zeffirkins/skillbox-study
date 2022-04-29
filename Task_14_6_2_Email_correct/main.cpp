#include <iostream>
using namespace std;

bool thisEmail (string email) {

    if (email.length() < 3) return false;
    if (email[0] == '@' || email[email.length() - 1] == '@') return false;

    string firstPart, secondPart;
    string validSymbolsFirstPart = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!#$%&'*+-./=?^_`{|}~0123456789";
    string validSymbolsSecondPart = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-.0123456789";

    int i = 0;
    for (i; email[i] != '@'; i++) {
        firstPart += email[i];
    }
    i += 1;
    for (i; i < email.length(); i++) {
        secondPart += email[i];
    }
    if (firstPart.length() > 64 || secondPart.length() > 63) return  false;
    if (email[0] == '.' || email[email.length() - 1] == '.'
            || firstPart[firstPart.length() - 1] == '.' || secondPart[0] == '.') return false;

    int dogMark = 0;
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '.' && email[i - 1] == '.') return false;
        if (email[i] == '@') dogMark += 1;
        if (dogMark > 1) return false;
    }

    for (int i = 0; i < firstPart.length(); i++) {
        int find = 0;
        for (int n = 0; n < validSymbolsFirstPart.length(); n++) {
            if (firstPart[i] == validSymbolsFirstPart[n]) {
                find++; break;
            }
        }
        if (find != 1) return false;
    }

    for (int i = 0; i < secondPart.length(); i++) {
        int find = 0;
        for (int n = 0; n < validSymbolsSecondPart.length(); n++) {
            if (secondPart[i] == validSymbolsSecondPart[n]) {
                find++; break;
            }
        }
        if (find != 1) return false;
    }

    return true;
}

int main() {
    cout << "Input email address:";
    string email;
    getline(cin, email);

    cout << (thisEmail(email) ? "Yes" : "No");

}