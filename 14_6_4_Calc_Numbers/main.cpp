#include <iostream>
using namespace std;

float thisNumber (string number) {

    bool errors = false;
    bool point = false;
    bool digit = false;

    for (int i = 0; i < number.length(); i++) {
        if (number[i] == '-' || number[i] == '.' || (number[i] >= '0' && number[i] <= '9')) {
            if (number[i] >= '0' && number[i] <= '9') {
                digit = true;
            }else if (number[i] == '-' && i != 0) {
                errors = true;
            }else if (number[i] == '.' && point) {
                errors = true;
            }else if (number[i] == '.' && !point) {
                point = true;
            }else {
                errors = true;
            }
        }
    }

    float num = 0.0f;
    if (!errors && digit) {
        for (int i = 0;i < number.length(); i++) {
            if (number[0] == '-') continue;
            if (number[i] == '.') break;
            num *= 10.0f;
            num += number[i] - '0';
        }
        float fraction = 0.0f;
        for (int n = number.length() - 1; number[n] >= 0; n--) {
            if (number[n] == '.') break;
            fraction += number[n] - '0';
            fraction /= 10.0f;
            if ((n == 0 && number[n] != '.')) {
                fraction = 0;
                break;
            }
        }
        if (fraction < 0.0000000001) fraction *= 10;
        num += fraction;
        if (number[0] == '-') num *= -1;
    }
    return num;
}


int main() {
    string number, number1, number2;
    float num1 = 0, num2 = 0;
    cout << "Input first number:";
    cin >> number;
    number1 = number;
    num1 = thisNumber(number);

    cout << "Input second number:";
    cin >> number;
    number2 = number;
    num2 = thisNumber(number);


    if (num1 == num2) cout << "Equal";
    if (num1 > num2) cout << "More";
    if (num1 < num2) cout << "Less";
}