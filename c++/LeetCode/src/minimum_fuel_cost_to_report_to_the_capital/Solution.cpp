//
// Created by dexhacker on 2/12/23.
//

#include "Solution.h"
#include <cassert>

int minimum_fuel_cost_to_report_to_the_capital::Solution::dfs(int i, vector<vector<int>> &v, vector<bool> &used, int seats) {
    int count = 1;
    for (auto j : v[i]) {
        if (!used[j]) {
            used[j] = true;
            count += dfs(j, v, used, seats);
        }
    }

    if (i != 0) {
        answer += count / seats;
        if (count % seats != 0) answer++;
    }

    return count;
}

long long minimum_fuel_cost_to_report_to_the_capital::Solution::minimumFuelCost(vector<vector<int>> &roads, int seats) {
    vector<vector<int>> v(roads.size() + 1);
    vector<bool> used(roads.size() + 1, false);
    for (auto i : roads) {
        v[i[0]].push_back(i[1]);
        v[i[1]].push_back(i[0]);
    }

    used[0] = true;
    dfs(0, v, used, seats);

    return answer;
}

void minimum_fuel_cost_to_report_to_the_capital::Solution::test() {
    vector<vector<int>> roads {{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}};
    assert(minimumFuelCost(roads, 2) == 7);

    cout << "minimumFuelCost completed!" << endl;
}
