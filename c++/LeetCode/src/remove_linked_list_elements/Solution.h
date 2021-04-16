//
// Created by dexhacker on 4/15/21.
//

#ifndef LEETCODE_REMOVE_LINKED_LIST_ELEMENTS_H
#define LEETCODE_REMOVE_LINKED_LIST_ELEMENTS_H

#include "../ListNode.h"
#include <iostream>

using namespace std;

namespace remove_linked_list_elements {
    class Solution {
    public:
        ListNode* removeElements(ListNode* head, int val);
        void test();
    };
}

#endif //LEETCODE_REMOVE_LINKED_LIST_ELEMENTS_H
