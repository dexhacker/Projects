//
// Created by dexhacker on 11/28/22.
//

#ifndef LEETCODE_MAXIMUM_PROFIT_IN_JOB_SCHEDULING_H
#define LEETCODE_MAXIMUM_PROFIT_IN_JOB_SCHEDULING_H

#include <iostream>
#include <vector>

using namespace std;

namespace maximum_profit_in_job_scheduling {
    class Solution {
    public:
        int dfs(vector<vector<int>>& comb, int pos, int last);
        int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit);
        void test();

    private:
        int memo[50001] = {};
    };
}

#endif //LEETCODE_MAXIMUM_PROFIT_IN_JOB_SCHEDULING_H
