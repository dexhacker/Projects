//
// Created by dexhacker on 1/20/23.
//

#include "Solution.h"
#include <cassert>

void non_decreasing_subsequences::Solution::dfs(vector<int> &nums, vector<int> v, int index) {
    if (v.size() > 1) answer.push_back(v);
    if (index >= nums.size()) return;

    for (int i = index; i < nums.size(); i++) {
        if (v.empty() || v.back() <= nums[i]) {
            v.push_back(nums[i]);
            dfs(nums, v, i + 1);
            v.pop_back();
        }
    }
}

vector<vector<int>> non_decreasing_subsequences::Solution::findSubsequences(vector<int> &nums) {
    vector<int> v;
    dfs(nums, v, 0);

    sort( answer.begin(), answer.end() );
    answer.erase( unique( answer.begin(), answer.end() ), answer.end() );
    return answer;
}

void non_decreasing_subsequences::Solution::test() {
    vector<int> nums {4, 6, 7, 7};
    vector<vector<int>> answer {{4, 6}, {4, 6, 7}, {4, 6, 7, 7}, {4, 7}, {4, 7, 7}, {6, 7}, {6, 7, 7}, {7, 7}};
    auto result = findSubsequences(nums);
    for (int i = 0; i < answer.size(); i++) for (int j = 0; j < answer[i].size(); j++) assert(answer[i][j] == result[i][j]);

    cout << "findSubsequences completed!" << endl;
}
