//
// Created by dexhacker on 6/2/21.
//

#include "Solution.h"
#include <cassert>
#include <vector>

bool interleaving_string::Solution::isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    vector<bool> dp(s2.size() + 1, false);
    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            if (i == 0 and j == 0) dp[j] = true;
            else if (i == 0) dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
            else if (j == 0) dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
            else dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }
    return dp[s2.size()];
}

void interleaving_string::Solution::test() {
    assert(isInterleave("aabcc", "dbbca", "aadbbcbcac") == true);
    assert(isInterleave("aabcc", "dbbca", "aadbbbaccc") == false);
    assert(isInterleave("", "", "") == true);

    cout << "isInterleave completed!" << endl;
}
