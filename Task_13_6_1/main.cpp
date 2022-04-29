#include <iostream>
#include <vector>
using namespace std;

void show(vector<int>vec, int index) {
    for (int i = index + 1; i < vec.size(); i++) {
        if (vec[i] != vec.empty()) cout << vec[i] << " ";

    }
    for (int i = 0; i <= index; i++) {
        if (vec[i] != vec.empty()) cout << vec[i] << " ";
    }
}

int main() {
    vector<int> vec(20);
    int number;
    cout << "Enter a number:";
    cin >> number;
    int index = 0;
    while(number != -1) {
        vec[index] = number;
        show(vec, index);
        index++;
        if (index == 20) index = 0;
        std::cout << "\nEnter a number:";
        std::cin >> number;
    }
    show(vec, index);
}