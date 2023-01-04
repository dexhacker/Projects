//
// Created by dexhacker on 1/4/23.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

int minimum_rounds_to_complete_all_tasks::Solution::minimumRounds(vector<int> &tasks) {
    unordered_map<int, int> m;
    for (int t : tasks) m[t]++;
    int answer = 0;
    for (auto p : m) {
        if (p.second < 2) return -1;
        if (p.second % 3 == 0) {
            answer += p.second / 3;
        } else {
            answer += p.second / 3 + 1;
        }
    }
    return answer;
}

void minimum_rounds_to_complete_all_tasks::Solution::test() {
    vector<int> tasks {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
    assert(minimumRounds(tasks) == 4);

    cout << "minimumRounds completed!" << endl;
}
