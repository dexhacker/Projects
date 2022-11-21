//
// Created by dexhacker on 11/21/22.
//

#ifndef LEETCODE_ERECT_THE_FENCE_H
#define LEETCODE_ERECT_THE_FENCE_H

#include <iostream>
#include <vector>

using namespace std;

namespace erect_the_fence {
    class Solution {
    public:
        bool isClockwiseTurn(vector<int> &a, vector<int> &b, vector<int> &c);
        vector<vector<int>> outerTrees(vector<vector<int>>& trees);
        void test();
    };
}

#endif //LEETCODE_ERECT_THE_FENCE_H
