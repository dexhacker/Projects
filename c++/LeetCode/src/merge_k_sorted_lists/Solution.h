//
// Created by dexhacker on 3/18/21.
//

#ifndef LEETCODE_MERGE_K_SORTED_LISTS_H
#define LEETCODE_MERGE_K_SORTED_LISTS_H

#include "../ListNode.h"
#include <iostream>
#include <vector>

using namespace std;

namespace merge_k_sorted_lists {
    class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists);
        void test();
    };
}

#endif //LEETCODE_MERGE_K_SORTED_LISTS_H
