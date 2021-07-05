//
// Created by dexhacker on 6/22/21.
//

#include "Solution.h"
#include <set>
#include <cassert>

vector<vector<int>> sum4::Solution::fourSum(vector<int> &nums, int target) {
    if (nums.size() < 4) return {};

    sort(nums.begin(), nums.end());
    set<vector<int>> answer;

    for (int i = 0; i < nums.size() - 3; ++i) {
        for (int j = i + 1; j < nums.size() - 2; ++j) {
            int l = j + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[j] + nums[l] + nums[r];
                if (target == sum) {
                    answer.insert({nums[i], nums[j], nums[l], nums[r]});
                    --r;
                    ++l;
                } else if (sum > target) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
    }

    vector<vector<int>> result(answer.begin(), answer.end());
    return result;
}

void sum4::Solution::test() {
    vector<int> test {1, 0, -1, 0, -2, 2};
    vector<vector<int>> answer {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    assert(fourSum(test, 0) == answer);

    cout << "fourSum completed!" << endl;
}
