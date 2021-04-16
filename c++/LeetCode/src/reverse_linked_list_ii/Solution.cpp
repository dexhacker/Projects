//
// Created by dexhacker on 4/15/21.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

ListNode * reverse_linked_list_ii::Solution::reverseBetween(ListNode *head, int left, int right) {
    if (left == right) return head;

    unordered_map<int, ListNode*> hash_map;
    int counter = 1;
    ListNode* previous_node = nullptr;
    ListNode* reverse_head_node = nullptr;
    auto new_head = head;
    auto current_node = head;
    auto next_node = head->next;
    while (current_node != nullptr) {
        hash_map[counter] = current_node;
        if (counter >= left && counter <= right) {
            if (reverse_head_node == nullptr) reverse_head_node = current_node;
            current_node->next = previous_node;
        }

        previous_node = current_node;
        current_node = next_node;
        if (current_node != nullptr) next_node = current_node->next;
        counter++;
    }

    if (hash_map.count(left - 1) > 0) {
        hash_map[left - 1]->next = hash_map[right];
    } else {
        new_head = hash_map[right];
    }
    if (hash_map.count(right + 1) > 0) {
        reverse_head_node->next = hash_map[right + 1];
    } else {
        hash_map[left]->next = nullptr;
    }

    return new_head;
}

void reverse_linked_list_ii::Solution::test() {
    auto test1_list_node1 = new ListNode(1);
    auto test1_list_node2 = new ListNode(2);
    auto test1_list_node3 = new ListNode(3);
    auto test1_list_node4 = new ListNode(4);
    auto test1_list_node5 = new ListNode(5);
    test1_list_node1->next = test1_list_node2;
    test1_list_node2->next = test1_list_node3;
    test1_list_node3->next = test1_list_node4;
    test1_list_node4->next = test1_list_node5;
    auto result1 = reverseBetween(test1_list_node1, 2, 4);
    int answer1[] {1, 4, 3, 2, 5};
    for (int i : answer1) {
        assert(result1->val == i);
        result1 = result1->next;
    }

    auto test2_list_node1 = new ListNode(5);
    auto result2 = reverseBetween(test2_list_node1, 1, 1);
    assert(result2->val == 5);

    auto test3_list_node1 = new ListNode(3);
    auto test3_list_node2 = new ListNode(5);
    test3_list_node1->next = test3_list_node2;
    auto result3 = reverseBetween(test3_list_node1, 1, 1);
    int answer3[] {3, 5};
    for (int i : answer3) {
        assert(result3->val == i);
        result3 = result3->next;
    }

    auto test4_list_node1 = new ListNode(3);
    auto test4_list_node2 = new ListNode(5);
    test4_list_node1->next = test4_list_node2;
    auto result4 = reverseBetween(test4_list_node1, 1, 2);
    int answer4[] {5, 3};
    for (int i : answer4) {
        assert(result4->val == i);
        result4 = result4->next;
    }

    auto test5_list_node1 = new ListNode(1);
    auto test5_list_node2 = new ListNode(2);
    auto test5_list_node3 = new ListNode(3);
    test5_list_node1->next = test5_list_node2;
    test5_list_node2->next = test5_list_node3;
    auto result5 = reverseBetween(test5_list_node1, 2, 3);
    int answer5[] {1, 3, 2};
    for (int i : answer5) {
        assert(result5->val == i);
        result5 = result5->next;
    }

    cout << "reverseBetween completed!" << endl;
}
