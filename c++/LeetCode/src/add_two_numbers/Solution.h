//
// Created by dexhacker on 1/12/21.
//

#ifndef LEETCODE_ADD_TWO_NUMBERS_SOLUTION_H
#define LEETCODE_ADD_TWO_NUMBERS_SOLUTION_H

namespace add_two_numbers {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
        void test();
    };
}

#endif //LEETCODE_ADD_TWO_NUMBERS_SOLUTION_H
