//
// Created by dexhacker on 9/14/22.
//

#include "Solution.h"
#include <cassert>

void pseudo_palindromic_paths_in_a_binary_tree::Solution::dfs(TreeNode *root, vector<int> counts) {
    counts[root->val - 1]++;

    if (root->left) dfs(root->left, counts);
    if (root->right) dfs(root->right, counts);

    if (root->left == nullptr && root->right == nullptr) {
        int odd = 0;
        for (int i : counts) {
            if (i % 2 == 1) {
                odd++;
                if (odd > 1) return;
            }
        }

        answer++;
        return;
    }
}

int pseudo_palindromic_paths_in_a_binary_tree::Solution::pseudoPalindromicPaths(TreeNode *root) {
    vector<int> counts(9);
    dfs(root, counts);

    return answer;
}

void pseudo_palindromic_paths_in_a_binary_tree::Solution::test() {
    auto tree_node1 = new TreeNode(2);
    auto tree_node2 = new TreeNode(3);
    auto tree_node3 = new TreeNode(1);
    auto tree_node4 = new TreeNode(3);
    auto tree_node5 = new TreeNode(1);
    auto tree_node6 = new TreeNode(1);
    tree_node1->left = tree_node2;
    tree_node1->right = tree_node3;
    tree_node2->left = tree_node4;
    tree_node2->right = tree_node5;
    tree_node3->right = tree_node6;
    assert(pseudoPalindromicPaths(tree_node1) == 2);

    cout << "pseudoPalindromicPaths completed!" << endl;
}
