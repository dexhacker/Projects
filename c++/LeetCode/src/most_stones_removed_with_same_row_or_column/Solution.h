//
// Created by dexhacker on 11/14/22.
//

#ifndef LEETCODE_MOST_STONES_REMOVED_WITH_SAME_ROW_OR_COLUMN_H
#define LEETCODE_MOST_STONES_REMOVED_WITH_SAME_ROW_OR_COLUMN_H

#include <iostream>
#include <vector>

using namespace std;

namespace most_stones_removed_with_same_row_or_column {
    class Solution {
    public:
        int removeStones(vector<vector<int>>& stones);
        void dfs(vector<vector<int>>& stones, int index, vector<bool>& visited);
        void test();

    private:
        int n;
    };
}

#endif //LEETCODE_MOST_STONES_REMOVED_WITH_SAME_ROW_OR_COLUMN_H
