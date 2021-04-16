//
// Created by dexhacker on 4/14/21.
//

#ifndef LEETCODE_MERGE_TWO_SORTED_LISTS_H
#define LEETCODE_MERGE_TWO_SORTED_LISTS_H

#include "../ListNode.h"
#include <iostream>

using namespace std;

namespace merge_two_sorted_lists {
    class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
        void test();
    };
}

#endif //LEETCODE_MERGE_TWO_SORTED_LISTS_H
