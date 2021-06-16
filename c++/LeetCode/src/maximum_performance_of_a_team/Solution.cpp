//
// Created by dexhacker on 6/5/21.
//

#include "Solution.h"
#include <queue>
#include <cassert>

int maximum_performance_of_a_team::Solution::maxPerformance(int n, vector<int> &speed, vector<int> &efficiency,
                                                            int k) {
    vector<pair<int, int>> ess;
    for (int i = 0; i < n; ++i) ess.emplace_back(efficiency[i], speed[i]);
    sort(rbegin(ess), rend(ess));
    long sumS = 0, res = 0;
    priority_queue <int, vector<int>, greater<int>> pq; //min heap
    for(auto& [e, s]: ess){
        pq.emplace(s);
        sumS += s;
        if (pq.size() > k) {
            sumS -= pq.top();
            pq.pop();
        }
        res = max(res, sumS * e);
    }
    return res % (int)(1e9+7);
}

void maximum_performance_of_a_team::Solution::test() {
    vector<int> test_s {2, 10, 3, 1, 5, 8};
    vector<int> test_e {5, 4, 3, 9, 7, 2};
    assert(maxPerformance(6, test_s, test_e, 2) == 60);

    cout << "maxPerformance completed!" << endl;
}
