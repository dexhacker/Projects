//
// Created by dexhacker on 5/20/21.
//

#ifndef LEETCODE_COMBINATION_SUM_III_H
#define LEETCODE_COMBINATION_SUM_III_H

#include <iostream>
#include <vector>

using namespace std;

namespace combination_sum_iii {
    class Solution {
    public:
        vector<vector<int>> combinationSum3(int k, int n);
        void solve(vector<int> & seq, int pos);
        void test();

    private:
        int k, n;
        vector<vector<int>> list;
        vector<int> used;
    };
}

#endif //LEETCODE_COMBINATION_SUM_III_H
