//
// Created by dexhacker on 5/26/21.
//

#include "Solution.h"
#include <cassert>

TreeNode * convert_sorted_array_to_binary_search_tree::Solution::sortedArrayToBST(vector<int> &nums) {
    if (nums.empty()) return nullptr;

    auto root = new TreeNode(nums[nums.size() / 2]);
    vector<int> left_vector(nums.begin(), nums.begin() + nums.size() / 2);
    root->left = sortedArrayToBST(left_vector);
    vector<int> right_vector(nums.begin() + nums.size() / 2 + 1, nums.end());
    root->right = sortedArrayToBST(right_vector);
    return root;
}

void convert_sorted_array_to_binary_search_tree::Solution::test() {
    vector<int> test1 {-10, -3, 0, 5, 9};
    assert(sortedArrayToBST(test1)->val == 0);

    vector<int> test2 {1, 3};
    assert(sortedArrayToBST(test2)->val == 3);

    cout << "sortedArrayToBST completed!" << endl;
}
