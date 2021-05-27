//
// Created by dexhacker on 5/26/21.
//

#include "Solution.h"
#include <cassert>

void construct_binary_tree_from_preorder_and_inorder_traversal::Solution::find_left(TreeNode *root, int index,
                                                                                    int start_pos, int finish_pos) {
    for (int j = index; j < po.size(); j++) {
        for (int i = start_pos; i <= finish_pos; i++) {
            if (io[i] == po[j]) {
                auto temp = new TreeNode(po[j]);
                root->left = temp;
                find_left(temp, j + 1, start_pos, i - 1);
                find_right(temp, j + 1, i + 1, finish_pos);
                return;
            }
        }
    }
}

void construct_binary_tree_from_preorder_and_inorder_traversal::Solution::find_right(TreeNode *root, int index,
                                                                                     int start_pos, int finish_pos) {
    for (int j = index; j < po.size(); j++) {
        for (int i = start_pos; i <= finish_pos; i++) {
            if (io[i] == po[j]) {
                auto temp = new TreeNode(po[j]);
                root->right = temp;
                find_left(temp, j + 1, start_pos, i - 1);
                find_right(temp, j + 1, i + 1, finish_pos);
                return;
            }
        }
    }
}

TreeNode * construct_binary_tree_from_preorder_and_inorder_traversal::Solution::buildTree(vector<int> &preorder,
                                                                                          vector<int> &inorder) {
    po = preorder, io = inorder;

    auto root = new TreeNode(preorder[0]);
    for (int i = 0; i < inorder.size(); i++) {
        if (root->val == inorder[i]) {
            find_left(root, 1, 0, i - 1);
            find_right(root, 1, i + 1, inorder.size() - 1);
        }
    }

    return root;
}

void construct_binary_tree_from_preorder_and_inorder_traversal::Solution::test() {
    vector<int> test1_po {3, 9, 20, 15, 7};
    vector<int> test1_io {9, 3, 15, 20, 7};
    assert(buildTree(test1_po, test1_io)->val == 3);

    cout << "buildTree completed!" << endl;
}
