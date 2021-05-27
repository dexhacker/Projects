//
// Created by dexhacker on 5/22/21.
//

#include "Solution.h"
#include <queue>
#include <cassert>

int maximum_depth_of_binary_tree::Solution::maxDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    int max = 1;
    queue<pair<TreeNode*, int>> pair_queue;
    pair_queue.push({root, 1});
    while (!pair_queue.empty()) {
        auto current_pair = pair_queue.front();
        pair_queue.pop();

        if (current_pair.first != nullptr) {
            if (max < current_pair.second) max = current_pair.second;
            pair_queue.push({current_pair.first->left, current_pair.second + 1});
            pair_queue.push({current_pair.first->right, current_pair.second + 1});
        }
    }
    return max;
}

void maximum_depth_of_binary_tree::Solution::test() {
    auto t1_tn1 = new TreeNode(3);
    auto t1_tn2 = new TreeNode(9);
    auto t1_tn3 = new TreeNode(20);
    auto t1_tn4 = new TreeNode(15);
    auto t1_tn5 = new TreeNode(7);
    t1_tn1->left = t1_tn2;
    t1_tn1->right = t1_tn3;
    t1_tn3->left = t1_tn4;
    t1_tn3->right = t1_tn5;
    assert(maxDepth(t1_tn1) == 3);

    auto t2_tn1 = new TreeNode(1);
    auto t2_tn2 = new TreeNode(2);
    t2_tn1->right = t2_tn2;
    assert(maxDepth(t2_tn1) == 2);

    assert(maxDepth(nullptr) == 0);

    auto t3_tn1 = new TreeNode(0);
    assert(maxDepth(t3_tn1) == 1);

    cout << "maxDepth completed!" << endl;
}
