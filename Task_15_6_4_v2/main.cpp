#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec{-100, -50, -5, 1, 10, 15, 20, 30};
    int startPos = 0;
    int min = 0;

    for (int i = 0; i < vec.size(); i++) {
      if (vec[i] >= 0) {
        startPos = i;
        break;
      }
    }

    min = vec[startPos];
    int count = 0, positive = 0, negative = 0;
    int positiveCur = startPos + 1, negativeCur = startPos - 1;
    while (count < vec.size()) {
      cout << min << " ";
      negative = vec[negativeCur];
      positive = vec[positiveCur];

      if (abs(positive) < abs(negative)) {
        min = positive;
        positiveCur += 1;
      }else {
        min = negative;
        negativeCur -= 1;
      }
      count++;
    }
}