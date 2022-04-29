#include <iostream>
#include <vector>
using namespace std;

void sorting (vector <int> &vec) {
    for (int i = vec.size() - 1; (i > 0) && (vec[i] < vec[i-1]); i--) {
        int temp = vec[i];
        vec[i] = vec[i-1];
        vec[i-1] = temp;
    }
}

void show (vector <int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
}

int main() {
    vector <int> vec;
    int num;
    cout << "Input any numbers (input '-1' for output 5 smallest numbers; input '-2' for ending program):\n";
    do{
        cin >> num;

        if (num == -1) {
            show(vec);
            if (vec.size() < 5)
                cout << "Haven't five elements yet" << "\n";
            else
                cout << "[5] smallest element is " << vec[4] << "\n";
        }
        else {
            vec.push_back(num);
            sorting (vec);
        }

    }while (num != -2);
}