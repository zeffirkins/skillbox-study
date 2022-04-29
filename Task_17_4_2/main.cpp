#include <iostream>
using namespace std;

int* reverse (int* array, int* reverseArr)
{
    for (int i = 9; i >= 0; --i)
        *(reverseArr + i) = *(array + 9 - i);
    return reverseArr;
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int reverseArr[10];
    int* pa = array;
    int* pr = reverseArr;

    pr = reverse (pa, pr);

    for (int i = 0; i < 10; ++i)
        cout << *(pr + i) << ' ';
}
