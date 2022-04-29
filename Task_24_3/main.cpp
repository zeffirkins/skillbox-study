#include <iostream>
using namespace std;

//#define SPRING
//#define SUMMER
#define AUTUMN
//#define WINTER

#define PRINT(x) #x

int main() {
#ifdef SPRING
    cout << PRINT(SPRING) << "\n";
#endif

#ifdef SUMMER
    cout << PRINT(SUMMER) << "\n";
#endif

#ifdef AUTUMN
    cout << PRINT(AUTUMN) << "\n";
#endif

#ifdef WINTER
    cout << PRINT(WINTER) << "\n";
#endif
    return 0;
}