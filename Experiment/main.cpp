#include <iostream>
#include <vector>
#include <algorithm>
#include "tuple"
#include <unordered_set>
#include <unordered_map>
#include <filesystem>
using namespace std;

auto averageAndExtremums = [] (vector<int> vec) {
    int avg, min, max;
    int accum = 0;
    for (auto i: vec) {
        accum += vec[i];
    }

    max = *max_element(vec.begin(), vec.end());
    min = *min_element(vec.begin(), vec.end());
    avg = accum / vec.size();

    return tuple<int, int, int>{avg, min, max};
};


int main () {
    vector<int> vec = {2, 3, 5, 1, 4};
    auto results = averageAndExtremums (vec);
    cout << get<1>(results);

    unordered_map<string, int> m;

    unordered_set<string> strings = {"first", "second", "third"};

    if (strings.count("first"))
        cout << "already exist";

    filesystem::path p("Users/Iurii/file.txt");

}