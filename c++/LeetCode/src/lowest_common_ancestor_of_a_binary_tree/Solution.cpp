//
// Created by dexhacker on 6/30/21.
//

#include "Solution.h"
#include <cassert>

void lowest_common_ancestor_of_a_binary_tree::Solution::saveParents(TreeNode *root, TreeNode *parent) {
    if (root == nullptr) return;

    parents[root] = parent;

    saveParents(root->left, root);
    saveParents(root->right, root);
}

TreeNode * lowest_common_ancestor_of_a_binary_tree::Solution::lowestCommonAncestor(TreeNode *root, TreeNode *p,
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

void lowest_common_ancestor_of_a_binary_tree::Solution::test() {
    auto tn1 = new TreeNode(3);
    auto tn2 = new TreeNode(5);
    auto tn3 = new TreeNode(1);
    tn1->left = tn2;
    tn1->right = tn3;
    assert(lowestCommonAncestor(tn1, tn2, tn3) == tn1);

    cout << "lowestCommonAncestor completed!" << endl;
}
