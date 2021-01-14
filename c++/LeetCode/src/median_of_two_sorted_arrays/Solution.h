//
// Created by dexhacker on 1/13/21.
//

#ifndef LEETCODE_MEDIAN_OF_TWO_SORTED_ARRAYS_SOLUTION_H
#define LEETCODE_MEDIAN_OF_TWO_SORTED_ARRAYS_SOLUTION_H

#include <iostream>
#include <vector>

using namespace std;

namespace median_of_two_sorted_arrays {
    class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
        void test();
    };
}


#endif //LEETCODE_MEDIAN_OF_TWO_SORTED_ARRAYS_SOLUTION_H
