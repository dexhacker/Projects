//
// Created by dexhacker on 6/11/21.
//

#include "Solution.h"
#include <cassert>

int stone_game_vii::Solution::stoneGameVII(vector<int> &stones) {
    int N = stones.size();
    vector<int> sum(N + 1);
    for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + stones[i];
    vector<vector<int>> dp(N, vector<int>(N));
    for (int len = 2; len <= N; ++len) {
        for (int i = 0; i <= N - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = max(sum[j + 1] - sum[i + 1] - dp[i + 1][j], sum[j] - sum[i] - dp[i][j - 1]);
        }
    }
    return dp[0][N - 1];
}

void stone_game_vii::Solution::test() {
    vector<int> test {7, 90, 5, 1, 100, 10, 10, 2};
    assert(stoneGameVII(test) == 122);

    cout << "stoneGameVII completed!" << endl;
}
