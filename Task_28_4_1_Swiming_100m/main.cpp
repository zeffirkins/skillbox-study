#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
using namespace std;

vector<string> results;
mutex results_access;

void swim(const string& name, double speed) {
    cout << name << " started to swim...";
    double distance = 0;
    while (distance <= 100) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << name << " swam: " << distance << "\n";
        distance += speed;
    }
    cout << name << " finished.\n";

    results_access.lock();
    results.push_back(name);
    results_access.unlock();
}

int main() {
    cout << "\n---=== Swim 100m ===---\n";
    cout << "Enter count swimmers:";
    int n;
    cin >> n;
    vector<thread> swimmers;
    vector<string> names(n);
    vector<double> speeds(n);

    for (int i = 0; i < n; ++i) {
        cout << "Name of swimmer:";
        cin >> names[i];
        cout << "Speed:";
        cin >> speeds[i];
    }

    for (int i = 0; i < n; ++i) {
        swimmers.emplace_back(swim, names[i], speeds[i]);
    }

    for (int i = 0; i < n; ++i) {
        swimmers[i].join();
    }

    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ". " << results[i] << "\n";
    }
}