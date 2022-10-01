//
// Created by dexhacker on 10/1/22.
//

#ifndef LEETCODE_DECODE_WAYS_H
#define LEETCODE_DECODE_WAYS_H

#include <iostream>
#include <vector>

using namespace std;

namespace decode_ways {
    class Solution {
    public:
        void dfs(string s, int index, vector<int> & dp);
        int numDecodings(string s);
        void test();
    };
}

#endif //LEETCODE_DECODE_WAYS_H
