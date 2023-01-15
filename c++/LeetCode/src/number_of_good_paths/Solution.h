//
// Created by dexhacker on 1/15/23.
//

#ifndef LEETCODE_NUMBER_OF_GOOD_PATHS_H
#define LEETCODE_NUMBER_OF_GOOD_PATHS_H

#include <iostream>
#include <vector>

using namespace std;

namespace number_of_good_paths {
    class Solution {
    public:
        int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges);
        int find(vector<int>& y, int i);
        void test();
    };
}

#endif //LEETCODE_NUMBER_OF_GOOD_PATHS_H
