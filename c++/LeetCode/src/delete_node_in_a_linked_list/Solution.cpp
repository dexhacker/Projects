//
// Created by dexhacker on 4/15/21.
//

#include "Solution.h"
#include <cassert>

void delete_node_in_a_linked_list::Solution::deleteNode(ListNode *node) {
    if (node == nullptr || node->next == nullptr) return;
    node->val = node->next->val;
    node->next = node->next->next;
}

void delete_node_in_a_linked_list::Solution::test() {
    auto test1_node_list1 = new ListNode(4);
    auto test1_node_list2 = new ListNode(5);
    auto test1_node_list3 = new ListNode(1);
    auto test1_node_list4 = new ListNode(9);
    test1_node_list1->next = test1_node_list2;
    test1_node_list2->next = test1_node_list3;
    test1_node_list3->next = test1_node_list4;
    deleteNode(test1_node_list2);
    int answer1[] {4, 1, 9};
    for (int i : answer1) {
        assert(test1_node_list1->val == i);
        test1_node_list1 = test1_node_list1->next;
    }

    auto test2_node_list1 = new ListNode(4);
    auto test2_node_list2 = new ListNode(5);
    auto test2_node_list3 = new ListNode(1);
    auto test2_node_list4 = new ListNode(9);
    test2_node_list1->next = test2_node_list2;
    test2_node_list2->next = test2_node_list3;
    test2_node_list3->next = test2_node_list4;
    deleteNode(test2_node_list3);
    int answer2[] {4, 5, 9};
    for (int i : answer2) {
        assert(test2_node_list1->val == i);
        test2_node_list1 = test2_node_list1->next;
    }

    auto test3_node_list1 = new ListNode(1);
    auto test3_node_list2 = new ListNode(2);
    auto test3_node_list3 = new ListNode(3);
    auto test3_node_list4 = new ListNode(4);
    test3_node_list1->next = test3_node_list2;
    test3_node_list2->next = test3_node_list3;
    test3_node_list3->next = test3_node_list4;
    deleteNode(test3_node_list3);
    int answer3[] {1, 2, 4};
    for (int i : answer3) {
        assert(test3_node_list1->val == i);
        test3_node_list1 = test3_node_list1->next;
    }

    auto test4_node_list1 = new ListNode(0);
    auto test4_node_list2 = new ListNode(1);
    test4_node_list1->next = test4_node_list2;
    deleteNode(test4_node_list1);
    assert(test4_node_list1->val == 1);

    auto test5_node_list1 = new ListNode(-3);
    auto test5_node_list2 = new ListNode(5);
    auto test5_node_list3 = new ListNode(-99);
    test5_node_list1->next = test5_node_list2;
    test5_node_list2->next = test5_node_list3;
    deleteNode(test5_node_list1);
    int answer5[] {5, -99};
    for (int i : answer5) {
        assert(test5_node_list1->val == i);
        test5_node_list1 = test5_node_list1->next;
    }

    cout << "removeElements completed!" << endl;
}
