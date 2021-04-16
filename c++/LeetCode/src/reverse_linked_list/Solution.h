//
// Created by dexhacker on 4/15/21.
//

#ifndef LEETCODE_REVERSE_LINKED_LIST_H
#define LEETCODE_REVERSE_LINKED_LIST_H

#include "../ListNode.h"
#include <iostream>

using namespace std;

namespace reverse_linked_list {
    class Solution {
    public:
        ListNode* reverseList(ListNode* head);
        void test();
    };
}

#endif //LEETCODE_REVERSE_LINKED_LIST_H
