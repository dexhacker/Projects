//
// Created by dexhacker on 6/19/21.
//

#include "Solution.h"
#include <vector>
#include <cassert>

int k_inverse_pairs_array::Solution::kInversePairs(int n, int k) {
    vector<vector<int>> dp = vector(n + 1, vector(k + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j == 0) {
                dp[i][j] = 1;
            } else {
                for (int p = 0; p <= min(j, i -1); ++p) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % MOD;
                }
            }
        }
    }

    return dp[n][k];
}

void k_inverse_pairs_array::Solution::test() {
    assert(kInversePairs(3, 1) == 2);

    cout << "kInversePairs completed!" << endl;
}
