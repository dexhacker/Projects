//
// Created by dexhacker on 5/1/21.
//

#ifndef LEETCODE_N_QUEENS_H
#define LEETCODE_N_QUEENS_H

#include <iostream>
#include <vector>

using namespace std;

namespace n_queens {
    class Solution {
    public:
        vector<vector<string>> solveNQueens(int n);
        void solve(vector<int> & current_seq, int current_position);
        bool is_valid_placing(vector<int> & current_seq);
        void test();

    private:
        int n;
        vector<vector<int>> list;
        vector<int> used;
    };
}

#endif //LEETCODE_N_QUEENS_H
