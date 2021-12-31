//
// Created by Фарид Абдугалыев on 31.12.2021.
//

#ifndef LEETCODE_MAXIMUM_DIFFERENCE_BETWEEN_NODE_AND_ANCESTOR_H
#define LEETCODE_MAXIMUM_DIFFERENCE_BETWEEN_NODE_AND_ANCESTOR_H

#include <iostream>
#include "../TreeNode.h"

using namespace std;

namespace maximum_difference_between_node_and_ancestor {
    class Solution {
    public:
        void dfs(TreeNode* root, pair<int, int> p);
        int maxAncestorDiff(TreeNode* root);
        void test();

    private:
        int answer = 0;
    };
}

#endif //LEETCODE_MAXIMUM_DIFFERENCE_BETWEEN_NODE_AND_ANCESTOR_H
