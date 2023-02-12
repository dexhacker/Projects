//
// Created by dexhacker on 2/12/23.
//

#ifndef LEETCODE_MINIMUM_FUEL_COST_TO_REPORT_TO_THE_CAPITAL_H
#define LEETCODE_MINIMUM_FUEL_COST_TO_REPORT_TO_THE_CAPITAL_H

#include <iostream>
#include <vector>

using namespace std;

namespace minimum_fuel_cost_to_report_to_the_capital {
    class Solution {
    private:
        long long answer = 0;

    public:
        int dfs (int i, vector<vector<int>>& v, vector<bool>& used, int seats);
        long long minimumFuelCost(vector<vector<int>>& roads, int seats);
        void test();
    };
}

#endif //LEETCODE_MINIMUM_FUEL_COST_TO_REPORT_TO_THE_CAPITAL_H
