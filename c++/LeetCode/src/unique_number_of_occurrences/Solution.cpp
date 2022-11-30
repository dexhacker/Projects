//
// Created by dexhacker on 11/30/22.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

bool unique_number_of_occurrences::Solution::uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> m;
    unordered_map<int, int> used;
    for (int i : arr) m[i]++;
    for (auto p : m) {
        if (used.count(p.second) > 0) return false;
        used[p.second]++;
    }

    return true;
}

void unique_number_of_occurrences::Solution::test() {
    vector<int> test {1, 2, 2, 1, 1, 3};
    assert(uniqueOccurrences(test) == true);

    cout << "uniqueOccurrences completed!" << endl;
}
