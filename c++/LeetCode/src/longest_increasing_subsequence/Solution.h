//
// Created by dexhacker on 7/10/21.
//

#ifndef LEETCODE_LONGEST_INCREASING_SUBSEQUENCE_H
#define LEETCODE_LONGEST_INCREASING_SUBSEQUENCE_H

#include <iostream>
#include <vector>

using namespace std;

namespace longest_increasing_subsequence {
    class Solution {
    public:
        int lengthOfLIS(vector<int>& nums);
        void test();
    };
}

#endif //LEETCODE_LONGEST_INCREASING_SUBSEQUENCE_H
