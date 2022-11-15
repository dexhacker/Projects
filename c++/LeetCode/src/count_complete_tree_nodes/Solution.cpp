//
// Created by dexhacker on 11/15/22.
//

#include "Solution.h"
#include <queue>
#include <cassert>

int count_complete_tree_nodes::Solution::countNodes(TreeNode *root) {
    if (root == nullptr) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int answer = 0;
    while (!q.empty()) {
        answer++;
        if (q.front()->left != nullptr) q.push(q.front()->left);
        if (q.front()->right != nullptr) q.push(q.front()->right);
        q.pop();
    }

    return answer;
}

void count_complete_tree_nodes::Solution::test() {
    auto node1 = new TreeNode(1);
    auto node2 = new TreeNode(2);
    auto node3 = new TreeNode(3);
    auto node4 = new TreeNode(4);
    auto node5 = new TreeNode(5);
    auto node6 = new TreeNode(6);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    assert(countNodes(node1) == 6);

    cout << "countNodes completed!" << endl;
}
