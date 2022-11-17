//
// Created by dexhacker on 11/17/22.
//

#include "Solution.h"
#include <cassert>

vector<vector<int>> spiral_matrix_ii::Solution::generateMatrix(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int r = 0;
    int c = 0;
    int d = 0;
    for (int i = 1; i <= n * n; i++)  {
        if (d == 0) {
            answer[r][c] = i;
            if (c + 1 < n && answer[r][c + 1] == 0) {
                c++;
            } else {
                r++;
                d++;
            }
        } else if (d == 1) {
            answer[r][c] = i;
            if (r + 1 < n && answer[r + 1][c] == 0) {
                r++;
            } else {
                c--;
                d++;
            }
        } else if (d == 2) {
            answer[r][c] = i;
            if (c - 1 >= 0 && answer[r][c - 1] == 0) {
                c--;
            } else {
                r--;
                d++;
            }
        } else if (d == 3) {
            answer[r][c] = i;
            if (r - 1 >= 0 && answer[r - 1][c] == 0) {
                r--;
            } else {
                c++;
                d = 0;
            }
        }
    }

    return answer;
}

void spiral_matrix_ii::Solution::test() {
    vector<vector<int>> answer {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    vector<vector<int>> result = generateMatrix(3);
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            assert(answer[i][j] == result[i][j]);
        }
    }

    cout << "generateMatrix completed!" << endl;
}
