//
// Created by dexhacker on 6/3/21.
//

#include "Solution.h"
#include <cassert>

bool partition_to_k_equal_sum_subsets::Solution::dfs(vector<int> &nums, vector<int> visited, int idx, int k,
                                                     int curr_sum, int target_sum) {
    if (k == 1) return true;
    if (curr_sum == target_sum) return dfs(nums, visited, 0, k-1, 0, target_sum);
    for (int i = idx; i < nums.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            if (dfs(nums, visited, i+1, k, curr_sum + nums[i], target_sum)) return true;
            visited[i] = false;
        }
    }
    return false;
}

bool partition_to_k_equal_sum_subsets::Solution::canPartitionKSubsets(vector<int> &nums, int k) {
    vector<int> visited(nums.size(), false);
    int sum = 0;
    for(auto x : nums) sum += x;
    if(sum % k != 0) return false;
    int target_sum = sum / k;
    return dfs(nums, visited, 0, k, 0, target_sum);
}

void partition_to_k_equal_sum_subsets::Solution::test() {
    vector<int> test {4, 3, 2, 3, 5, 2, 1};
    assert(canPartitionKSubsets(test, 4) == true);

    cout << "canPartitionKSubsets completed!" << endl;
}
