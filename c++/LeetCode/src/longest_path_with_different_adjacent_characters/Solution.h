//
// Created by dexhacker on 1/13/23.
//

#ifndef LEETCODE_LONGEST_PATH_WITH_DIFFERENT_ADJACENT_CHARACTERS_H
#define LEETCODE_LONGEST_PATH_WITH_DIFFERENT_ADJACENT_CHARACTERS_H

#include <iostream>
#include <vector>

using namespace std;

namespace longest_path_with_different_adjacent_characters {
    class Solution {
    private:
        vector<int> child[100001];
        int ans = 1;

    public:
        int dfs(string &s, int curr_node);
        int longestPath(vector<int>& parent, string s);
        void test();
    };
}

#endif //LEETCODE_LONGEST_PATH_WITH_DIFFERENT_ADJACENT_CHARACTERS_H
