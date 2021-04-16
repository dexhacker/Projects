//
// Created by dexhacker on 4/16/21.
//

#ifndef LEETCODE_SMALLEST_RANGE_COVERING_ELEMENTS_FROM_K_LISTS_H
#define LEETCODE_SMALLEST_RANGE_COVERING_ELEMENTS_FROM_K_LISTS_H

#include <iostream>
#include <vector>

using namespace std;

namespace smallest_range_covering_elements_from_k_lists {
    class Solution {
    public:
        vector<int> smallestRange(vector<vector<int>>& nums);
        void test();
    };
}

#endif //LEETCODE_SMALLEST_RANGE_COVERING_ELEMENTS_FROM_K_LISTS_H
