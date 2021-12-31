//
// Created by Фарид Абдугалыев on 31.12.2021.
//

#include "Solution.h"
#include <cassert>

void maximum_difference_between_node_and_ancestor::Solution::dfs(TreeNode* root, pair<int, int> p) {
    if (root->left) {
        int max = p.first;
        int min = p.second;

        if (root->left->val > max) max = root->left->val;
        if (root->left->val < min) min = root->left->val;

        dfs(root->left, {max, min});
    }

    if (root->right) {
        int max = p.first;
        int min = p.second;

        if (root->right->val > max) max = root->right->val;
        if (root->right->val < min) min = root->right->val;

        dfs(root->right, {max, min});
    }

    if (root->left == nullptr && root->right == nullptr) {
        answer = max(answer, p.first - p.second);
    }
}

int maximum_difference_between_node_and_ancestor::Solution::maxAncestorDiff(TreeNode* root) {
    dfs(root, {root->val, root->val});

    return answer;
}

void maximum_difference_between_node_and_ancestor::Solution::test() {
    auto* t1 = new TreeNode(8);
    auto* t2 = new TreeNode(3);
    auto* t3 = new TreeNode(1);
    auto* t4 = new TreeNode(6);
    auto* t5 = new TreeNode(4);
    auto* t6 = new TreeNode(7);
    auto* t7 = new TreeNode(10);
    auto* t8 = new TreeNode(14);
    auto* t9 = new TreeNode(13);

    t1->left = t2;
    t2->left = t3;
    t2->right = t4;
    t4->left = t5;
    t4->right = t6;
    t1->right = t7;
    t7->right = t8;
    t8->left = t9;

    assert(maxAncestorDiff(t1) == 7);

    cout << "maxAncestorDiff completed!" << endl;
}
