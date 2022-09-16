//
// Created by dexhacker on 9/16/22.
//

#ifndef LEETCODE_MAXIMUM_SCORE_FROM_PERFORMING_MULTIPLICATION_OPERATIONS_H
#define LEETCODE_MAXIMUM_SCORE_FROM_PERFORMING_MULTIPLICATION_OPERATIONS_H

#include <iostream>
#include <vector>

using namespace std;

namespace maximum_score_from_performing_multiplication_operations {
    class Solution {
    public:
        int maximumScore(vector<int>& nums, vector<int>& m);
        int rec(int i, int l, int h, vector<int>&nums, vector<int>&m, vector<vector<int>>&dp);
        void test();
    };
}

#endif //LEETCODE_MAXIMUM_SCORE_FROM_PERFORMING_MULTIPLICATION_OPERATIONS_H
