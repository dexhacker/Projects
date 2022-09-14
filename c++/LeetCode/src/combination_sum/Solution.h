//
// Created by dexhacker on 9/14/22.
//

#ifndef LEETCODE_COMBINATION_SUM_H
#define LEETCODE_COMBINATION_SUM_H

#include <iostream>
#include <vector>

using namespace std;

namespace combination_sum {
    class Solution {
    public:
        void calculate_sum(vector<int>& combinations, int sum, vector<int>& candidates, int target, int index);
        vector<vector<int>> combinationSum(vector<int>& candidates, int target);
        void test();

    private:
        vector<vector<int>> answer;
    };
}

#endif //LEETCODE_COMBINATION_SUM_H
