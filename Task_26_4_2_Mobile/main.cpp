#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <class Addresbook> list;

class Addresbook {
public:
    string name;
    string number;
};

class Mobilephone {
public:
    void add () {
        Addresbook newContact;
        string newNumber;
        cout << "Please enter a name of Person: ";
        cin >> newContact.name;
        cout << "Please enter a number phone Person in the format +7xxxxxxxxxx: ";
        cin >> newNumber;
        while (newNumber.size() != 12 && newNumber[0] != '+' && newNumber[1] != '7') {
            cout << "Incorrect input" << std::endl;
            cout << "Please enter again" << std::endl;
            cin >> newNumber;
        }
        newContact.number = newNumber;
        list.push_back(newContact);
    };

    void call () {
        string name;
        cout << "Who do you want to call? " ;
        cin >> name;
        for (int i = 0; i < list.size(); i++) {
            if(name == list[i].name) {
                cout << "We're calling to " << list[i].name << " by number " << list[i].number << "\n";
            } else if (name == list[i].number) {
                cout << "We're calling to " << list[i].name << " by number" << list[i].number << "\n";
            } else cout << "There is no such kind of person.\n";
        }
    };

    void sms () {
        string name;
        string message;
        cout << "Please enter a message:";
        cin.ignore();
        std::getline (cin, message);
        cout << "Who do you want to write?\n";
        cin >> name;
        for (int i = 0; i < list.size(); i++) {
            if(name == list[i].name) {
                cout << "SMS " << message <<" were sent to " << list[i].name << " by number" << list[i].number << "\n";
            } else if (name == list[i].number) {
                cout << "SMS " << message <<" were sent to " << list[i].name << " by number" << list[i].number << "\n";
            } else cout << "There is no such kind of person\n";
        }
    };
};

int main () {
    Mobilephone mobile;
    cout << "\n---=== Mobilephone ===---\n";
    string action;
    while (action != "exit") {
        cout << "Enter 'add' for add new contact\n";
        cout << "Enter 'call' to pause\n";
        cout << "Enter 'sms' for change track\n";
        cout << "Enter 'exit' to exit the program\n";
        cout << "=>";
        cin >> action;
        if (action == "add")  mobile.add();
        else if (action == "call") mobile.call();
        else if (action == "sms")  mobile.sms();
        else cout << "Incorrect input! Try again.\n";
    }
    cout << "Goodbye!\n";
}