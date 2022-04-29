#include <iostream>
using namespace std;

bool thisNumber (string number) {

    bool errors = false;
    bool point = false;
    bool digit = false;

    for (int i = 0; i < number.length(); i++) {
        if (number[i] == '-' || number[i] == '.' || (number[i] >= '0' && number[i] <= '9')) {
            if (number[i] >= '0' && number[i] <= '9') {
                digit = true;
            } else if (number[i] == '-' && i != 0) {
                errors = true;
            } else if (number[i] == '.' && point) {
                errors = true;
            } else if (number[i] == '.' && !point) {
                point = true;
            } else {
                errors = true;
            }
        }
    }
    (!errors && digit) ? true : false;
}

int compareParts(string number1, string number2) {
    double fraction1 = 0, fraction2 = 0;
    for (int i = number1.length() - 1; number1[i] >= 0; i--) {
        if (number1[i] == '.') break;
        fraction1 += number1[i] - '0';
        fraction1 /= 10.0f;
        if ((i == 0 && number1[i] != '.')) {
            fraction1 = 0;
            break;
        }
    }

    for (int i = number2.length() - 1; number2[i] >= 0; i--) {
        if (number2[i] == '.') break;
        fraction2 += number2[i] - '0';
        fraction2 /= 10.0f;
        if ((i == 0 && number2[i] != '.')) {
            fraction2 = 0;
            break;
        }
    }

    if (fraction1 > fraction2) return 1;
    else if (fraction1 < fraction2) return -1;
    else if (fraction1 == fraction2) return 0;

}

int compareNumber (string number1, string number2) {
    int str1 = 0, str2 = 0;
    for (int i = 0;i < number1.length(); i++) {
        if (number1[0] == '-') continue;
        if (number1[i] == '.') break;
        str1 *= 10.0f;
        str1 += number1[i] - '0';
    }
    for (int i = 0;i < number2.length(); i++) {
        if (number2[0] == '-') continue;
        if (number2[i] == '.') break;
        str2 *= 10.0f;
        str2 += number2[i] - '0';
    }

    if (number1[0] == '-') str1 *= -1;
    if (number2[0] == '-') str2 *= -1;

    if (str1 > str2) return 1;
    else if (str1 < str2) return -1;
    else return (compareParts(number1, number2));
}


int main() {
    string number1, number2;
    float num1, num2;
    cout << "Input first number:";
    cin >> number1;

    cout << "Input second number:";
    cin >> number2;

    if (thisNumber(number1) && thisNumber(number2)) {}
        if (compareNumber(number1, number2) == 1)
            cout << "More";
        else if (compareNumber(number1, number2) == -1)
            cout << "Less";
        else if (compareNumber(number1, number2) == 0)
            cout << "Equal";

}