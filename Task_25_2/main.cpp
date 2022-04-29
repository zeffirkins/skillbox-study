#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>
using namespace std;

int main() {
    time_t t = time(nullptr);
    tm current = *localtime(&t);
    tm bd = *localtime(&t);
    string answer;
    bool found = false;
    multimap<int, string> birth;
    int dayTotal, today, maxDay = 365;
    while (true) {
        cout << "Name:";
        cin >> answer;
        if (answer == "end") break;
        cout << "Birthday:";
        cin >> get_time(&bd, "%Y/%m/%d");
        dayTotal = (bd.tm_mon * 30 + bd.tm_mday);
        birth.insert(pair<int, string>(dayTotal, answer));
    }
    today = (current.tm_mon * 30 + current.tm_mday);
    for (int i = today; i <= maxDay; i++) {
        multimap<int, string>::iterator it = birth.find(i);
        if (it->second != "end"){
            cout << "Name: " << it->second << " Birthday: " << (it->first / 30) + 1 << "/" << (it->first % 30) << "\n";
            found = true;
        }
    }
    if (!found){
        cout << "Not this year!)\n";
        map<int, string>::iterator itf = birth.begin();
        cout << "Name: " << itf->second << " Birthday: " << (itf->first / 30) + 1 << "/" << (itf->first % 30)
             << "\n";
    }
}