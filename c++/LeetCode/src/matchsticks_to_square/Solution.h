//
// Created by dexhacker on 6/15/21.
//

#ifndef LEETCODE_MATCHSTICKS_TO_SQUARE_H
#define LEETCODE_MATCHSTICKS_TO_SQUARE_H

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

namespace matchsticks_to_square {
    class Solution {
    public:
        bool dfs(vector<int>& nums, int lb, int sum, int target, int k);
        bool makesquare(vector<int>& nums);
        void test();

    private:
        bitset<16> visited;
    };
}

#endif //LEETCODE_MATCHSTICKS_TO_SQUARE_H
