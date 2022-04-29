#include <iostream>
using namespace std;

bool thisIp (string ip) {

    if (ip.length() < 7 || ip.length() > 15) return false;
    if (ip[0] == '.' || ip[ip.length() - 1] == '.') return false;
    string validSymbols = "0123456789.";

    int num = 0;
    int dotMark = 0;
    for (int i = 0; i < ip.length(); i++) {
        if (ip[i] == '.') dotMark += 1;
        if (ip[i] == '.' && ip[i - 1] == '.') return false;
        if (ip[i] == '0' && ip[i - 1] == '0') return false;
        if (ip[i] != '.' && ip[i - 1] == '0' && ip[i - 2] == '.') return false;

        if (ip[i] != '.') {
            num *= 10;
            num += ip[i] - '0';
        }else {
            if (!(num >= 0 && num <= 255)) return false;
            num = 0;
        }
        int find = 0;
        for (int n = 0; n < validSymbols.length(); n++) {
            if (ip[i] == validSymbols[n]) {
                find++; break;
            }
        }
        if (find != 1) return false;
    }
    if (dotMark != 3) return false;

    return true;
}

int main() {
    cout << "Input IP address:";
    string ip;
    getline(cin, ip);

    cout << (thisIp(ip) ? "Yes" : "No");
}