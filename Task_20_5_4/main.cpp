#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

int main() {
    srand(time(nullptr));
    int bank[1000];

    int sum_bank = 0;

    cout << "-==SkillBoxBank==-\n";
    cout << "If you want deposit money at an ATM enter '+'.\n";
    cout << "If you want withdraw money from the account enter '-'.\n";
    cout << "What is your action:";
    string action;
    cin >> action;

    if (action == "+") {
        int banknote[6] = {100, 200, 500, 1000, 2000, 5000};
        for(int i = 0; i < 1000; i++){
            bank[i] = banknote[rand() % 6];
            sum_bank += bank[i];
        }
        ofstream file_bank("C:\\Skillbox\\bank.bin", ios::binary);
        file_bank.write((char*)&bank, sizeof(bank));
        file_bank.close();
        cout << "Total amount money in ATM " << sum_bank << " RUB.\n";
    }else if (action == "-") {
        cout<<"Enter the required amount:";
        int money;
        cin >> money;
        if (money % 100) {
            cerr << "Enter sum incorrect! You must enter sum multiples of 100";
            return 0;
        }
        ifstream file_bank;
        file_bank.open("C:\\Skillbox\\bank.bin", ios::binary);
        if (!file_bank.is_open()) {
            cerr << "Error! File is not open of not found.\n";
            cerr << "Try to top up the ATM first.\n";
            return 0;
        }
        file_bank.read((char*)&bank, sizeof(bank));
        for(int i = 0; i < 1000; i++){
            sum_bank += bank[i];
        }
        file_bank.close();
        if (money > sum_bank) {
            cerr << "Error! The ATM doesn't have that much money.";
            return 0;
        }else {
            while (money != 0) {
                for(int i = 0; i < 1000; i++) {
                    if (bank[i] > money) continue;
                    else {
                        money -= bank[i];
                        sum_bank -= bank[i];
                        bank[i] = 0;
                    }
                }
            }
            cout << "The remaining amount in the ATM " << sum_bank;
            for(int i = 0; i < 1000; i++){
                sum_bank += bank[i];
            }
            ofstream file_bank("C:\\Skillbox\\bank.bin", ios::binary);
            file_bank.write((char*)&bank, sizeof(bank));
            file_bank.close();
        }
    }else
        cerr << "Error! Incorrect action,the program is closed.";
    return 0;
}