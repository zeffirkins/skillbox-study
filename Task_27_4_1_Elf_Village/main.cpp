#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Branch {
    Branch* bigStick = nullptr;
    vector<Branch*> midStick;

    string elfName = "None";

public:

    Branch(Branch* inBigStick): bigStick(inBigStick) {}

    Branch* addHome() {
        Branch* home = new Branch(this);
        midStick.push_back(home);
        return home;
    }

    bool canBeBusy() {
        return bigStick != nullptr;
    }


    void busy(string inElfName) {
        if (elfName == inElfName) return;
        if (inElfName != "None") {
            if (elfName != "None") {
                cerr << "House already busy!\n";
                return;
            }
            if (!canBeBusy()) {
                cerr << "This branch can't busy!\n";
                return;
            }
            elfName = inElfName;
        }
    }

    Branch* getTopBranch() {
        if (bigStick == nullptr) return nullptr;
        if (bigStick->bigStick == nullptr) return bigStick;
        return bigStick->getTopBranch();
    }

    Branch* getBigBranch() {
        if (bigStick == nullptr) return nullptr;
        return bigStick->bigStick == nullptr ? this : bigStick;
    }

    int elfsCount() {
        int count = elfName != "None";
        for (int i = 0; i < midStick.size(); i++) {
            count += midStick[i]->elfsCount();
        }
        return count;
    }

    int countNeighbors() {
        Branch* bigBranch = getBigBranch();
        return bigBranch == nullptr ? 0 : bigBranch->elfsCount() - (elfName != "None");
    }

    void busyMidStick() {
        if (canBeBusy()) {
            string inElfName;
            cout << "Enter elf name:";
            cin >> inElfName;
            busy(inElfName);
        }
        for (int i = 0; i < midStick.size(); i++) {
            midStick[i]->busyMidStick();
        }
    }

    Branch* findElfBranch(const string& inElfName) {
        if (elfName == inElfName) {
            return this;
        }
        for (int i = 0; i < midStick.size(); i++) {
            ;
            if (Branch* child = midStick[i]->findElfBranch(inElfName); child != nullptr) {
                return child;
            }
        }
        return nullptr;
    }
};

int main() {
    vector<Branch*> village;
    for (int i = 0; i < 1; i++) {
        Branch* tree = new Branch(nullptr);
        village.push_back(tree);
        int bigCount = (rand() % 3) + 3;
        for (int j = 0; j < bigCount; j++) {
            Branch* big = tree->addHome();
            int smallCount = (rand() % 2) + 2;
            for (int k = 0; k < smallCount; k++) {
                big->addHome();
            }
        }
    }

    for (int i = 0; i < village.size(); i++) {
        village[i]->busyMidStick();
    }

    string nameElf;
    cout << "Try to find an elf. Enter name:";
    cin >> nameElf;

    for (int i = 0; i < village.size(); i++) {
        if (Branch* branch = village[i]->findElfBranch(nameElf);branch != nullptr) {
            int count = branch->countNeighbors();
            cout << "Count neighbors: " << count << "\n";
        }
    }
}