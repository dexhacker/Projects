//
// Created by dexhacker on 11/28/22.
//

#ifndef LEETCODE_FIND_PLAYERS_WITH_ZERO_OR_ONE_LOSSES_H
#define LEETCODE_FIND_PLAYERS_WITH_ZERO_OR_ONE_LOSSES_H

#include <iostream>
#include <vector>

using namespace std;

namespace find_players_with_zero_or_one_losses {
    class Solution {
    public:
        vector<vector<int>> findWinners(vector<vector<int>>& matches);
        void test();
    };
}

#endif //LEETCODE_FIND_PLAYERS_WITH_ZERO_OR_ONE_LOSSES_H
