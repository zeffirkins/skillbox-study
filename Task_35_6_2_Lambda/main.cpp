#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>
using namespace std;

int main() {
    vector<int>vec = {3, 2, 1, 2, 4, 5, 3, 3};

    auto lambda = [] (vector<int> vec) {
        unordered_set<int> findCount;
        vector <int> countMeeting;

        for(auto current : vec) {
            if (findCount.insert(current).second)
                countMeeting.push_back(current);
        }

        return std::make_unique<std::vector<int>>(countMeeting);
    };

    auto uniq_ptr = lambda(vec);
    for (auto element : *uniq_ptr)
        cout << element << " ";
}