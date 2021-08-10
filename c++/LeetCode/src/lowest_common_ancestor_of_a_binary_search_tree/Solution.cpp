//
// Created by dexhacker on 7/19/21.
//

#include "Solution.h"
#include <cassert>

void lowest_common_ancestor_of_a_binary_search_tree::Solution::saveParents(TreeNode *root, TreeNode *parent) {
    if (root == nullptr) return;

    parents[root] = parent;

    saveParents(root->left, root);
    saveParents(root->right, root);
}

TreeNode * lowest_common_ancestor_of_a_binary_search_tree::Solution::lowestCommonAncestor(TreeNode *root, TreeNode *p,
                                                                                          TreeNode *q) {
    saveParents(root, nullptr);

    unordered_map<TreeNode*, bool> p_parents;
    TreeNode* current_node = p;
    while (current_node) {
        p_parents[current_node] = true;

        if (parents.count(current_node) > 0) {
            current_node = parents[current_node];
        } else {
            break;
        }
    }

    current_node = q;
    while (current_node) {
        if (p_parents[current_node]) return current_node;

        if (parents.count(current_node) > 0) {
            current_node = parents[current_node];
        } else {
            break;
        }
    }

    return nullptr;
}

void lowest_common_ancestor_of_a_binary_search_tree::Solution::test() {
    auto tree_node1 = new TreeNode(6);
    auto tree_node2 = new TreeNode(2);
    auto tree_node3 = new TreeNode(8);
    auto tree_node4 = new TreeNode(0);
    auto tree_node5 = new TreeNode(4);
    auto tree_node6 = new TreeNode(7);
    auto tree_node7 = new TreeNode(9);
    auto tree_node8 = new TreeNode(3);
    auto tree_node9 = new TreeNode(5);
    tree_node1->left = tree_node2;
    tree_node1->right = tree_node3;
    tree_node2->left = tree_node4;
    tree_node2->right = tree_node5;
    tree_node3->left = tree_node6;
    tree_node3->right = tree_node7;
    tree_node5->left = tree_node8;
    tree_node5->right = tree_node9;
    assert(lowestCommonAncestor(tree_node1, tree_node2, tree_node3) == tree_node1);

    cout << "lowestCommonAncestor completed!" << endl;
}
