//
// Created by Farid on 13.12.2022.
//

#include "Solution.h"
#include <cassert>

int minimum_falling_path_sum::Solution::minFallingPathSum(vector<vector<int>> &matrix) {
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix[0].size(); i++) dp[0][i] = matrix[0][i];

    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            dp[i][j] = dp[i - 1][j] + matrix[i][j];
            if (j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + matrix[i][j]);
            if (j + 1 < matrix[i].size()) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + matrix[i][j]);
        }
    }

    int answer = dp[dp.size() - 1][0];
    for (int i = 1; i < dp[dp.size() - 1].size(); i++) if (answer > dp[dp.size() - 1][i]) answer = dp[dp.size() - 1][i];
    return answer;
}

void minimum_falling_path_sum::Solution::test() {
    vector<vector<int>> test {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    assert(minFallingPathSum(test) == 13);

    cout << "minFallingPathSum completed!" << endl;
}
