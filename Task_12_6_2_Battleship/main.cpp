#include <iostream>
using namespace std;

int main() {

    bool tiny[1];
    bool small[2];
    bool medium[3];
    bool large[4];

    cout << "Size for tiny ship: "  << sizeof(tiny) << "\n";
    cout << "Size for small ship: "  << sizeof(small) << "\n";
    cout << "Size for medium ship: "  << sizeof(medium) << "\n";
    cout << "Size for large ship: "  << sizeof(large) << "\n";
}