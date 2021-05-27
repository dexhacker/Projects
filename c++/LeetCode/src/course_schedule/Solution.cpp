//
// Created by dexhacker on 5/27/21.
//

#include "Solution.h"
#include <cassert>

void course_schedule::Solution::dfs(int key, vector<int> & neighbors, unordered_map<int, bool> visited) {
    if (!answer) return;
    if (visited[key]) {
        answer = false;
        return;
    }
    if (used[key]) return;

    used[key] = true;
    visited[key] = true;

    for (int neighbor : neighbors) {
        if (adjastancy_map.count(neighbor) > 0) dfs(neighbor, adjastancy_map[neighbor], visited);
    }
}

bool course_schedule::Solution::canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    for (int i = 0; i < prerequisites.size(); i++) {
        vector<int> current_pair = prerequisites[i];
        adjastancy_map[current_pair[1]].push_back(current_pair[0]);
    }

    for (auto & [key, value] : adjastancy_map) {
        if (!answer) return false;
        unordered_map<int, bool> visited;
        if (!used[key]) dfs(key, value, visited);
    }

    return answer;
}

void course_schedule::Solution::test() {
    vector<vector<int>> test1 {{1, 0}};
    assert(canFinish(2, test1) == true);

    adjastancy_map = {}, used = {}, answer = true;
    vector<vector<int>> test2 {{1, 0}, {0, 1}};
    assert(canFinish(2, test2) == false);

    cout << "canFinish completed!" << endl;
}
