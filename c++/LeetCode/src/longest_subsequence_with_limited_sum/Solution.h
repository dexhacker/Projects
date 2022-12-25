//
// Created by dexhacker on 12/25/22.
//

#ifndef LEETCODE_LONGEST_SUBSEQUENCE_WITH_LIMITED_SUM_H
#define LEETCODE_LONGEST_SUBSEQUENCE_WITH_LIMITED_SUM_H

#include <iostream>
#include <vector>

using namespace std;

namespace longest_subsequence_with_limited_sum {
    class Solution {
    public:
        vector<int> answerQueries(vector<int>& nums, vector<int>& queries);
        void test();
    };
}

#endif //LEETCODE_LONGEST_SUBSEQUENCE_WITH_LIMITED_SUM_H
