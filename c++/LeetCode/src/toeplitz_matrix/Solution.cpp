//
// Created by dexhacker on 10/31/22.
//

#include "Solution.h"
#include <cassert>

bool toeplitz_matrix::Solution::isToeplitzMatrix(vector<vector<int>> &matrix) {
    for (int i = 0; i < matrix[0].size(); i++) {
        int number = matrix[0][i];
        int j = 1;
        int k = i + 1;
        while (j < matrix.size() && k < matrix[0].size()) {
            if (number != matrix[j][k]) return false;
            j++;
            k++;
        }
    }

    for (int i = 1; i < matrix.size(); i++) {
        int number = matrix[i][0];
        int j = i + 1;
        int k = 1;
        while (j < matrix.size() && k < matrix[0].size()) {
            if (number != matrix[j][k]) return false;
            j++;
            k++;
        }
    }

    return true;
}

void toeplitz_matrix::Solution::test() {
    vector<vector<int>> test {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
    assert(isToeplitzMatrix(test) == true);

    cout << "isToeplitzMatrix completed!" << endl;
}
