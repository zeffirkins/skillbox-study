#include <iostream>
using namespace std;

void evendigits (long long number, int &ans){
    int temp = number % 10;
    if(temp % 2 == 0)
        ans++;

    number = number / 10;
    if(number == 0)
        return;

    evendigits(number, ans);
}

int main() {
    cout << "Input long number: ";
    long long number;
    cin >> number;

    int ans = 0;
    evendigits(number, ans);

    cout << "You number have " << ans << " even digits!\n";
}