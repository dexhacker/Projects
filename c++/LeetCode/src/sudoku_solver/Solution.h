//
// Created by dexhacker on 9/14/22.
//

#ifndef LEETCODE_SUDOKU_SOLVER_H
#define LEETCODE_SUDOKU_SOLVER_H

#include <iostream>
#include <vector>

using namespace std;

namespace sudoku_solver {
    class Solution {
    public:
        bool check(vector<vector<char>> &board, int i, int j, char val);
        bool solveSudoku(vector<vector<char>> &board, int i, int j);
        void solveSudoku(vector<vector<char>>& board);
        void test();
    };
}

#endif //LEETCODE_SUDOKU_SOLVER_H
