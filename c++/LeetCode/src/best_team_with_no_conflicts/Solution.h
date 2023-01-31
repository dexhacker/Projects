//
// Created by dexhacker on 1/31/23.
//

#ifndef LEETCODE_BEST_TEAM_WITH_NO_CONFLICTS_H
#define LEETCODE_BEST_TEAM_WITH_NO_CONFLICTS_H

#include <iostream>
#include <vector>

using namespace std;

namespace best_team_with_no_conflicts {
    class Solution {
    public:
        static bool comporator(pair<int, int> i1, pair<int, int> i2);
        int bestTeamScore(vector<int>& scores, vector<int>& ages);
        void test();
    };
}

#endif //LEETCODE_BEST_TEAM_WITH_NO_CONFLICTS_H
