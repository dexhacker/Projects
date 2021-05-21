//
// Created by dexhacker on 4/29/21.
//

#ifndef LEETCODE_RANGE_SUM_QUERY_2D_IMMUTABLE_H
#define LEETCODE_RANGE_SUM_QUERY_2D_IMMUTABLE_H

#include <iostream>
#include <vector>

using namespace std;

namespace range_sum_query_2d_immutable {
    class NumMatrix {
    public:
        static void test();
        NumMatrix(vector<vector<int>>& matrix);
        int sumRegion(int row1, int col1, int row2, int col2);

    private:
        vector<vector<int>> prefix;
    };
}

#endif //LEETCODE_RANGE_SUM_QUERY_2D_IMMUTABLE_H
