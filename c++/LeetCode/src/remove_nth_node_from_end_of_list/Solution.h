//
// Created by dexhacker on 4/15/21.
//

#ifndef LEETCODE_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#define LEETCODE_REMOVE_NTH_NODE_FROM_END_OF_LIST_H

#include "../ListNode.h"
#include <iostream>

using namespace std;

namespace remove_nth_node_from_end_of_list {
    class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n);
        void test();
    };
}

#endif //LEETCODE_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
