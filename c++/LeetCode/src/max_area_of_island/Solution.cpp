//
// Created by dexhacker on 6/2/21.
//

#include "Solution.h"
#include <cassert>

int max_area_of_island::Solution::find_island(int i, int j) {
    g[i][j] = 0;
    int ans = 1;
    if (i - 1 >= 0 and g[i - 1][j] == 1) ans += find_island(i - 1, j);
    if (i + 1 < g.size() and g[i + 1][j] == 1) ans += find_island(i + 1, j);
    if (j - 1 >= 0 and g[i][j - 1] == 1) ans += find_island(i, j - 1);
    if (j + 1 < g[i].size() and g[i][j + 1] == 1) ans += find_island(i, j + 1);
    return ans;
}

int max_area_of_island::Solution::maxAreaOfIsland(vector<vector<int>> &grid) {
    g = grid;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (g[i][j] == 1) answer = max(answer, find_island(i, j));
        }
    }
    return answer;
}

void max_area_of_island::Solution::test() {
    vector<vector<int>> test{
            {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
            {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };
    assert(maxAreaOfIsland(test) == 6);

    cout << "maxAreaOfIsland completed!" << endl;
}
