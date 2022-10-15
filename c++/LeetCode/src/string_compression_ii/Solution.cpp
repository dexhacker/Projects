//
// Created by dexhacker on 10/16/22.
//

#include "Solution.h"
#include <cstring>
#include <cassert>

int string_compression_ii::Solution::dfs(std::string &s, int left, int K) {
    int k = K;
    if(s.size() - left <= k) return 0;
    if(dp[left][k] >= 0) return dp[left][k];
    int res = k ? dfs(s, left + 1, k - 1) : 10000, c = 1;
    for(int i = left + 1; i <= s.size(); ++i) {
        res = min(res, dfs(s, i, k) + 1 + (c >= 100 ? 3 : (c >= 10 ? 2 : (c > 1 ? 1 :0))));
        if(i == s.size()) break;
        if(s[i] == s[left]) ++c;
        else if(--k < 0) break;
    }
    return dp[left][K] = res;
}

int string_compression_ii::Solution::getLengthOfOptimalCompression(std::string s, int k) {
    std::memset(dp, -1, sizeof(dp));
    return dfs(s, 0, k);
}

void string_compression_ii::Solution::test() {
    assert(getLengthOfOptimalCompression("aaabcccd", 2) == 4);

    cout << "getLengthOfOptimalCompression completed!" << endl;
}
