//
// Created by Фарид Абдугалыев on 16.12.2021.
//

#ifndef LEETCODE_MINIMUM_HEIGHT_TREES_H
#define LEETCODE_MINIMUM_HEIGHT_TREES_H

#include <iostream>
#include <vector>

using namespace std;

namespace minimum_height_trees {
    class Solution {
    public:
        vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges);
        void test();
    };
}

#endif //LEETCODE_MINIMUM_HEIGHT_TREES_H
