//
// Created by dexhacker on 11/28/22.
//

#include "Solution.h"
#include <cstring>
#include <cassert>

int maximum_profit_in_job_scheduling::Solution::dfs(vector<vector<int>> &comb, int pos, int last) {
    if(pos >= comb.size()) return 0;
    if(comb[pos][0] < last) return dfs(comb, pos+1, last);
    if(memo[pos] != -1) return memo[pos];
    int ans = 0;
    ans = max(dfs(comb, pos + 1, comb[pos][1]) + comb[pos][2], dfs(comb, pos + 1, 0));
    return memo[pos] = ans;
}

int maximum_profit_in_job_scheduling::Solution::jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
    memset(memo, -1, sizeof memo);
    vector<vector<int>> comb;
    for(int i = 0; i < startTime.size(); i++) comb.push_back({startTime[i], endTime[i], profit[i]});
    sort(comb.begin(), comb.end());
    return dfs(comb, 0, 0);
}

void maximum_profit_in_job_scheduling::Solution::test() {
    vector<int> startTime {1, 2, 3, 3};
    vector<int> endTime {3, 4, 5, 6};
    vector<int> profit {50, 10, 40, 70};
    assert(jobScheduling(startTime, endTime, profit) == 120);

    cout << "jobScheduling completed!" << endl;
}
