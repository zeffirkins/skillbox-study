#include <iostream>
using namespace std;

#define FULL(a) \
for (int i=0; i<10; i++) \
{\
cout << "Please enter amount of passengers in " << i + 1 << " carriage: ";\
cin >> a[i];\
}\

#define OVERLOAD(a) \
for (int i=0; i<10; i++) \
{\
if (a[i] > 20) {\
cout << i + 1 << " carriage have" << a[i] - 20 << " extra passenger\n";\
}\
}\

#define FREE(a) \
for (int i=0; i<10; i++) \
{\
if (a[i] < 20) {\
cout << i + 1 << " carriage have" << 20 - a[i] << " free places for passenger\n";\
}\
}\

#define TOTAL(a) \
int sum=0; \
for (int i=0; i<10; i++) \
{\
sum += a[i];\
}\
cout << "Amount of passengers is " << sum << "\n";\

int main() {
    int a[10];
    FULL (a);
    OVERLOAD(a);
    FREE(a);
    TOTAL(a);
    return 0;
}