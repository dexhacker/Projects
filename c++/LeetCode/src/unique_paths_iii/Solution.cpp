//
// Created by dexhacker on 12/31/22.
//

#include "Solution.h"
#include <cassert>

void unique_paths_iii::Solution::dfs(vector<vector<int>> &grid, vector<vector<bool>> &used, int i, int j) {
    if (grid[i][j] == 2) {
        bool all_used = true;
        for (auto k : used) for (auto b : k) if (!b) all_used = false;
        if (all_used) answer++;
        return;
    }

    if (i - 1 >= 0 && !used[i - 1][j]) {
        used[i - 1][j] = true;
        dfs(grid, used, i - 1, j);
        used[i - 1][j] = false;
    }
    if (i + 1 < grid.size() && !used[i + 1][j]) {
        used[i + 1][j] = true;
        dfs(grid, used, i + 1, j);
        used[i + 1][j] = false;
    }
    if (j - 1 >= 0 && !used[i][j - 1]) {
        used[i][j - 1] = true;
        dfs(grid, used, i, j - 1);
        used[i][j - 1] = false;
    }
    if (j + 1 < grid[i].size() && !used[i][j + 1]) {
        used[i][j + 1] = true;
        dfs(grid, used, i, j + 1);
        used[i][j + 1] = false;
    }
}

int unique_paths_iii::Solution::uniquePathsIII(vector<vector<int>> &grid) {
    vector<vector<bool>> used(grid.size(), vector<bool>(grid[0].size(), false));
    int start_i = 0, start_j = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) {
                start_i = i;
                start_j = j;
            }
            if (grid[i][j] == -1) used[i][j] = true;
        }
    }
    used[start_i][start_j] = true;
    dfs(grid, used, start_i, start_j);
    return answer;
}

void unique_paths_iii::Solution::test() {
    vector<vector<int>> grid {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    assert(uniquePathsIII(grid) == 2);

    cout << "uniquePathsIII completed!" << endl;
}
