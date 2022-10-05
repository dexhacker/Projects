//
// Created by dexhacker on 10/5/22.
//

#include "Solution.h"
#include <cassert>

void permutations_ii::Solution::reс(vector<int> &nums, vector<int> permutation, bool *used) {
    if (permutation.size() == nums.size()) {
        answer.push_back(permutation);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;

        used[i] = true;
        permutation.push_back(nums[i]);
        reс(nums, permutation, used);
        permutation.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permutations_ii::Solution::permuteUnique(vector<int> &nums) {
    vector<int> permutation;
    bool used [8];

    reс(nums, permutation, used);

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}

void permutations_ii::Solution::test() {
    vector<int> test {1, 1, 2};
    vector<vector<int>> answer {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
    auto result = permuteUnique(test);
    for (int i = 0; i < answer.size(); i++) assert(answer[i] == result[i]);

    cout << "permuteUnique completed!" << endl;
}
