//
// Created by dexhacker on 7/8/21.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

int reduce_array_size_to_the_half::Solution::minSetSize(vector<int> &arr) {
    unordered_map<int, int> countNumbers;

    for (auto i : arr) ++countNumbers[i];

    vector<pair<int, int>> pairs;

    for (const auto& [number, count] : countNumbers) pairs.push_back({count, number});

    sort(pairs.begin(), pairs.end(), greater <>());

    int answer = 0;
    int size = arr.size();
    int i = 0;
    while (size > arr.size() / 2) {
        size -= pairs[i].first;
        ++i;
        ++answer;
    }

    return answer;
}

void reduce_array_size_to_the_half::Solution::test() {
    vector<int> test {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    assert(minSetSize(test) == 2);

    cout << "minSetSize completed!" << endl;
}
