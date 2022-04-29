#include <iostream>
using namespace std;
void show(int mas[][6]){

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 6; j++){
            cout << mas [i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int cutlery [2][6] = {{4, 3, 3, 3, 3, 3},
                         {4, 3, 3, 3, 3, 3}};
    int plates [2][6] = {{3, 2, 2, 2, 2, 2},
                        {3, 2, 2, 2, 2, 2}};
    int chair [2][6] = {{1, 1, 1, 1, 1, 1},
                         {1, 1, 1, 1, 1, 1}};
    show (cutlery);
    show (plates);
    show (chair);

    chair [0][4]+=1;
    cutlery [1][2]-=1;
    cutlery [0][0]-=1;
    cutlery [1][2]+=1;
    plates [0][0]-=1;

    cout << "==============================\n\n";

    show (cutlery);
    show (plates);
    show (chair);

    return 0;
}