//
// Created by dexhacker on 10/24/22.
//

#ifndef LEETCODE_SPIRAL_MATRIX_H
#define LEETCODE_SPIRAL_MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

namespace spiral_matrix {
    class Solution {
    public:
        void go(vector<vector<int>>& m, string dir, int r, int d, int l, int u);
        vector<int> spiralOrder(vector<vector<int>>& matrix);
        void test();

    private:
        vector<int> answer;
    };
}

#endif //LEETCODE_SPIRAL_MATRIX_H
