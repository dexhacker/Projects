//
// Created by dexhacker on 2/11/23.
//

#include "Solution.h"
#include <unordered_map>
#include <queue>
#include <cassert>

vector<int> shortest_path_with_alternating_colors::Solution::shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
    vector<int> answer(n, -1);
    vector<int> used(n, 0);
    unordered_map<int, vector<int>> red_m, blue_m;
    queue<vector<int>> q;

    for (auto i : redEdges) red_m[i[0]].push_back(i[1]);
    for (auto i : blueEdges) blue_m[i[0]].push_back(i[1]);

    q.push({0, 0, 0});
    used[0] = 3;
    while (!q.empty()) {
        auto i = q.front();
        q.pop();

        if (answer[i[0]] == -1) answer[i[0]] = i[1];

        if (i[2] == 0 || i[2] == 2) {
            for (auto j : red_m[i[0]]) {
                if (used[j] == 0 || used[j] == 2) {
                    used[j] += 1;
                    q.push({j, i[1] + 1, 1});
                }
            }
        }

        if (i[2] == 0 || i[2] == 1) {
            for (auto j : blue_m[i[0]]) {
                if (used[j] == 0 || used[j] == 1) {
                    used[j] += 2;
                    q.push({j, i[1] + 1, 2});
                }
            }
        }
    }

    return answer;
}

void shortest_path_with_alternating_colors::Solution::test() {
    vector<vector<int>> redEdges {{0, 1}, {1, 2}};
    vector<vector<int>> blueEdges;
    vector<int> answer {0, 1, -1};
    auto result = shortestAlternatingPaths(3, redEdges, blueEdges);
    for (int i = 0; i < answer.size(); i++) assert(answer[i] == result[i]);

    cout << "shortestAlternatingPaths completed!" << endl;
}
