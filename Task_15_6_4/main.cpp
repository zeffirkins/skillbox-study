#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec{-100, -50, -5, 1, 10, 15};

    for(int i = 0; i < vec.size() - 1; i++){
        int ind = i;
        for(int j = i + 1; j < vec.size(); j++){
            if(abs(vec[j]) < abs(vec[ind]))
                ind = j;
        }
        swap(vec[i], vec[ind]);
    }

    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}