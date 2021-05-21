//
// Created by dexhacker on 4/29/21.
//

#include "Solution.h"
#include <cassert>

int min_cost_climbing_stairs::Solution::minCostClimbingStairs(vector<int> &cost) {
    vector<int> prefix {cost[0], cost[1]};
    for (int i = 2; i < cost.size(); i++) prefix.push_back(min(prefix[i - 2], prefix[i - 1]) + cost[i]);
    return min(prefix[prefix.size() - 2], prefix[prefix.size() - 1]);
}

void min_cost_climbing_stairs::Solution::test() {
    vector<int> test1 {10, 15, 20};
    assert(minCostClimbingStairs(test1) == 15);

    vector<int> test2 {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    assert(minCostClimbingStairs(test2) == 6);

    cout << "minCostClimbingStairs completed!" << endl;
}