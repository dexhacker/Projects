//
// Created by dexhacker on 1/19/23.
//

#ifndef LEETCODE_SUBARRAY_SUMS_DIVISIBLE_BY_K_H
#define LEETCODE_SUBARRAY_SUMS_DIVISIBLE_BY_K_H

#include <iostream>
#include <vector>

using namespace std;

namespace subarray_sums_divisible_by_k {
    class Solution {
    public:
        int subarraysDivByK(vector<int>& nums, int k);
        void test();
    };
}

#endif //LEETCODE_SUBARRAY_SUMS_DIVISIBLE_BY_K_H
