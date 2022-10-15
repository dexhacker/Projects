//
// Created by dexhacker on 10/16/22.
//

#ifndef LEETCODE_STRING_COMPRESSION_II_H
#define LEETCODE_STRING_COMPRESSION_II_H

#include <iostream>

using namespace std;

namespace string_compression_ii {
    class Solution {
    public:
        int dfs(string &s, int left, int K);
        int getLengthOfOptimalCompression(string s, int k);
        void test();

    private:
        int dp[101][101];
    };
}

#endif //LEETCODE_STRING_COMPRESSION_II_H
