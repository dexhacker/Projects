//
// Created by dexhacker on 12/30/22.
//

#ifndef LEETCODE_ALL_PATHS_FROM_SOURCE_TO_TARGET_H
#define LEETCODE_ALL_PATHS_FROM_SOURCE_TO_TARGET_H

#include <iostream>
#include <vector>

using namespace std;

namespace all_paths_from_source_to_target {
    class Solution {
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph);
        void test();
    };
}

#endif //LEETCODE_ALL_PATHS_FROM_SOURCE_TO_TARGET_H
