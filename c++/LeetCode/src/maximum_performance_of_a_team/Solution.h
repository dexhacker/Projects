//
// Created by dexhacker on 6/5/21.
//

#ifndef LEETCODE_MAXIMUM_PERFORMANCE_OF_A_TEAM_H
#define LEETCODE_MAXIMUM_PERFORMANCE_OF_A_TEAM_H

#include <iostream>
#include <vector>

using namespace std;

namespace maximum_performance_of_a_team {
    class Solution {
    public:
        int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k);
        void test();
    };
}

#endif //LEETCODE_MAXIMUM_PERFORMANCE_OF_A_TEAM_H
