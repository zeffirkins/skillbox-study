#include <iostream>
#include <sstream>
using namespace std;

double result (double num1, char action, double num2) {
    if (action == '+') return num1 + num2;
    else if (action == '-') return num1 - num2;
    else if (action == '*') return num1 * num2;
    else if (action == '/') return num1 / num2;
}

int main() {
    stringstream temp;
    string str;

    cout << "Input first number, action(+, -, *, /), second number: ";
    cin >> str;
    temp << str;

    double num1, num2;
    char action;
    temp >> num1 >> action >> num2;

    if (num2 == 0 && action == '/') {
        cout << "Can't divided by 0";
    }else if (!(action == '-' || action == '+' || action == '*' || action == '/')) {
        cout << "Error! Unknown action.";
    }else {
        double result_number = result(num1, action, num2);
        cout << num1 << " " << action << " " << num2 << " = " << result_number << "\n";
    }
}