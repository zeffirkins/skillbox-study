#include <iostream>
using namespace std;

struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

Color frameBuffer[1920 * 1080];

int main() {
    Color red {255,0,0};
    Color green {0,255,0};
    Color blue {0,0,255};

    Color white{255,255,255};
    Color black{0,0,0};
}
