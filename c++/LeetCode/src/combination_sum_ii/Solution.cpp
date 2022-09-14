//
// Created by dexhacker on 9/14/22.
//

#include "Solution.h"
#include <cassert>

void combination_sum_ii::Solution::calculate_sum(vector<int> &combinations, vector<int> &candidates, int target, int index) {
    if (target < 0) return;
    if (0 == target) {
        answer.push_back(combinations);
        return;
    }

    for (int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i - 1]) continue;

        combinations.push_back(candidates[i]);
        calculate_sum(combinations, candidates, target - candidates[i], i + 1);
        combinations.pop_back();
    }
}

vector<vector<int>> combination_sum_ii::Solution::combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<int> combinations;
    calculate_sum(combinations, candidates, target, 0);

    return answer;
}

void combination_sum_ii::Solution::test() {
    vector<int> test1 {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> answer1 {
            {1, 1, 6},
            {1, 2, 5},
            {1, 7},
            {2, 6}
    };
    assert(combinationSum2(test1, 8) == answer1);

    cout << "combinationSum2 completed!" << endl;
}
