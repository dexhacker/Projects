//
// Created by dexhacker on 9/24/22.
//

#ifndef LEETCODE_PATH_SUM_II_H
#define LEETCODE_PATH_SUM_II_H

#include <iostream>
#include <vector>
#include "../TreeNode.h"

using namespace std;

namespace path_sum_ii {
    class Solution {
    public:
        void dfs(TreeNode* root, int targetSum, vector<int> sub_answer);
        vector<vector<int>> pathSum(TreeNode* root, int targetSum);
        void test();

    private:
        vector<vector<int>> answer;
    };
}

#endif //LEETCODE_PATH_SUM_II_H
