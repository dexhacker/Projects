//
// Created by dexhacker on 10/13/22.
//

#include "Solution.h"
#include <cassert>

void rotate_image::Solution::rotate(vector<vector<int>> &matrix) {
    vector<vector<int>> tmp(matrix);

    for (int i = 0; i < tmp.size(); i++) {
        for (int j = 0; j < tmp[i].size(); j++) {
            matrix[j][tmp.size() - 1 - i] = tmp[i][j];
        }
    }
}

void rotate_image::Solution::test() {
    vector<vector<int>> test {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> answer {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    rotate(test);
    for (int i = 0; i < test.size(); i++) {
        for (int j = 0; j < test[i].size(); j++) {
            assert(test[i][j] == answer[i][j]);
        }
    }

    cout << "rotate completed!" << endl;
}
