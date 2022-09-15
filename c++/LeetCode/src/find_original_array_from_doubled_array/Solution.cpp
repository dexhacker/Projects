//
// Created by dexhacker on 9/15/22.
//

#include "Solution.h"
#include <queue>
#include <unordered_map>
#include <cassert>

vector<int> find_original_array_from_doubled_array::Solution::findOriginalArray(vector<int> &changed) {
    if (changed.size() % 2 == 1) return {};

    sort(changed.begin(), changed.end());

    vector<int> answer;

    unordered_map<int, queue<int>> m;
    for (int i = 0; i < changed.size(); i++) m[changed[i]].push(i);

    for (int i = 0; i < changed.size(); i++) {
        if (changed[i] < 0) continue;

        m[changed[i]].pop();

        if (m.count(changed[i] * 2)) {
            m[changed[i] * 2];

            if (m[changed[i] * 2].empty()) return {};

            int index = m[changed[i] * 2].front();

            changed[index] = -1;
            m[changed[i] * 2].pop();
            answer.push_back(changed[i]);
        } else {
            return {};
        }
    }

    return answer;
}

void find_original_array_from_doubled_array::Solution::test() {
    vector<int> test1 {1, 3, 4, 2, 6, 8};
    vector<int> answer1 {1,3,4};
    assert(findOriginalArray(test1) == answer1);

    cout << "findOriginalArray completed!" << endl;
}
