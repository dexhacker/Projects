//
// Created by dexhacker on 7/24/21.
//

#include "Solution.h"
#include <cassert>

bool binary_tree_pruning::Solution::dfs(TreeNode *root) {
    if (root == nullptr) return false;
    if (root->left == nullptr and root->right == nullptr) {
        if (root->val == 1) return true;
        return false;
    }

    bool right = dfs(root->right);
    bool left = dfs(root->left);

    if (right or left) {
        if (!right) root->right = nullptr;
        if (!left) root->left = nullptr;
        return true;
    } else {
        if (root->val == 1) {
            root->left = nullptr;
            root->right = nullptr;
            return true;
        } else {
            return false;
        }
    }
}

TreeNode * binary_tree_pruning::Solution::pruneTree(TreeNode *root) {
    if (dfs(root)) return root;

    return nullptr;
}

void binary_tree_pruning::Solution::test() {
    auto t1 = new TreeNode(1);
    auto t2 = new TreeNode(0);
    auto t3 = new TreeNode(0);
    auto t4 = new TreeNode(1);
    t1->right = t2;
    t2->left = t3;
    t2->right = t4;
    pruneTree(t1);
    assert(t1->right->right->val == 1);
    assert(t1->right->left == nullptr);

    cout << "pruneTree completed!" << endl;
}
