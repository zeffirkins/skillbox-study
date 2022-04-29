#include <iostream>
#include <vector>
using namespace std;

class Branch {
    vector<vector<string>> child;
    int bigBranch = rand() % 3 + 3;
    int midBranch = rand() % 2 + 2;

public:

    void villageGeneration () {
        child.resize(bigBranch);
        for (int i = 0; i < bigBranch; ++i) {
            child[i].resize(midBranch);
        }
    }

    void placement() {
        for (int i = 0; i < bigBranch; i++) {
            for (int j = 0; j < midBranch; j++) {
                cout << "Elf name:";
                cin >> child[i][j];
            }
        }
    }

    void foundNeighbors (string answer) {
        int countNeighbors = 0;
        int busy = 0;

        for (int i = 0; i < bigBranch; i++) {
            for (int j = 0; j < midBranch; j++) {
                if (answer == child[i][j]) {
                    busy = i;
                    break;
                }
            }
        }

        for(int i = busy; busy == i; i++) {
            for (int j = 0; j < midBranch; j++) {
                if (child[i][j] != "None" && child[i][j] != answer) countNeighbors++;
            }
        }

        cout << "Count of neighbors: " << countNeighbors;
    }
};

int main() {
    Branch myVillage;
    myVillage.villageGeneration();
    myVillage.placement();
    cout << "Who are we looking for?\n";
    string answer;
    cin >> answer;
    myVillage.foundNeighbors(answer);
}