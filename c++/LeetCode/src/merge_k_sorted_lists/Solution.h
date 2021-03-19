//
// Created by dexhacker on 3/18/21.
//

#ifndef LEETCODE_MERGE_K_SORTED_LISTS_H
#define LEETCODE_MERGE_K_SORTED_LISTS_H

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

namespace merge_k_sorted_lists {
    class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists);
        void test();
    };
}

#endif //LEETCODE_MERGE_K_SORTED_LISTS_H
