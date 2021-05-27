//
// Created by dexhacker on 5/27/21.
//

#ifndef LEETCODE_BINARY_SEARCH_TREE_ITERATOR_H
#define LEETCODE_BINARY_SEARCH_TREE_ITERATOR_H

#include "../TreeNode.h"
#include <iostream>
#include <vector>

using namespace std;

namespace binary_search_tree_iterator {
    class BSTIterator {
    public:
        static void test();
        void dfs(TreeNode *root);
        BSTIterator(TreeNode* root);
        int next();
        bool hasNext();

    private:
        vector<int> numbers;
        int counter;
    };
}

#endif //LEETCODE_BINARY_SEARCH_TREE_ITERATOR_H
