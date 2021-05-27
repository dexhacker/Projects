//
// Created by dexhacker on 5/27/21.
//

#include "Solution.h"
#include <cassert>

TreeNode * convert_sorted_list_to_binary_search_tree::Solution::sortedArrayToBST(vector<int> &nums) {
    if (nums.empty()) return nullptr;

    auto root = new TreeNode(nums[nums.size() / 2]);
    vector<int> left_vector(nums.begin(), nums.begin() + nums.size() / 2);
    root->left = sortedArrayToBST(left_vector);
    vector<int> right_vector(nums.begin() + nums.size() / 2 + 1, nums.end());
    root->right = sortedArrayToBST(right_vector);
    return root;
}

TreeNode * convert_sorted_list_to_binary_search_tree::Solution::sortedListToBST(ListNode *head) {
    if (head == nullptr) return nullptr;

    vector<int> numbers;
    auto current_head = head;
    while (current_head != nullptr) {
        numbers.push_back(current_head->val);
        current_head = current_head->next;
    }

    return sortedArrayToBST(numbers);
}

void convert_sorted_list_to_binary_search_tree::Solution::test() {
    auto node1 = new ListNode(-10);
    auto node2 = new ListNode(-3);
    auto node3 = new ListNode(0);
    auto node4 = new ListNode(5);
    auto node5 = new ListNode(9);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    assert(sortedListToBST(node1)->val == 0);

    cout << "sortedListToBST completed!" << endl;
}
