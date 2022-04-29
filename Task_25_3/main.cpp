#include <iostream>
#include <ctime>
#include <iomanip>
#include <unistd.h>
using namespace std;

int main() {
    tm timer;
    cout << "\n---=== Timer ===---\n";
    cout << "Enter time in format MM:SS =>";
    cin >> get_time(&timer, "%M:%S");
    time_t t = time(nullptr) + timer.tm_min * 60 + timer.tm_sec;
    while (true) {
        time_t delta = t - time(nullptr);
        if (delta == 0) break;
        cout << delta / 60 << ":" << delta % 60 << "\n";
        sleep(1);
    }
    cout << "DING! DING! DING!\n";
}