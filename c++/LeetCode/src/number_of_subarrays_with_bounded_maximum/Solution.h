//
// Created by dexhacker on 6/17/21.
//

#ifndef LEETCODE_NUMBER_OF_SUBARRAYS_WITH_BOUNDED_MAXIMUM_H
#define LEETCODE_NUMBER_OF_SUBARRAYS_WITH_BOUNDED_MAXIMUM_H

#include <iostream>
#include <vector>

using namespace std;

namespace number_of_subarrays_with_bounded_maximum {
    class Solution {
    public:
        int numSubarrayBoundedMax(vector<int>& nums, int left, int right);
        void test();
    };
}

#endif //LEETCODE_NUMBER_OF_SUBARRAYS_WITH_BOUNDED_MAXIMUM_H
