//
// Created by dexhacker on 12/24/22.
//

#include "Solution.h"
#include <vector>
#include <cassert>

int domino_and_tromino_tiling::Solution::numTilings(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 5;
    vector<long> dp(n);
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 5;
    for (int i = 3; i < n; i++) dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % 1000000007;
    return dp.back() % 1000000007;
}

void domino_and_tromino_tiling::Solution::test() {
    assert(numTilings(3) == 5);

    cout << "numTilings completed!" << endl;
}
