//
// Created by dexhacker on 1/11/23.
//

#include "Solution.h"
#include <cassert>

bool minimum_time_to_collect_all_apples_in_a_tree::Solution::dfs(int vertex, int step, vector<bool> &hasApple,
                                                                 vector<bool> &used) {
    bool isUsed = false;
    if (hasApple[vertex]) {
        answer += step;
        step = 0;
        isUsed = true;
    }
    for (int i : m[vertex]) {
        if (!used[i]) {
            used[i] = true;
            if (dfs(i, step + 1, hasApple, used)) {
                step = 0;
                isUsed = true;
            }
        }
    }
    return isUsed;
}

int minimum_time_to_collect_all_apples_in_a_tree::Solution::minTime(int n, vector<vector<int>> &edges,
                                                                    vector<bool> &hasApple) {
    vector<bool> used(n, false);
    for (auto i : edges) {
        m[i[0]].push_back(i[1]);
        m[i[1]].push_back(i[0]);
    }
    used[0] = true;
    dfs(0, 0, hasApple, used);
    return answer * 2;
}

void minimum_time_to_collect_all_apples_in_a_tree::Solution::test() {
    vector<vector<int>> edges {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3},{2, 6}};
    vector<bool> hasApple {false, false, true, false, true, true, false};
    assert(minTime(7, edges, hasApple) == 8);

    cout << "minTime completed!" << endl;
}
