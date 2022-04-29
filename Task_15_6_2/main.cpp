#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {2, 7, 11, 15};
    int sumNumber = 18;

    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (sumNumber == vec[i] + vec[j]) {
                cout << vec[i] << ", " << vec[j] << "\n";
                break;
            }
        }
    }
}
