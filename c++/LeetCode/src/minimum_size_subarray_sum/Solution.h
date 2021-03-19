//
// Created by dexhacker on 3/17/21.
//

#ifndef LEETCODE_MINIMUM_SIZE_SUBARRAY_SUM_H
#define LEETCODE_MINIMUM_SIZE_SUBARRAY_SUM_H

#include <iostream>
#include <vector>

using namespace std;

namespace minimum_size_subarray_sum {
    class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums);
        void test();
    };
}

#endif //LEETCODE_MINIMUM_SIZE_SUBARRAY_SUM_H
