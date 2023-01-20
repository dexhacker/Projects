//
// Created by dexhacker on 1/20/23.
//

#ifndef LEETCODE_NON_DECREASING_SUBSEQUENCES_H
#define LEETCODE_NON_DECREASING_SUBSEQUENCES_H

#include <iostream>
#include <vector>

using namespace std;

namespace non_decreasing_subsequences {
    class Solution {
    private:
        vector<vector<int>> answer;

    public:
        void dfs(vector<int>& nums, vector<int> v, int index);
        vector<vector<int>> findSubsequences(vector<int>& nums);
        void test();
    };
}

#endif //LEETCODE_NON_DECREASING_SUBSEQUENCES_H
