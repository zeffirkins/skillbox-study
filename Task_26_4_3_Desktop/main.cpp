#include <iostream>
using namespace std;

class Monitor {
public:
    int x;
    int y;
    int width;
    int height;
};

Monitor myMonitor;

class Command {
public:
    void move () {
        int newX, newY;
        cout << "Please enter new beginning:";
        cin >> newX >> newY;
        while ((newX + myMonitor.width) > 80 && ((newY + myMonitor.height) > 50))
        {
            cout << "Incorrect input, please try again\n";
            cin >> newX >> newY;
        }
        myMonitor.x = newX;
        myMonitor.y = newY;
    };

    void resize () {
        int newWidth, newHeight;
        cout << "Please enter new width and new heught of the window\n";
        cin >> newWidth >> newHeight;
        while ((myMonitor.x + newWidth) > 80 && (myMonitor.y + newHeight) > 50) {
            cout << "Incorrect input, please try again\n";
            cin >> newWidth >> newHeight;
        }
    };

    void display () {
        for (int i = 0; i <= 50; i++) {
            for (int j = 0; j <=80; j++) {
                if (i >= myMonitor.y && i <= (myMonitor.y + myMonitor.height) && j >= myMonitor.x
                    && j <= (myMonitor.x + myMonitor.width)) cout << "1";
                else cout << "0";
            }
            cout << "\n";
        }
    };
};

int main() {
    cout << "\n---=== Monitor ===---\n";
    cout << "Please enter initial parameters of Window\n";
    cin >> myMonitor.x >> myMonitor.y >> myMonitor.width >> myMonitor.height;
    while ((myMonitor.x + myMonitor.width) > 80 && (myMonitor.y + myMonitor.height) > 50) {
        cout << "Incorrect entry, please try again\n";
        cin >> myMonitor.x >> myMonitor.y >> myMonitor.width >> myMonitor.height;
    }
    int answer;
    Command command;
    while (answer != 4) {
        cout << "Please choose a command:\n";
        cout << "1. move Window\n";
        cout << "2. resize Window\n";
        cout << "3.display Window\n";
        cout << "4.exit";
        cout << "=>";
        cin >> answer;

        if (answer == 1) command.move();
        else if (answer == 2) command.resize();
        else if (answer == 3) command.display();
        else cout << "Incorrect input.\n";
    }
    cout << "Goodbye!\n";
}