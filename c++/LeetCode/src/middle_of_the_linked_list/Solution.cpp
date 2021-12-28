//
// Created by Фарид Абдугалыев on 28.12.2021.
//

#include "Solution.h"
#include <cassert>

ListNode *middle_of_the_linked_list::Solution::middleNode(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void middle_of_the_linked_list::Solution::test() {
    auto l1 = new ListNode(1);
    auto l2 = new ListNode(2);
    auto l3 = new ListNode(3);
    auto l4 = new ListNode(4);
    auto l5 = new ListNode(5);
    auto l6 = new ListNode(6);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;

    assert(middleNode(l1) == l4);

    cout << "middleNode completed!" << endl;
}
