//
// Created by dexhacker on 5/22/21.
//

#include "Solution.h"
#include <queue>
#include <cassert>

bool symmetric_tree::Solution::isSymmetric(TreeNode *root) {
    if (root->left == nullptr and root->right == nullptr) return true;
    if (root->left == nullptr or root->right == nullptr) return false;

    queue<pair<TreeNode*, TreeNode*>> pair_queue;
    pair_queue.push({root->left, root->right});

    while (!pair_queue.empty()) {
        auto current_pair = pair_queue.front();
        pair_queue.pop();
        if (current_pair.first != nullptr and current_pair.second != nullptr) {
            if (current_pair.first->val == current_pair.second->val) {
                pair_queue.push({current_pair.first->right, current_pair.second->left});
                pair_queue.push({current_pair.first->left, current_pair.second->right});
            } else {
                return false;
            }
        } else {
            if (current_pair.first != nullptr or current_pair.second != nullptr) return false;
        }
    }
    return true;
}

void symmetric_tree::Solution::test() {
    auto test1_tn1 = new TreeNode(1);
    auto test1_tn2 = new TreeNode(2);
    auto test1_tn3 = new TreeNode(2);
    auto test1_tn4 = new TreeNode(3);
    auto test1_tn5 = new TreeNode(4);
    auto test1_tn6 = new TreeNode(4);
    auto test1_tn7 = new TreeNode(3);
    test1_tn1->left = test1_tn2;
    test1_tn1->right = test1_tn3;
    test1_tn2->left = test1_tn4;
    test1_tn2->right = test1_tn5;
    test1_tn3->left = test1_tn6;
    test1_tn3->right = test1_tn7;
    assert(isSymmetric(test1_tn1) == true);

    auto test2_tn1 = new TreeNode(1);
    auto test2_tn2 = new TreeNode(2);
    auto test2_tn3 = new TreeNode(2);
    auto test2_tn4 = new TreeNode(3);
    auto test2_tn5 = new TreeNode(3);
    test2_tn1->left = test2_tn2;
    test2_tn1->right = test2_tn3;
    test2_tn2->right = test2_tn4;
    test2_tn3->right = test2_tn5;
    assert(isSymmetric(test2_tn1) == false);

    auto test3_tn1 = new TreeNode(1);
    assert(isSymmetric(test3_tn1) == true);

    cout << "isSymmetric completed!" << endl;
}
