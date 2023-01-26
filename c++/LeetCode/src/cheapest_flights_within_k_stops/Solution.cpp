//
// Created by dexhacker on 1/26/23.
//

#include "Solution.h"
#include <unordered_map>
#include <queue>
#include <cassert>

int cheapest_flights_within_k_stops::Solution::findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
    int cost = -1;
    vector<unordered_map<int, int>> paths(n);
    vector<int> used(n, -1);
    queue<vector<int>> q;
    for (auto i : flights) paths[i[0]][i[1]] = i[2];
    used[src] = 0;
    q.push({src, k + 1, 0});
    while(!q.empty()) {
        auto i = q.front();
        q.pop();

        if (i[1] >= 0 && i[0] == dst) {
            if (cost == -1) {
                cost = i[2];
            } else {
                if (i[2] < cost) {
                    cost = i[2];
                }
            }
        }

        if (i[1] < 0) continue;

        for (auto p : paths[i[0]]) {
            if (used[p.first] == -1 || i[2] + p.second < used[p.first]) {
                used[p.first] = i[2] + p.second;
                q.push({p.first, i[1] - 1, i[2] + p.second});
            }
        }
    }

    return cost;
}

void cheapest_flights_within_k_stops::Solution::test() {
    vector<vector<int>> flights {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    assert(findCheapestPrice(4, flights, 0, 3, 1) == 700);

    cout << "findCheapestPrice completed!" << endl;
}
