#include <iostream>
#include <vector>
using namespace std;

vector<int> add(vector<int>vec, int val) {
    vec.resize(vec.size() + 1);
    vec[vec.size() - 1] = val;

    return vec;
}

vector<int> remove_last(vector<int>vec) {
    vec.resize(vec.size() - 1);

    return vec;
}

vector<int> remain(vector<int> vec,int position) {
    vector<int> newVec;
    for (int i = 0; i < position; i++) {
        newVec[i] = vec[i];
    }
    for (int i = position; i < vec.size(); i++) {
        newVec[i] = vec[i+1];
    }

    return newVec;
}

int main() {

    vector<int>vec;
    int num, position;

    cout << "Fill the showcase:";
    while (num != -1) {
        cin >> num;

        vec = add(vec, num);
    }
    cout << "Showcase:";
    for (int i = 0; i < vec.size() - 1; i++) {
        cout << vec[i] << " ";
    }

    while (position != -1) {
        cout << "How robot you chosen?\n";
        cin >> position;

        vec = remain(vec, position);
    }

    cout << "Remaining robots:";
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
}