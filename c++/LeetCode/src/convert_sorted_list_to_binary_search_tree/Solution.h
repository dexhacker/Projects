//
// Created by dexhacker on 5/27/21.
//

#ifndef LEETCODE_CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_H
#define LEETCODE_CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_H

#include "../ListNode.h"
#include "../TreeNode.h"
#include <iostream>
#include <vector>

using namespace std;

namespace convert_sorted_list_to_binary_search_tree {
    class Solution {
    public:
        TreeNode * sortedArrayToBST(vector<int> &nums);
        TreeNode* sortedListToBST(ListNode* head);
        void test();
    };
}

#endif //LEETCODE_CONVERT_SORTED_LIST_TO_BINARY_SEARCH_TREE_H
