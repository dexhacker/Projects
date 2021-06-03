//
// Created by dexhacker on 6/3/21.
//

#ifndef LEETCODE_PARTITION_TO_K_EQUAL_SUM_SUBSETS_H
#define LEETCODE_PARTITION_TO_K_EQUAL_SUM_SUBSETS_H

#include <iostream>
#include <vector>

using namespace std;

namespace partition_to_k_equal_sum_subsets {
    class Solution {
    public:
        bool canPartitionKSubsets(vector<int>& nums, int k);
        bool dfs(vector<int>& nums,vector<int>visited,int idx,int k,int curr_sum,int target_sum);
        void test();
    };
}

#endif //LEETCODE_PARTITION_TO_K_EQUAL_SUM_SUBSETS_H
