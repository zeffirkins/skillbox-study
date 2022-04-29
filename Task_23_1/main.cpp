#include <iostream>
#include <map>
#include <string>
using namespace std;

int main () {
    cout << "---=== Phonebook ===---\n";
    cout << "If you want add contact press 1.\n";
    cout << "If you want find contact by number press 2.\n";
    cout << "If you want find contact by name press 3.\n";
    cout << "For exit press 0.\n";
    int action;
    map<int, string> phonebook;
    multimap<string, int> phonebook2;
    string name;
    int number;
    while (action != 0) {
        cout << "Your action?\n";
        cout << "->";
        cin >> action;
        if (action == 1) {
            cout << "Enter the number:";
            cin >> number;
            cout << "Enter the name:";
            cin >> name;

            phonebook.insert(pair<int, string> (number, name));
            phonebook2.insert(pair<string, int> (name, number));
        } else if (action == 2) {
            cout << "Enter the number:";
            cin >> number;

            map<int, string>::iterator it = phonebook.find(number);
            cout << it->second << "\n";
        } else if (action == 3) {
            cout << "Enter the name:";
            cin >> name;

            for (multimap<string, int>::iterator it = phonebook2.begin(); it != phonebook2.end(); it++) {
                if ((*it).first == name) {
                    cout << (*it).first << " => "  << (*it).second << "\n";
                }
            }
        }else {
            cerr << "\nError! Incorrect action.\n";
        }
    }
}