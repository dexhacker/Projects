//
// Created by dexhacker on 10/31/22.
//

#ifndef LEETCODE_TOEPLITZ_MATRIX_H
#define LEETCODE_TOEPLITZ_MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

namespace toeplitz_matrix {
    class Solution {
    public:
        bool isToeplitzMatrix(vector<vector<int>>& matrix);
        void test();
    };
}

#endif //LEETCODE_TOEPLITZ_MATRIX_H
