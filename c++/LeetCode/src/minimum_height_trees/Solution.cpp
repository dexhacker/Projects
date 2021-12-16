//
// Created by Фарид Абдугалыев on 16.12.2021.
//

#include "Solution.h"
#include <cassert>

vector<int> minimum_height_trees::Solution::findMinHeightTrees(int n, vector<vector<int>> &edges) {
    if (edges.empty()) return {0};

    vector<vector<int>> graph_map(n);
    vector<int> result(n);
    for (auto & edge : edges) {
        graph_map[edge[0]].push_back(edge[1]);
        graph_map[edge[1]].push_back(edge[0]);
    }

    vector<bool> used(n);
    vector<int> wave;
    vector<int> prev_wave;
    vector<int> node_count(n);
    for (int i = 0; i < graph_map.size(); i++) {
        if (graph_map[i].size() == 1) {
            wave.push_back(i);
            node_count[i] = 0;
            used[i] = true;
        } else {
            node_count[i] = graph_map[i].size();
        }
    }

    while(!wave.empty()) {
        prev_wave = wave;
        vector<int> new_wave;
        for (auto i : wave) {
            for (auto e : graph_map[i]) {
                node_count[e]--;
                if (!used[e] && node_count[e] == 1) {
                    node_count[e]--;
                    used[e] = true;
                    new_wave.push_back(e);
                }
            }
        }
        wave = new_wave;
    }

    return prev_wave;
}

void minimum_height_trees::Solution::test() {
    vector<vector<int>> test1 {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    vector<int> answer {3, 4};
    assert(findMinHeightTrees(6, test1) == answer);

    cout << "findMinHeightTrees completed!" << endl;
}
