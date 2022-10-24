//
// Created by dexhacker on 10/24/22.
//

#ifndef LEETCODE_N_QUEENS_II_H
#define LEETCODE_N_QUEENS_II_H

#include <iostream>
#include <vector>

using namespace std;

namespace n_queens_ii {
    class Solution {
    public:
        void req(int n, vector<vector<bool>>& b, int row);
        int totalNQueens(int n);
        void test();

    private:
        int answer = 0;
    };
}

#endif //LEETCODE_N_QUEENS_II_H
