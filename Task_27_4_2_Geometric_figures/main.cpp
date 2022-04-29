#include <iostream>
using namespace std;

class Core {
public:
    float x, y;
    string color = "unknown";

    void centerCore () {
        cout << "Enter x and y coordinate:";
        cin >> x >> y;
    }

    void colorChoose() {
        cout << "Please choose color of shape:\n";
        cout << "1. red\n";
        cout << "2. blue\n";
        cout << "3. green\n";
        int choose = 0;
        cin >> choose;

        if (choose == 1) color = "red";
        if (choose == 1) color = "blue";
        if (choose == 1) color = "green";
    }
};

class Square : public Core {
public:
    float distanceToEdge = 0;
    Square (float m) : distanceToEdge(m) {}

    void squareSize() {
        centerCore();
        colorChoose();
        cout << "Square size is " << (2 * distanceToEdge) * (2 * distanceToEdge) << "\n";
    }
    void squareOutside () {
        cout << "It's equal\n";
    }
};

class Circle : public Core {
public:
    float radius = 0;
    Circle (float m) : radius(m) {}

    void circleSize() {
        centerCore();
        colorChoose();
        cout << "Circle size is " << 3.14f * radius * radius << "\n";
    }
    void squareOutside() {
        cout << "Square outside has following size of edge: " << 2 * radius << "\n";
    }
};

class Triangle : public Core {
public:
    float distanceToApex;
    Triangle (float m) : distanceToApex (m) {}
    void triangleSize() {
        centerCore();
        colorChoose();
        cout << "Triangle square is " << 0.433f * (2 * 0.86f * distanceToApex) * (2 * 0.86f * distanceToApex) << "\n";
    }
    void squareOutside() {
        cout << "Square outside has following size of edge: " << 0.86f * 2 * 0.86f * distanceToApex << "\n";
    }
};

class Rectangle : public Core {
    float shortDistance, longDistance;
public:
    Rectangle (float m, float n) : shortDistance(m), longDistance (n) {}

    void rectangleSize() {
        centerCore();
        colorChoose();
        cout << "rectangle square is " << 4 * shortDistance * longDistance << "\n";
    }
    void squareOutside() {
        cout << "Square outside has following size of edge: " << longDistance << "\n";
    }
};

void squareCreation() {
    float m;
    cout << "Please enter distance to edge: \n";
    cin >> m;
    Square mySquare(m);
    mySquare.squareSize();
    mySquare.squareOutside();
}

void circleCreation() {
    float m;
    cout << "Please enter a radius: \n";
    cin >> m;
    Circle myCircle(m);
    myCircle.circleSize();
    myCircle.squareOutside();
}

void triangleCreation() {
    float m;
    cout << "Please enter a distanc1e from center to Apex: \n";
    cin >> m;
    Triangle myTriangle(m);
    myTriangle.triangleSize();
    myTriangle.squareOutside();
}

void rectangleCreation() {
    float m, n;
    cout << "Please enter a short and long edges: \n";
    cin >> m >> n;
    Rectangle myRectangle(m, n);
    myRectangle.rectangleSize();
    myRectangle.squareOutside();
}


int main() {
    cout << "\n---=== Geometric Figure ===---\n";
    int buffer;
    while (buffer != 5) {
        cout << "Please choose what shape we will create\n";
        cout << "1. circle\n";
        cout << "2. square\n";
        cout << "3. triangle\n";
        cout << "4. rectangle\n";
        cout << "5. exit\n";
        cin >> buffer;

        if (buffer == 1) circleCreation();
        else if (buffer == 2) squareCreation();
        else if (buffer == 3) triangleCreation();
        else if (buffer == 4) rectangleCreation();
        else if (buffer == 5) cout << "Goodbye.";
        else cout << "Incorrect command! Try again.\n";
    }
}