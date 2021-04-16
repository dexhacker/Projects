//
// Created by dexhacker on 4/15/21.
//

#include "Solution.h"
#include <cassert>

ListNode * reverse_linked_list::Solution::reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* previous_node = nullptr;
    auto current_node = head;
    auto next_node = head->next;
    while (current_node != nullptr) {
        current_node->next = previous_node;

        previous_node = current_node;
        current_node = next_node;
        if (current_node != nullptr) next_node = next_node->next;
    }
    return previous_node;
}

void reverse_linked_list::Solution::test() {
    auto test1_list_node1 = new ListNode(1);
    auto test1_list_node2 = new ListNode(2);
    auto test1_list_node3 = new ListNode(3);
    auto test1_list_node4 = new ListNode(4);
    auto test1_list_node5 = new ListNode(5);
    test1_list_node1->next = test1_list_node2;
    test1_list_node2->next = test1_list_node3;
    test1_list_node3->next = test1_list_node4;
    test1_list_node4->next = test1_list_node5;
    auto result1 = reverseList(test1_list_node1);
    int answer1[] {5, 4, 3, 2, 1};
    for (int i : answer1) {
        assert(result1->val == i);
        result1 = result1->next;
    }

    auto test2_list_node1 = new ListNode(1);
    auto test2_list_node2 = new ListNode(2);
    test2_list_node1->next = test2_list_node2;
    auto result2 = reverseList(test2_list_node1);
    int answer2[] {2, 1};
    for (int i : answer2) {
        assert(result2->val == i);
        result2 = result2->next;
    }

    auto test3_list_node1 = nullptr;
    assert(reverseList(test3_list_node1) == nullptr);

    cout << "reverseList completed!" << endl;
}
