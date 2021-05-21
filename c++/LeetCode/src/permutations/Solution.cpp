//
// Created by dexhacker on 5/19/21.
//

#include "Solution.h"
#include <cassert>

void permutations::Solution::solve(vector<int> &current_seq, int current_position) {
    if (current_seq.size() == n) {
        list.push_back(current_seq);
        return;
    }
    for (int next_number = 0; next_number < n; next_number++) {
        if (used[next_number] == 1) continue;

        used[next_number] = 1;
        current_seq.push_back(next_number);
        solve(current_seq, current_position + 1);
        current_seq.pop_back();
        used[next_number] = 0;
    }
}

vector<vector<int>> permutations::Solution::permute(vector<int> &nums) {
    list = {}, used = {}, n = nums.size();
    used.reserve(n);
    vector<int> empty;
    solve(empty, 0);
    for (auto & seq : list)
        for (int &i : seq)
            i = nums[i];
    return list;
}

void permutations::Solution::test() {
    vector<int> test1 {1, 2, 3};
    vector<vector<int>> answer1 {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    assert(permute(test1) == answer1);

    vector<int> test2 {0, 1};
    vector<vector<int>> answer2 {{0, 1}, {1, 0}};
    assert(permute(test2) == answer2);

    vector<int> test3 {1};
    vector<vector<int>> answer3 {{1}};
    assert(permute(test3) == answer3);

    cout << "permute completed!" << endl;
}
