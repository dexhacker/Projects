//
// Created by dexhacker on 5/27/21.
//

#include "Solution.h"
#include <queue>
#include <cassert>

int network_delay_time::Solution::networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<pair<int, int>>> list(n + 1);
    vector<int> used(n + 1, -1);
    for (auto & time : times) {
        int source = time[0], target = time[1], weight = time[2];
        list[source].push_back({target, weight});
    }
    queue<pair<int, int>> q;
    q.push({k, 0});
    while (!q.empty()) {
        auto current_pair = q.front();
        bool updated = false;
        q.pop();


        if (used[current_pair.first] == -1) {
            used[current_pair.first] = current_pair.second;
            updated = true;
        } else {
            if (used[current_pair.first] > current_pair.second) {
                used[current_pair.first] = current_pair.second;
                updated = true;
            }
        }

        if (updated) {
            for (auto p : list[current_pair.first]) {
                q.push({p.first, used[current_pair.first] + p.second});
            }
        }
    }

    int max_time = 0;
    for (int i = 1; i < used.size(); i++) {
        if (used[i] == -1) return -1;
        max_time = max(max_time, used[i]);
    }

    return max_time;
}

void network_delay_time::Solution::test() {
    vector<vector<int>> test1 {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    assert(networkDelayTime(test1, 4, 2) == 2);

    vector<vector<int>> test2 {{1, 2, 1}};
    assert(networkDelayTime(test2, 2, 1) == 1);

    vector<vector<int>> test3 {{1, 2, 1}};
    assert(networkDelayTime(test2, 2, 2) == -1);

    cout << "networkDelayTime completed!" << endl;
}
