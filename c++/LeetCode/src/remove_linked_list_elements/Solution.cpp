//
// Created by dexhacker on 4/15/21.
//

#include "Solution.h"
#include <cassert>

ListNode * remove_linked_list_elements::Solution::removeElements(ListNode *head, int val) {
    auto current_node = head;
    ListNode* previous_node = nullptr;
    while (current_node != nullptr) {
        if (current_node->val == val) {
            if (previous_node == nullptr) {
                head = current_node->next;
                current_node = current_node->next;
            } else {
                previous_node->next = current_node->next;
                current_node = previous_node->next;
            }
            continue;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    return head;
}

void remove_linked_list_elements::Solution::test() {
    auto test1_node_list1 = new ListNode(1);
    auto test1_node_list2 = new ListNode(2);
    test1_node_list1->next = test1_node_list2;
    auto test1_node_list3 = new ListNode(6);
    test1_node_list2->next = test1_node_list3;
    auto test1_node_list4 = new ListNode(3);
    test1_node_list3->next = test1_node_list4;
    auto test1_node_list5 = new ListNode(4);
    test1_node_list4->next = test1_node_list5;
    auto test1_node_list6 = new ListNode(5);
    test1_node_list5->next = test1_node_list6;
    auto test1_node_list7 = new ListNode(6);
    test1_node_list6->next = test1_node_list7;
    auto result1 = removeElements(test1_node_list1, 6);
    int answer1[] = {1, 2, 3, 4, 5};
    for (int i : answer1) {
        assert(result1->val == i);
        result1 = result1->next;
    }

    auto test2_node_list1 = nullptr;
    auto result2 = removeElements(test2_node_list1, 1);
    assert(result2 == nullptr);

    auto test3_node_list1 = new ListNode(7);
    auto test3_node_list2 = new ListNode(7);
    test3_node_list1->next = test3_node_list2;
    auto test3_node_list3 = new ListNode(7);
    test3_node_list2->next = test3_node_list3;
    auto test3_node_list4 = new ListNode(7);
    test3_node_list3->next = test3_node_list4;
    auto result3 = removeElements(test3_node_list1, 7);
    assert(result3 == nullptr);

    cout << "removeElements completed!" << endl;
}
