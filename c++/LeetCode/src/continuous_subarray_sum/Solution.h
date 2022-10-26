//
// Created by dexhacker on 10/26/22.
//

#ifndef LEETCODE_CONTINUOUS_SUBARRAY_SUM_H
#define LEETCODE_CONTINUOUS_SUBARRAY_SUM_H

#include <iostream>
#include <vector>

using namespace std;

namespace continuous_subarray_sum {
    class Solution {
    public:
        bool checkSubarraySum(vector<int>& nums, int k);
        void test();
    };
}

#endif //LEETCODE_CONTINUOUS_SUBARRAY_SUM_H
