//
// Created by dexhacker on 5/24/21.
//

#include "Solution.h"
#include <cassert>

void redundant_connection::Solution::dfs(int v, vector<vector<int>> &adjacency_list, vector<bool> &visited) {
    visited[v] = true;
    for (auto & neighbor : adjacency_list[v]) if (!visited[neighbor]) dfs(neighbor, adjacency_list, visited);
}

vector<int> redundant_connection::Solution::findRedundantConnection(vector<vector<int>> &edges) {
    vector<int> last_redundant {-1, -1};
    for (int deleted_edge = 0; deleted_edge < edges.size(); deleted_edge++) {
        vector<vector<int>> adjacency_list(edges.size() + 1);
        for (int i = 0; i < edges.size(); i++) {
            if (i == deleted_edge) continue;

            int a = edges[i][0];
            int b = edges[i][1];
            adjacency_list[a].push_back(b);
            adjacency_list[b].push_back(a);
        }

        vector<bool> visited(edges.size() + 1, false);

        dfs(1, adjacency_list, visited);

        bool is_all_visited = true;
        for (int i = 1; i < edges.size() + 1; i++) if (!visited[i]) is_all_visited = false;
        if (is_all_visited) last_redundant = edges[deleted_edge];
    }
    return last_redundant;
}

void redundant_connection::Solution::test() {
    vector<vector<int>> test1 {{1, 2}, {1, 3}, {2, 3}};
    vector<int> answer1 {2, 3};
    assert(findRedundantConnection(test1) == answer1);

    vector<vector<int>> test2 {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
    vector<int> answer2 {1, 4};
    assert(findRedundantConnection(test2) == answer2);

    cout << "findRedundantConnection completed!" << endl;
}
