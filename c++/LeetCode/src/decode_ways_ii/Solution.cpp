//
// Created by dexhacker on 7/11/21.
//

#include "Solution.h"
#include <vector>
#include <cassert>

int decode_ways_ii::Solution::numDecodings(string s) {
    int MOD = 1e9 + 7;

    vector<long> dp(s.size() + 1);
    dp[0] = 1;

    if (s[0] == '*') {
        dp[1] = 9;
    } else if (s[0] == '0') {
        dp[1] = 0;
    } else {
        dp[1] = 1;
    }

    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '*') {
            dp[i + 1] = 9 * dp[i] % MOD;
            if (s[i - 1] == '1')
                dp[i + 1] = (dp[i + 1] + 9 * dp[i - 1]) % MOD;
            else if (s[i - 1] == '2')
                dp[i + 1] = (dp[i + 1] + 6 * dp[i - 1]) % MOD;
            else if (s[i - 1] == '*')
                dp[i + 1] = (dp[i + 1] + 15 * dp[i - 1]) % MOD;
        } else {
            dp[i + 1] = s[i] != '0' ? dp[i] : 0;
            if (s[i - 1] == '1')
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
            else if (s[i - 1] == '2' && s[i] <= '6')
                dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
            else if (s[i - 1] == '*')
                dp[i + 1] = (dp[i + 1] + (s[i] <= '6' ? 2 : 1) * dp[i - 1]) % MOD;
        }
    }
    return (int)dp[s.size()];
}

void decode_ways_ii::Solution::test() {
    assert(numDecodings("2*") == 15);

    cout << "numDecodings completed!" << endl;
}
