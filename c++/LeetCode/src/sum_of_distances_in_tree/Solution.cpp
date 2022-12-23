//
// Created by dexhacker on 12/23/22.
//

#include "Solution.h"
#include <cassert>

vector<int> sum_of_distances_in_tree::Solution::sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
    tree.resize(N);
    res.assign(N, 0);
    count.assign(N, 1);
    for (auto e : edges) {
        tree[e[0]].insert(e[1]);
        tree[e[1]].insert(e[0]);
    }
    dfs(0, -1);
    dfs2(0, -1);
    return res;
}

void sum_of_distances_in_tree::Solution::dfs(int root, int pre) {
    for (auto i : tree[root]) {
        if (i == pre) continue;
        dfs(i, root);
        count[root] += count[i];
        res[root] += res[i] + count[i];
    }
}

void sum_of_distances_in_tree::Solution::dfs2(int root, int pre) {
    for (auto i : tree[root]) {
        if (i == pre) continue;
        res[i] = res[root] - count[i] + count.size() - count[i];
        dfs2(i, root);
    }
}

void sum_of_distances_in_tree::Solution::test() {
    vector<vector<int>> edges {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    vector<int> answer {8, 12, 6, 10, 10, 10};
    auto result = sumOfDistancesInTree(6, edges);
    for (int i = 0; i < answer.size(); i++) assert(answer[i] == result[i]);

    cout << "sumOfDistancesInTree completed!" << endl;
}
