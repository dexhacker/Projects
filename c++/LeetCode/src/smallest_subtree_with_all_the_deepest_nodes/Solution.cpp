//
// Created by dexhacker on 5/27/21.
//

#include "Solution.h"
#include <cassert>

void smallest_subtree_with_all_the_deepest_nodes::Solution::dfs(TreeNode *root, int deep, TreeNode *parent) {
    if (parent != nullptr) hash_map[root] = parent;

    if (root->left == nullptr and root->right == nullptr) {
        if (max_deep < deep) {
            max_deep = deep;
            deeps = {root};
        }
        if (max_deep == deep) deeps.push_back(root);
        return;
    }
    if (root->left != nullptr) dfs(root->left, deep + 1, root);
    if (root->right != nullptr) dfs(root->right, deep + 1, root);
}

TreeNode * smallest_subtree_with_all_the_deepest_nodes::Solution::subtreeWithAllDeepest(TreeNode *root) {
    dfs(root, 1, nullptr);
    bool isContinue = true;
    while (deeps.size() > 1) {
        if (deeps[deeps.size() - 2] == deeps[deeps.size() - 1]) {
            deeps.pop_back();
            continue;
        }
        for (int i = 0; i < deeps.size(); i++) {
            deeps[i] = hash_map[deeps[i]];
        }
    }
    return deeps[0];
}

void smallest_subtree_with_all_the_deepest_nodes::Solution::test() {
    auto tree_node0 = new TreeNode(0);
    auto tree_node1 = new TreeNode(1);
    auto tree_node2 = new TreeNode(2);
    auto tree_node3 = new TreeNode(3);
    auto tree_node4 = new TreeNode(4);
    auto tree_node5 = new TreeNode(5);
    auto tree_node6 = new TreeNode(6);
    auto tree_node7 = new TreeNode(7);
    auto tree_node8 = new TreeNode(8);
    tree_node3->left = tree_node5;
    tree_node3->right = tree_node1;
    tree_node5->left = tree_node6;
    tree_node5->right = tree_node2;
    tree_node2->left = tree_node7;
    tree_node2->right = tree_node4;
    tree_node1->left = tree_node0;
    tree_node1->right = tree_node8;
    assert(subtreeWithAllDeepest(tree_node3)->val == 2);

    cout << "subtreeWithAllDeepest completed!" << endl;
}
