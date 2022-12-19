//
// Created by dexhacker on 12/19/22.
//

#include "Solution.h"
#include <unordered_map>
#include <queue>
#include <cassert>

bool find_if_path_exists_in_graph::Solution::validPath(int n, vector<vector<int>> &edges, int source, int destination) {
    if (source == destination) return true;
    unordered_map<int, vector<int>> um;
    for (auto i : edges) {
        um[i[0]].push_back(i[1]);
        um[i[1]].push_back(i[0]);
    }
    unordered_map<int, bool> used;
    queue<int> q;
    q.push(source);
    used[source] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i : um[current]) {
            if (used[i] == true) continue;
            if (i == destination) return true;
            used[i] = true;
            q.push(i);
        }
    }
    return false;
}

void find_if_path_exists_in_graph::Solution::test() {
    vector<vector<int>> edges {{0, 1}, {1, 2}, {2, 0}};
    assert(validPath(3, edges, 0, 2) == true);

    cout << "validPath completed!" << endl;
}
