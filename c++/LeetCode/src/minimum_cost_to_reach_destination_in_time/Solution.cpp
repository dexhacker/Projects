//
// Created by dexhacker on 7/12/21.
//

#include "Solution.h"
#include <unordered_map>
#include <queue>
#include <cassert>

int minimum_cost_to_reach_destination_in_time::Solution::minCost(int maxTime, vector<vector<int>> &edges,
                                                                 vector<int> &passingFees) {
    int N = passingFees.size();
    vector<unordered_map<int, int>> G(N);
    vector<int> minTime(N, maxTime + 1);
    for (auto &e : edges) {
        int u = e[0], v = e[1], t = e[2];
        if (G[u].count(v)) {
            G[u][v] = G[v][u] = min(G[u][v], t);
        } else {
            G[u][v] = G[v][u] = t;
        }
    }
    auto cmp = [](auto &a, auto &b) { return a[2] > b[2]; };
    priority_queue<Node, vector<Node>, decltype(cmp) > pq(cmp);
    pq.push({0, 0, passingFees[0]});
    minTime[0] = 0;
    while (pq.size()) {
        auto [u, time, c] = pq.top();
        pq.pop();
        if (u == N - 1) return c;
        for (auto &[v, t] : G[u]) {
            int nt = time + t, nc = c + passingFees[v];
            if (nt < minTime[v]) {
                minTime[v] = nt;
                pq.push({v, nt, nc});
            }
        }
    }
    return -1;
}

void minimum_cost_to_reach_destination_in_time::Solution::test() {
    vector<vector<int>> edges {{0, 1, 10}, {1, 2, 10}, {2, 5, 10}, {0, 3, 1}, {3, 4, 10}, {4, 5, 15}};
    vector<int> passingFees {5,1,2,20,20,3};
    assert(minCost(30, edges, passingFees) == 11);

    cout << "minCost completed!" << endl;
}
