//
// Created by dexhacker on 11/22/22.
//

#include "Solution.h"
#include <vector>
#include <bits/stdc++.h>
#include <cassert>

int perfect_squares::Solution::numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int target = 1; target <= n; target++) {
        int mnCount = INT_MAX;
        for (int num = 1; num <= sqrt(target); num++) {
            int sqNum = num * num;
            int currCount = 1 + dp[target - sqNum];
            mnCount = min(mnCount, currCount);
        }
        dp[target] = mnCount;
    }
    return dp[n];
}

void perfect_squares::Solution::test() {
    assert(numSquares(12) == 3);

    cout << "numSquares completed!" << endl;
}
