#include <iostream>
#include <exception>
#include <time.h>
#include <string>
using namespace std;

class fish_except : public exception {
    const char* what() const noexcept override {
        return "Congratulations! You catch FISH.";
    }
};

class boot_except : public exception {
    const char* what() const noexcept override {
        return "Lol=) you catch old boot.";
    }
};

class empty_except : public exception {
    const char* what() const noexcept override {
        return "Empty. Try again.";
    }
};


int main() {
    srand(time(nullptr));
    int field_size = 9;
    int boot_count = 3;
    string field[field_size];
    for (int i = 0; i < field_size; i++) {
        field[i] = "empty";
    }
    field[rand() % 9] = "fish";

    while (boot_count > 0) {
        int get_pos = rand() % 9;
        if (field[get_pos] == "empty") {
            field[get_pos] = "boot";
            boot_count--;
        }
    }

    //for (int i = 0; i < field_size; i++) {
    //    cout << field[i] << "\n";
    //}
    bool fished = false;
    int answer;
    int number_of_ratings = 0;
    while (!fished) {
        try {
            cout << "Enter number sector (1 - 9) for fishing =>";
            cin >> answer;
            answer--;
            if (field[answer] == "fish") {
                throw fish_except();
            }else if (field[answer] == "boot") {
                throw boot_except();
            }else {
                cout << "Empty. Try again.\n";
            }
        }catch (const exception &x) {
            cout << x.what() << "\n";
            fished = true;
        }
        number_of_ratings++;
    }
    cout << "Number of ratings: " << number_of_ratings << "\n";
}