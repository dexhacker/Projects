//
// Created by dexhacker on 4/16/21.
//

#ifndef LEETCODE_LINKED_LIST_CYCLE_II_H
#define LEETCODE_LINKED_LIST_CYCLE_II_H

#include "../ListNode.h"
#include <iostream>

using namespace std;

namespace linked_list_cycle_ii {
    class Solution {
    public:
        ListNode *detectCycle(ListNode *head);
        void test();
    };
}

#endif //LEETCODE_LINKED_LIST_CYCLE_II_H
