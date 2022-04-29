#include <iostream>
using namespace std;

int* reverse (int* array, int* reverseArray) {
    for (int i = 9; i >= 0; --i)
        *(reverseArray + i) = *(array + 9 - i);
    return reverseArray;
}

int main() {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int reverseArray[10];
    int* pa = array;
    int* pr = reverseArray;

    for (int i = 0; i < 10; i++)
        cout << *(pa + i) << ' ';
    cout << "\n";

    pr = reverse (pa, pr);

    for (int i = 0; i < 10; i++)
        cout << *(pr + i) << ' ';
}