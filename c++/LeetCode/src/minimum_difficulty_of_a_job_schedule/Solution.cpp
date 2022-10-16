//
// Created by dexhacker on 10/16/22.
//

#include "Solution.h"
#include <cassert>

int minimum_difficulty_of_a_job_schedule::Solution::minDifficulty(vector<int> &jobDifficulty, int d) {
    int n = jobDifficulty.size(), inf = 1e9, maxd;
    if (n < d) return -1;
    vector<int> dp(n + 1, 1e9);
    dp[n] = 0;
    for (int k = 1; k <= d; ++k) {
        for (int i = 0; i <= n - k; ++i) {
            maxd = 0, dp[i] = inf;
            for (int j = i; j <= n - k; ++j) {
                maxd = max(maxd, jobDifficulty[j]);
                dp[i] = min(dp[i], maxd + dp[j + 1]);
            }
        }
    }
    return dp[0];
}

void minimum_difficulty_of_a_job_schedule::Solution::test() {
    vector<int> test {6, 5, 4, 3, 2, 1};
    assert(minDifficulty(test, 2) == 7);

    cout << "minDifficulty completed!" << endl;
}
