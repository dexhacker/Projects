//
// Created by dexhacker on 6/15/21.
//

#include "Solution.h"
#include <cassert>

bool matchsticks_to_square::Solution::dfs(vector<int> &nums, int lb, int sum, int target, int k) {
    if (k == 1) return true;
    if (sum == target) return dfs(nums, 0, 0, target, k - 1);
    if (lb >= nums.size()) return false;
    for (int i = lb; i < nums.size(); ++i) {
        if (sum + nums[i] <= target && !visited[i]) {
            visited[i] = true;
            if (dfs(nums, i + 1, sum + nums[i], target, k))
                return true;
            visited[i] = false;
        }
    }
    return false;
}

bool matchsticks_to_square::Solution::makesquare(vector<int> &nums) {
    if (!nums.size()) return false;
    int sum = 0;
    for (auto i : nums) sum += i;
    if (sum % 4 != 0) return false;
    return dfs(nums, 0, 0, sum / 4, 4);
}

void matchsticks_to_square::Solution::test() {
    vector<int> test {1, 1, 2, 2, 2};
    assert(makesquare(test) == true);

    cout << "makesquare completed!" << endl;
}
