//
// Created by dexhacker on 4/15/21.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

ListNode * remove_nth_node_from_end_of_list::Solution::removeNthFromEnd(ListNode *head, int n) {
    int counter = 1;
    unordered_map<int, ListNode*> hash_map;
    auto current_node = head;
    while (current_node != nullptr) {
        hash_map[counter] = current_node;
        current_node = current_node->next;
        counter++;
    }

    if (counter - n - 1 < 1) return hash_map[counter - n]->next;
    auto previous_node = hash_map[counter - n - 1];
    auto next_node = hash_map[counter - n + 1];
    previous_node->next = next_node;
    return head;
}

void remove_nth_node_from_end_of_list::Solution::test() {
    auto test1_list_node1 = new ListNode(1);
    auto test1_list_node2 = new ListNode(2);
    auto test1_list_node3 = new ListNode(3);
    auto test1_list_node4 = new ListNode(4);
    auto test1_list_node5 = new ListNode(5);
    test1_list_node1->next = test1_list_node2;
    test1_list_node2->next = test1_list_node3;
    test1_list_node3->next = test1_list_node4;
    test1_list_node4->next = test1_list_node5;
    auto result1 = removeNthFromEnd(test1_list_node1, 2);
    int answer1[] {1, 2, 3, 5};
    for (int i : answer1) {
        assert(result1->val == i);
        result1 = result1->next;
    }

    auto test2_list_node1 = new ListNode(1);
    assert(removeNthFromEnd(test2_list_node1, 1) == nullptr);

    auto test3_list_node1 = new ListNode(1);
    auto test3_list_node2 = new ListNode(2);
    test3_list_node1->next = test3_list_node2;
    auto result3 = removeNthFromEnd(test3_list_node1, 1);
    int answer3[] {1};
    for (int i : answer3) {
        assert(result3->val == i);
        result3 = result3->next;
    }

    auto test4_list_node1 = new ListNode(1);
    auto test4_list_node2 = new ListNode(2);
    test4_list_node1->next = test4_list_node2;
    auto result4 = removeNthFromEnd(test4_list_node1, 2);
    int answer4[] {2};
    for (int i : answer4) {
        assert(result4->val == i);
        result4 = result4->next;
    }

    cout << "removeNthFromEnd completed!" << endl;
}
