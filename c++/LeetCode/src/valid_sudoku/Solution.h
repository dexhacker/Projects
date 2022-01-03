//
// Created by Фарид Абдугалыев on 03.01.2022.
//

#ifndef LEETCODE_VALID_SUDOKU_H
#define LEETCODE_VALID_SUDOKU_H

#include <iostream>
#include <vector>

using namespace std;

namespace valid_sudoku {
    class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board);
        void test();
    };
}

#endif //LEETCODE_VALID_SUDOKU_H
