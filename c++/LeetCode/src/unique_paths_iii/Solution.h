//
// Created by dexhacker on 12/31/22.
//

#ifndef LEETCODE_UNIQUE_PATHS_III_H
#define LEETCODE_UNIQUE_PATHS_III_H

#include <iostream>
#include <vector>

using namespace std;

namespace unique_paths_iii {
    class Solution {
    private:
        int answer = 0;

    public:
        void dfs(vector<vector<int>>& grid, vector<vector<bool>>& used, int i, int j);
        int uniquePathsIII(vector<vector<int>>& grid);
        void test();
    };
}

#endif //LEETCODE_UNIQUE_PATHS_III_H
