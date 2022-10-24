//
// Created by dexhacker on 10/24/22.
//

#include "Solution.h"
#include <cassert>

void n_queens_ii::Solution::req(int n, vector<vector<bool>> &b, int row) {
    if (row == n) {
        answer++;

        return;
    }

    for (int i = 0; i < n; i++) {

        bool any = false;
        for (int j = 0; j < row; j++) {
            if (b[j][i]) {
                any = true;
                break;
            }
        }
        if (any) continue;

        for (int j = row - 1; j >= 0; j--) {
            if (i - (row - j) >= 0 && b[j][i - (row - j)]) {
                any = true;
                break;
            }
            if (i + (row - j) < n && b[j][i + (row - j)]) {
                any = true;
                break;
            }
        }
        if (any) continue;

        b[row][i] = true;
        req(n, b, row + 1);
        b[row][i] = false;
    }
}

int n_queens_ii::Solution::totalNQueens(int n) {
    vector<vector<bool>> b(n, vector<bool>(n, false));
    req(n, b, 0);
    return answer;
}

void n_queens_ii::Solution::test() {
    assert(totalNQueens(4) == 2);

    cout << "totalNQueens completed!" << endl;
}
