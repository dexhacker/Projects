//
// Created by dexhacker on 12/30/22.
//

#include "Solution.h"
#include <queue>
#include <cassert>

vector<vector<int>> all_paths_from_source_to_target::Solution::allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> answer;
    queue<vector<int>> q;
    q.push({0});
    while (!q.empty()) {
        auto path = q.front();
        q.pop();
        for (int i : graph[path.back()]) {
            path.push_back(i);
            if (i == graph.size() - 1) {
                answer.push_back(path);
            } else {
                q.push(path);
            }
            path.pop_back();
        }
    }
    return answer;
}

void all_paths_from_source_to_target::Solution::test() {
    vector<vector<int>> graph {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> answer {{0, 1, 3}, {0, 2, 3}};
    auto result = allPathsSourceTarget(graph);
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            assert(answer[i][j] == result[i][j]);
        }
    }

    cout << "allPathsSourceTarget completed!" << endl;
}
