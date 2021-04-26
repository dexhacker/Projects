//
// Created by dexhacker on 4/26/21.
//

#ifndef LEETCODE_BURST_BALLOONS_H
#define LEETCODE_BURST_BALLOONS_H

#include <iostream>
#include <vector>

using namespace std;

namespace burst_balloons {
    class Solution {
    public:
        int maxCoins(vector<int>& nums);
        int maxCoins(vector<int>& nums, int l, int r);
        void test();

    private:
        vector<vector<int>> cache;
    };
}

#endif //LEETCODE_BURST_BALLOONS_H
