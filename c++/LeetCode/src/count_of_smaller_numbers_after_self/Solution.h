//
// Created by dexhacker on 6/28/21.
//

#ifndef LEETCODE_COUNT_OF_SMALLER_NUMBERS_AFTER_SELF_H
#define LEETCODE_COUNT_OF_SMALLER_NUMBERS_AFTER_SELF_H

#include <iostream>
#include <vector>

using namespace std;

namespace count_of_smaller_numbers_after_self {
    class Solution {
    public:
        void merge_countSmaller(vector<int>& indices, int first, int last, vector<int>& results, vector<int>& nums);
        vector<int> countSmaller(vector<int>& nums);
        void test();
    };
}

#endif //LEETCODE_COUNT_OF_SMALLER_NUMBERS_AFTER_SELF_H
