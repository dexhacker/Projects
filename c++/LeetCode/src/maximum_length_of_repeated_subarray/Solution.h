//
// Created by dexhacker on 7/8/21.
//

#ifndef LEETCODE_MAXIMUM_LENGTH_OF_REPEATED_SUBARRAY_H
#define LEETCODE_MAXIMUM_LENGTH_OF_REPEATED_SUBARRAY_H

#include <iostream>
#include <vector>

using namespace std;

namespace maximum_length_of_repeated_subarray {
    class Solution {
    public:
        int findLength(vector<int>& nums1, vector<int>& nums2);
        void test();
    };
}

#endif //LEETCODE_MAXIMUM_LENGTH_OF_REPEATED_SUBARRAY_H
