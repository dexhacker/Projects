//
// Created by dexhacker on 10/14/22.
//

#ifndef LEETCODE_DELETE_THE_MIDDLE_NODE_OF_A_LINKED_LIST_H
#define LEETCODE_DELETE_THE_MIDDLE_NODE_OF_A_LINKED_LIST_H

#include <iostream>
#include "../ListNode.h"

using namespace std;

namespace delete_the_middle_node_of_a_linked_list {
    class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head);
        void test();
    };
}

#endif //LEETCODE_DELETE_THE_MIDDLE_NODE_OF_A_LINKED_LIST_H
