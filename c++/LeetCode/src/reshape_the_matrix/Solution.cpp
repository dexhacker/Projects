//
// Created by dexhacker on 7/8/21.
//

#include "Solution.h"
#include <cassert>

vector<vector<int>> reshape_the_matrix::Solution::matrixReshape(vector<vector<int>> &mat, int r, int c) {
    if (mat.size() * mat[0].size() != r * c) return mat;

    vector<vector<int>> answer(r, vector<int>(c));
    int l = 0;
    int m = 0;

    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            if (m == c) {
                m = 0;
                ++l;
            }
            answer[l][m] = mat[i][j];
            ++m;
        }
    }

    return answer;
}

void reshape_the_matrix::Solution::test() {
    vector<vector<int>> test {{1, 2}, {3, 4}};
    vector<vector<int>> answer {{1, 2, 3, 4}};
    assert(matrixReshape(test, 1, 4) == answer);

    cout << "matrixReshape completed!" << endl;
}
