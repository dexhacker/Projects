//
// Created by dexhacker on 10/1/22.
//

#include "Solution.h"
#include <cassert>

void decode_ways::Solution::dfs(std::string s, int index, vector<int> &dp) {
    int answer = 0;

    string number;
    number.push_back(s[index]);

    if (stoi(number) > 0) {
        if (index + 1 < s.size()) {
            if (dp[index + 1] == -1) dfs(s, index + 1, dp);
            answer += dp[index + 1];
        } else {
            answer++;
        }
    }

    if (index + 1 >= s.size()) {
        dp[index] = answer;
        return;
    }

    string s2 = number + s[index + 1];

    if (stoi(s2) > 9 && stoi(s2) < 27) {
        if (index + 2 < s.size()) {
            if (dp[index + 2] == -1) dfs(s, index + 2, dp);
            answer += dp[index + 2];
        } else {
            answer++;
        }
    }

    dp[index] = answer;
}

int decode_ways::Solution::numDecodings(std::string s) {
    vector<int> dp(100, -1);
    dfs(s, 0, dp);

    return dp[0];
}

void decode_ways::Solution::test() {
    assert(numDecodings("226") == 3);

    cout << "numDecodings completed!" << endl;
}
