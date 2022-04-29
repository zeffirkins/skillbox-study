#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <string>
using namespace std;

std::vector <bool> railwayStation = {false, false, false};
std::mutex railwayStation_access;

void arrivalToRailway(string name, int time) {
    cout << name << " went to you...";
    this_thread::sleep_for(chrono::seconds(time));

    railwayStation_access.lock();
    cout << "\nTrain " << name << " is arrived.\n";
    cout << "Waiting for depart. PLease enter a command depart.\n";
    string command;
    cin >> command;
    while (command != "depart") {
        cout << "Incorrect input command, please try again!\n";
        cin >> command;
    }
    for (int i = 0; i < railwayStation.size(); i++) {
        if (railwayStation[i] == false) {
            railwayStation[i] = true;
            break;
        }
    }
    railwayStation_access.unlock();
}

int main() {
    cout << "\n---=== Railway Simulator ===---\n";
    vector <thread> trains;
    vector <string> names(3);
    vector <int> time(3);

    for (int i = 0; i < 3; i++) {
        cout << "Name of trains:";
        cin >> names[i];
        cout << "Travel time:";
        cin >> time[i];
    }

    for (int i = 0; i < 3; ++i) {
        trains.emplace_back(arrivalToRailway, names[i], time[i]);
    }

    for (int i = 0; i < 3; ++i) {
        trains[i].join();
    }
}