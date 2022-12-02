//
// Created by dexhacker on 12/2/22.
//

#include "Solution.h"
#include <vector>
#include <cassert>

int unique_paths::Solution::uniquePaths(int m, int n) {
    vector<vector<int>> d(m, vector<int>(n, 0));
    d[m - 1][n - 1] = 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (j + 1 < n) d[i][j] += d[i][j + 1];
            if (i + 1 < m) d[i][j] += d[i + 1][j];
        }
    }
    return d[0][0];
}

void unique_paths::Solution::test() {
    assert(uniquePaths(3, 7) == 28);

    cout << "uniquePaths completed!" << endl;
}
