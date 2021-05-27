//
// Created by dexhacker on 5/22/21.
//

#include "Solution.h"
#include <cassert>
#include <queue>

bool same_tree::Solution::isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr and q == nullptr) return true;
    if (p == nullptr or q == nullptr) return false;

    queue<pair<TreeNode*, TreeNode*>> pair_queue;
    pair_queue.push({p, q});
    while (!pair_queue.empty()) {
        auto current_pair = pair_queue.front();
        pair_queue.pop();
        if (current_pair.first->val != current_pair.second->val) return false;
        if (current_pair.first->left != nullptr and current_pair.second->left != nullptr) {
            pair_queue.push({current_pair.first->left, current_pair.second->left});
        } else {
            if (current_pair.first->left != nullptr or current_pair.second->left != nullptr) {
                return false;
            }
        }
        if (current_pair.first->right != nullptr and current_pair.second->right != nullptr) {
            pair_queue.push({current_pair.first->right, current_pair.second->right});
        } else {
            if (current_pair.first->right != nullptr or current_pair.second->right != nullptr) {
                return false;
            }
        }
    }
    return true;
}

void same_tree::Solution::test() {
    auto test1_tree_node_1 = new TreeNode(1);
    auto test1_tree_node_2 = new TreeNode(2);
    auto test1_tree_node_3 = new TreeNode(3);
    test1_tree_node_1->left = test1_tree_node_2;
    test1_tree_node_1->right = test1_tree_node_3;

    auto test2_tree_node_1 = new TreeNode(1);
    auto test2_tree_node_2 = new TreeNode(2);
    auto test2_tree_node_3 = new TreeNode(3);
    test2_tree_node_1->left = test2_tree_node_2;
    test2_tree_node_1->right = test2_tree_node_3;

    assert(isSameTree(test1_tree_node_1, test2_tree_node_1) == true);


    auto test3_tree_node_1 = new TreeNode(1);
    auto test3_tree_node_2 = new TreeNode(2);
    test3_tree_node_1->left = test3_tree_node_2;

    auto test4_tree_node_1 = new TreeNode(1);
    auto test4_tree_node_2 = new TreeNode(2);
    test4_tree_node_1->right = test4_tree_node_2;

    assert(isSameTree(test3_tree_node_1, test4_tree_node_2) == false);


    auto test5_tree_node_1 = new TreeNode(1);
    auto test5_tree_node_2 = new TreeNode(2);
    auto test5_tree_node_3 = new TreeNode(1);
    test5_tree_node_1->left = test5_tree_node_2;
    test5_tree_node_1->right = test5_tree_node_3;

    auto test6_tree_node_1 = new TreeNode(1);
    auto test6_tree_node_2 = new TreeNode(1);
    auto test6_tree_node_3 = new TreeNode(2);
    test6_tree_node_1->left = test6_tree_node_2;
    test6_tree_node_1->right = test6_tree_node_3;

    assert(isSameTree(test5_tree_node_1, test6_tree_node_1) == false);

    assert(isSameTree(nullptr, nullptr) == true);

    cout << "isSameTree completed!" << endl;
}
