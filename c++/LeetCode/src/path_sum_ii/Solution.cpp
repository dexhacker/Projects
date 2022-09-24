//
// Created by dexhacker on 9/24/22.
//

#include "Solution.h"
#include <cassert>

void path_sum_ii::Solution::dfs(TreeNode *root, int targetSum, vector<int> sub_answer) {
    targetSum -= root->val;
    sub_answer.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr) {
        if (targetSum == 0) answer.push_back(sub_answer);
        return;
    }

    if (root->left != nullptr) dfs(root->left, targetSum, sub_answer);
    if (root->right != nullptr) dfs(root->right, targetSum, sub_answer);
}

vector<vector<int>> path_sum_ii::Solution::pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) return {};

    vector<int> sub_answer;
    dfs(root, targetSum, sub_answer);

    return answer;
}

void path_sum_ii::Solution::test() {
    auto n1 = new TreeNode(5);
    auto n2 = new TreeNode(4);
    auto n3 = new TreeNode(11);
    auto n4 = new TreeNode(7);
    auto n5 = new TreeNode(2);
    auto n6 = new TreeNode(8);
    auto n7 = new TreeNode(13);
    auto n8 = new TreeNode(4);
    auto n9 = new TreeNode(5);
    auto n10 = new TreeNode(1);
    n1->left = n2;
    n1->right = n6;
    n2->left = n3;
    n3->left = n4;
    n3->right = n5;
    n6->left = n7;
    n6->right = n8;
    n8->left = n9;
    n8->right = n10;
    vector<vector<int>> answer1 {{5, 4, 11, 2}, {5, 8, 4, 5}};
    auto result = pathSum(n1, 22);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            assert(answer1[i][j] == result[i][j]);
        }
    }

    cout << "pathSum completed!" << endl;
}
