//
// Created by dexhacker on 4/30/21.
//

#ifndef LEETCODE_COIN_CHANGE_H
#define LEETCODE_COIN_CHANGE_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace coin_change {
    class Solution {
    public:
        int coinChange(vector<int>& coins, int amount);
        void test();
    };
}

#endif //LEETCODE_COIN_CHANGE_H
