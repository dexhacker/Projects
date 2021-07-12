//
// Created by dexhacker on 7/8/21.
//

#ifndef LEETCODE_RESHAPE_THE_MATRIX_H
#define LEETCODE_RESHAPE_THE_MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

namespace reshape_the_matrix {
    class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c);
        void test();
    };
}

#endif //LEETCODE_RESHAPE_THE_MATRIX_H
