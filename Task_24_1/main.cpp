#include <iostream>
using namespace std;

#define MONDAY    cout << "monday"
#define TUESDAY   cout << "tuesday"
#define WEDNESDAY cout << "wednesday"
#define THURSDAY  cout << "thursday"
#define FRIDAY    cout << "friday"
#define SATURDAY  cout << "saturday"
#define SUNDAY    cout << "sunday"

#define MESSAGE cout <<  "Enter the number of the day of the week =>"
#define ERROR cerr << "Error! Incorrect number."

int main() {
    int day;
    MESSAGE;
    cin >> day;

    if (day == 1) MONDAY;
    else if (day == 2) TUESDAY;
    else if (day == 3) WEDNESDAY;
    else if (day == 4) THURSDAY;
    else if (day == 5) FRIDAY;
    else if (day == 6) SATURDAY;
    else if (day == 7) SUNDAY;
    else ERROR;
}