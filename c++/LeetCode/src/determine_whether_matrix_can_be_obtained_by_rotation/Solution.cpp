//
// Created by dexhacker on 6/6/21.
//

#include "Solution.h"
#include <cassert>

vector<vector<int>> determine_whether_matrix_can_be_obtained_by_rotation::Solution::move(vector<vector<int>> &mat) {
    vector<vector<int>> tmp;
    for (int i = 0; i < mat[0].size(); i++) {
        vector<int> row;
        for (int j = mat.size() - 1; j >= 0; j--) {
            row.push_back(mat[j][i]);
        }
        tmp.push_back(row);
    }
    return tmp;
}

bool determine_whether_matrix_can_be_obtained_by_rotation::Solution::isEqual(vector<vector<int>> &mat,
                                                                             vector<vector<int>> &target) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] != target[i][j]) return false;
        }
    }
    return true;
}

bool determine_whether_matrix_can_be_obtained_by_rotation::Solution::findRotation(vector<vector<int>> &mat,
                                                                                  vector<vector<int>> &target) {
    if (isEqual(mat, target)) return true;

    for (int i = 0; i < 3; i++) {
        mat = move(mat);
        if (isEqual(mat, target)) return true;
    }
    return false;
}

void determine_whether_matrix_can_be_obtained_by_rotation::Solution::test() {
    vector<vector<int>> mat {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> target {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    assert(findRotation(mat, target) == true);

    cout << "findRotation completed!" << endl;
}
