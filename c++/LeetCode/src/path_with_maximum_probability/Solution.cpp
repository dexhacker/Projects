//
// Created by dexhacker on 5/27/21.
//

#include "Solution.h"
#include <queue>
#include <cassert>

double path_with_maximum_probability::Solution::maxProbability(int n, vector<vector<int>> &edges,
                                                               vector<double> &succProb, int start, int end) {
    vector<vector<pair<int, double>>> list(n);
    vector<double> used(n, 0);
    double max_prob = 0;
    for (int i = 0; i < edges.size(); i++) {
        list[edges[i][0]].push_back({edges[i][1], succProb[i]});
        list[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    queue<pair<int, double>> q;
    q.push({start, 1});
    while (!q.empty()) {
        auto curr_pair = q.front();
        q.pop();

        if (curr_pair.first == end) {
            max_prob = max(max_prob, curr_pair.second);
            continue;
        }

        if (used[curr_pair.first] >= curr_pair.second) continue;
        used[curr_pair.first] = curr_pair.second;
        for (auto p : list[curr_pair.first]) {
            q.push({p.first, curr_pair.second * p.second});
        }
    }

    return max_prob;
}

void path_with_maximum_probability::Solution::test() {
    vector<vector<int>> test_edges1 {{0, 1}, {1, 2}, {0, 2}};
    vector<double> test_prob1 {0.5, 0.5, 0.2};
    assert(maxProbability(3, test_edges1, test_prob1, 0, 2) == 0.25000);

    cout << "maxProbability completed!" << endl;
}
