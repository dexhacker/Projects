//
// Created by dexhacker on 7/12/21.
//

#ifndef LEETCODE_MINIMUM_COST_TO_REACH_DESTINATION_IN_TIME_H
#define LEETCODE_MINIMUM_COST_TO_REACH_DESTINATION_IN_TIME_H

#include <iostream>
#include <vector>
#include <array>

using namespace std;

namespace minimum_cost_to_reach_destination_in_time {
    class Solution {
    public:
        int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees);
        void test();

    private:
        typedef array<int, 3> Node;
    };
}

#endif //LEETCODE_MINIMUM_COST_TO_REACH_DESTINATION_IN_TIME_H
