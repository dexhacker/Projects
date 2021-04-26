//
// Created by dexhacker on 4/16/21.
//

#include "Solution.h"
#include <cassert>

ListNode * linked_list_cycle_ii::Solution::detectCycle(ListNode *head) {
    if (head == nullptr) return nullptr;

    auto slow = head;
    auto fast = head;
    bool is_first = true;
    bool is_cycle = false;

    while (slow and fast and fast->next) {
        if (!is_first && slow == fast) {
            is_cycle = true;
            break;
        }

        slow = slow->next;
        fast = fast->next->next;
        is_first = false;
    }

    if (!is_cycle) return nullptr;

    auto current_node = head;
    while (true) {
        if (current_node == slow) break;
        current_node = current_node->next;
        slow = slow->next;
    }

    return current_node;
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
