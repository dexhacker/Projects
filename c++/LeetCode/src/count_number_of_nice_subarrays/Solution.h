//
// Created by dexhacker on 3/18/21.
//

#ifndef LEETCODE_COUNT_NUMBER_OF_NICE_SUBARRAYS_H
#define LEETCODE_COUNT_NUMBER_OF_NICE_SUBARRAYS_H

#include <iostream>
#include <vector>

using namespace std;

namespace count_number_of_nice_subarrays {
    class Solution {
    public:
        int numberOfSubarrays(vector<int>& nums, int k);
        void test();
    };
}

#endif //LEETCODE_COUNT_NUMBER_OF_NICE_SUBARRAYS_H
