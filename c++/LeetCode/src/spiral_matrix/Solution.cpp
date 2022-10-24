//
// Created by dexhacker on 10/24/22.
//

#include "Solution.h"
#include <cassert>

void spiral_matrix::Solution::go(vector<vector<int>> &m, std::string dir, int r, int d, int l, int u) {
    if (r < l || d < u) return;

    if (dir == "right") {
        for (int i = l; i <= r; i++) answer.push_back(m[u][i]);
        go(m, "down", r, d, l, u + 1);
    } else if (dir == "down") {
        for (int i = u; i <= d; i++) answer.push_back(m[i][r]);
        go(m, "left", r - 1, d, l, u);
    } else if (dir == "left") {
        for (int i = r; i >= l; i--) answer.push_back(m[d][i]);
        go(m, "up", r, d - 1, l, u);
    } else {
        for (int i = d; i >= u; i--) answer.push_back(m[i][l]);
        go(m, "right", r, d, l + 1, u);
    }
}

vector<int> spiral_matrix::Solution::spiralOrder(vector<vector<int>> &matrix) {
    go(matrix, "right", matrix[0].size() - 1, matrix.size() - 1, 0, 0);
    return answer;
}

void spiral_matrix::Solution::test() {
    vector<vector<int>> test {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result {1, 2, 3, 6, 9, 8, 7, 4, 5};

    assert(spiralOrder(test) == result);

    cout << "spiralOrder completed!" << endl;
}
