#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

struct TimeManager {
    string name = "unknown";
    time_t open;
    time_t close;
    double second = 0;
};

void finish(TimeManager& TM) {
    if (TM.name != "unknown") {
        TM.close = time (nullptr);
        TM.second = (TM.close - TM.open);
        ofstream file ("saving.txt", ios::app);
        file << TM.name << " " << TM.second << "\n";
        file.close();
        TM.name = "unknown";
    } else {
        cout << "There is no open task, please enter command again.\n";
    }
}

void begin(TimeManager& TM) {
    if (TM.name == "unknown") {
        cout << "Please enter a name task.\n";
        cin >> TM.name;
        TM.open = time (nullptr);
    }
    else {
        finish(TM);
        cout << " There is open task, please enter a command again.\n";
    }
}

void status() {
    string name;
    int time;
    ifstream file ("saving.txt");
    while (!file.eof()) {
        file >> name >> time;
        cout << "Project name: " << name << ". Length: " << time << " seconds.\n";
    }
}

int main() {
    cout << "\n---=== TimeManager ===---\n";
    cout << "To start a project enter -> begin\n";
    cout << "To close a current project enter -> end\n";
    cout << "To see current overview of closed tasks enter -> status\n";
    string command;
    TimeManager TM;
    while (command != "exit") {
        cout << "What you want to do?\n";
        cin >> command;
        if (command == "begin") begin (TM);
        else if (command == "end") finish(TM);
        else if (command == "status") status();
        else if (command != "exit") cerr << "Error";
    }
}