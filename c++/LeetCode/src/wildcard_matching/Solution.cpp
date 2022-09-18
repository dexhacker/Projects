//
// Created by dexhacker on 9/18/22.
//

#include "Solution.h"
#include <vector>
#include <cassert>

bool wildcard_matching::Solution::isMatch(std::string s, std::string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1));
    dp[0][0] = true;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] != '*') break;

        dp[0][i + 1] = true;
    }

    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j < dp[i].size(); j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            } else {
                dp[i][j] = false;
            }
        }
    }

    return dp[s.size()][p.size()];
}

void wildcard_matching::Solution::test() {
    assert(isMatch("aa", "a") == false);
    assert(isMatch("aa", "*") == true);
    assert(isMatch("cb", "?a") == false);

    cout << "isValidBST completed!" << endl;
}
