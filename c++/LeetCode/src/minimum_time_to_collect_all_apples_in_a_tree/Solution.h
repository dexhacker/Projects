//
// Created by dexhacker on 1/11/23.
//

#ifndef LEETCODE_MINIMUM_TIME_TO_COLLECT_ALL_APPLES_IN_A_TREE_H
#define LEETCODE_MINIMUM_TIME_TO_COLLECT_ALL_APPLES_IN_A_TREE_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace minimum_time_to_collect_all_apples_in_a_tree {
    class Solution {
    private:
        unordered_map<int, vector<int>> m;
        int answer = 0;

    public:
        bool dfs(int vertex, int step, vector<bool>& hasApple, vector<bool>& used);
        int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple);
        void test();
    };
}

#endif //LEETCODE_MINIMUM_TIME_TO_COLLECT_ALL_APPLES_IN_A_TREE_H
