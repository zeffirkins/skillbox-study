#include <iostream>
#include <string>
#include <map>
using namespace std;

int main () {
    cout << "\n---=== Registry ===---\n";
    cout << "If you want add a patient enter his last name.\n";
    cout << "If you want called a next patient enter string => Next.\n";
    cout << "If you want exit enter => 0\n";

    string answer;
    multimap<string, int> patients;
    while (answer != "0") {
        cout << "\n=>";
        cin >> answer;

        if (answer == "0") {
            cout << "Goodbye.\n";
            break;
        } else if (answer == "NEXT" || answer == "Next" || answer == "next") {
            map<string, int>::iterator itf = patients.begin();
            cout << itf->first << "\n";
            patients.erase(itf);
            if (patients.empty()) {
                cout << "Patients is end.\n";
            }
        }else {
            patients.insert(pair<string, int> (answer, 1));
        }
    }
}