//
// Created by dexhacker on 4/16/21.
//

#include "Solution.h"
#include <cassert>

ListNode * linked_list_cycle_ii::Solution::detectCycle(ListNode *head) {
    if (head == nullptr) return nullptr;

    auto current_node = head;
    ListNode* target_node = nullptr;
    while (current_node != nullptr) {
        if (current_node->val > 200000) {
            target_node = current_node;
            break;
        }
        current_node->val = current_node->val + 300000;
        current_node = current_node->next;
    }
    if (target_node == nullptr) return nullptr;

    current_node = head;
    while (current_node->val < 200000) {
        current_node->val = current_node->val - 300000;
        current_node = current_node->next;
    }

    return target_node;
}

void linked_list_cycle_ii::Solution::test() {
    auto test1_list_node1 = new ListNode(3);
    auto test1_list_node2 = new ListNode(2);
    auto test1_list_node3 = new ListNode(0);
    auto test1_list_node4 = new ListNode(4);
    test1_list_node1->next = test1_list_node2;
    test1_list_node2->next = test1_list_node3;
    test1_list_node3->next = test1_list_node4;
    test1_list_node4->next = test1_list_node2;
    assert(test1_list_node2 == detectCycle(test1_list_node1));

    auto test2_list_node1 = new ListNode(1);
    auto test2_list_node2 = new ListNode(2);
    test2_list_node1->next = test2_list_node2;
    test2_list_node2->next = test2_list_node1;
    assert(test2_list_node1 == detectCycle(test2_list_node1));

    auto test3_list_node1 = new ListNode(1);
    assert(nullptr == detectCycle(test3_list_node1));

    cout << "detectCycle completed!" << endl;
}
