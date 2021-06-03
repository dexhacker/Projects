//
// Created by dexhacker on 6/2/21.
//

#ifndef LEETCODE_MAX_AREA_OF_ISLAND_H
#define LEETCODE_MAX_AREA_OF_ISLAND_H

#include <iostream>
#include <vector>

using namespace std;

namespace max_area_of_island {
    class Solution {
    public:
        int find_island(int i, int j);
        int maxAreaOfIsland(vector<vector<int>>& grid);
        void test();

    private:
        vector<vector<int>> g;
        int answer = 0;
    };
}

#endif //LEETCODE_MAX_AREA_OF_ISLAND_H
