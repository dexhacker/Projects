//
// Created by dexhacker on 5/22/21.
//

#include "Solution.h"
#include <queue>
#include <cassert>

bool path_sum::Solution::hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) return false;

    queue<pair<TreeNode*, int>> pair_queue;
    pair_queue.push({root, root->val});

    while (!pair_queue.empty()) {
        auto current_pair = pair_queue.front();
        pair_queue.pop();

        if (current_pair.first != nullptr) {
            if (current_pair.first->left == nullptr and current_pair.first->right == nullptr and current_pair.second == targetSum) return true;
            if (current_pair.first->left != nullptr) pair_queue.push({current_pair.first->left, current_pair.second + current_pair.first->left->val});
            if (current_pair.first->right != nullptr) pair_queue.push({current_pair.first->right, current_pair.second + current_pair.first->right->val});
        }
    }
    return false;
}

void path_sum::Solution::test() {
    auto t1_tn1 = new TreeNode(5);
    auto t1_tn2 = new TreeNode(4);
    auto t1_tn3 = new TreeNode(11);
    auto t1_tn4 = new TreeNode(7);
    auto t1_tn5 = new TreeNode(2);
    auto t1_tn6 = new TreeNode(8);
    auto t1_tn7 = new TreeNode(13);
    auto t1_tn8 = new TreeNode(4);
    auto t1_tn9 = new TreeNode(1);
    t1_tn1->left = t1_tn2;
    t1_tn2->left = t1_tn3;
    t1_tn3->left = t1_tn4;
    t1_tn3->right = t1_tn5;
    t1_tn1->right = t1_tn6;
    t1_tn6->left = t1_tn7;
    t1_tn6->right = t1_tn8;
    t1_tn8->right = t1_tn8;
    assert(hasPathSum(t1_tn1, 22) == true);

    auto t2_tn1 = new TreeNode(1);
    auto t2_tn2 = new TreeNode(2);
    auto t2_tn3 = new TreeNode(3);
    t2_tn1->left = t2_tn2;
    t2_tn1->right = t2_tn3;
    assert(hasPathSum(t2_tn1, 5) == false);

    auto t3_tn1 = new TreeNode(1);
    auto t3_tn2 = new TreeNode(2);
    t3_tn1->left = t3_tn2;
    assert(hasPathSum(t3_tn1, 0) == false);
    assert(hasPathSum(t3_tn1, 1) == false);

    assert(hasPathSum(nullptr, 0) == false);
    assert(hasPathSum(nullptr, 1) == false);

    cout << "hasPathSum completed!" << endl;
}
