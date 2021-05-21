//
// Created by dexhacker on 4/29/21.
//

#include "NumMatrix.h"
#include <cassert>

range_sum_query_2d_immutable::NumMatrix::NumMatrix(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        vector<int> row;
        int sum = 0;
        for (int j = 0; j < matrix[i].size(); j++) {
            sum += matrix[i][j];
            if (i - 1 >= 0) sum += prefix[i - 1][j];
            if (i - 1 >= 0 && j - 1 >= 0) sum -= prefix[i - 1][j - 1];
            row.push_back(sum);
        }
        prefix.push_back(row);
    }
}

int range_sum_query_2d_immutable::NumMatrix::sumRegion(int row1, int col1, int row2, int col2) {
    int sum = prefix[row2][col2];
    if (row1 - 1 >= 0) sum -= prefix[row1 - 1][col2];
    if (col1 - 1 >= 0) sum -= prefix[row2][col1 - 1];
    if (row1 - 1 >= 0 && col1 - 1 >= 0) sum += prefix[row1 - 1][col1 - 1];
    return sum;
}

void range_sum_query_2d_immutable::NumMatrix::test() {
    vector<vector<int>> vector1 {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    auto test1 = new NumMatrix(vector1);
    assert(test1->sumRegion(2, 1, 4, 3) == 8);
    assert(test1->sumRegion(1, 1, 2, 2) == 11);
    assert(test1->sumRegion(1, 2, 2, 4) == 12);

    cout << "sumRegion completed!" << endl;
}
