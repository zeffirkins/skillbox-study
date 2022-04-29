#include <iostream>
using namespace std;

template < typename T>
T average(T array[], int size) {
    T sum = 0;
    cout << "Fill the array (" << size<< "):\n";
    for (int i = 0; i < size; i++){
        cout << i + 1 << ")=>";
        cin >> array[i];
        sum += array[i];
    }
    return sum / size;
}


int main() {
    cout << "\n---=== Average ===---\n";
    cout << "Enter size array =>";
    int size;
    cin >> size;
    double array[size];
    cout << average(&array[size], size);
}