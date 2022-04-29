#include <iostream>
#include <vector>
using namespace std;

void swapvec (vector <int> &vec, int* arr) {
    int temp;
    for (int i = 0; i < vec.size(); i++) {
        temp = *(arr + i);
        *(arr + i) = vec[i];
        vec[i] = temp;
    }
}

int main() {
    vector <int> vec = {1, 2, 3, 4};
    int arr[] = {2,4,6,8};

    swapvec(vec, arr);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < sizeof(arr) / sizeof (arr[0]); i++) {
        cout << arr[i] << " ";
    }
}