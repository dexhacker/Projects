//
// Created by dexhacker on 9/14/22.
//

#include "Solution.h"
#include <cassert>

void combination_sum::Solution::calculate_sum(vector<int> &combinations, int sum, vector<int> &candidates, int target, int index) {
    if (sum > target) return;
    if (sum == target) {
        answer.push_back(combinations);
        return;
    }

    for (int i = index; i < candidates.size(); i++) {
        sum += candidates[i];
        combinations.push_back(candidates[i]);
        calculate_sum(combinations, sum, candidates, target, i);
        sum -= candidates[i];
        combinations.pop_back();
    }
}

vector<vector<int>> combination_sum::Solution::combinationSum(vector<int> &candidates, int target) {
    vector<int> combinations;
    int sum = 0;

    calculate_sum(combinations, sum, candidates, target, 0);

    return answer;
}

void combination_sum::Solution::test() {
    vector<int> test1 {2, 3, 6, 7};
    vector<vector<int>> answer1 {{2, 2, 3}, {7}};
    assert(combinationSum(test1, 7) == answer1);

    cout << "combinationSum completed!" << endl;
}
