//
// Created by dexhacker on 4/15/21.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

ListNode * rotate_list::Solution::rotateRight(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) return head;

    unordered_map<int, ListNode*> hash_map;
    auto current_node = head;
    int counter = 0;
    while (current_node != nullptr) {
        hash_map[counter] = current_node;
        current_node = current_node->next;
        counter++;
    }
    int move = k % counter;
    if (move == 0) return head;
    hash_map[counter - 1]->next = hash_map[0];
    hash_map[counter - 1 - move]->next = nullptr;
    return hash_map[counter - move];
}

void rotate_list::Solution::test() {
    auto test1_list_node1 = new ListNode(1);
    auto test1_list_node2 = new ListNode(2);
    auto test1_list_node3 = new ListNode(3);
    auto test1_list_node4 = new ListNode(4);
    auto test1_list_node5 = new ListNode(5);
    test1_list_node1->next = test1_list_node2;
    test1_list_node2->next = test1_list_node3;
    test1_list_node3->next = test1_list_node4;
    test1_list_node4->next = test1_list_node5;
    auto result1 = rotateRight(test1_list_node1, 2);
    int answer1[] {4, 5, 1, 2, 3};
    for (int i : answer1) {
        assert(result1->val == i);
        result1 = result1->next;
    }

    auto test2_list_node1 = new ListNode(0);
    auto test2_list_node2 = new ListNode(1);
    auto test2_list_node3 = new ListNode(2);
    test2_list_node1->next = test2_list_node2;
    test2_list_node2->next = test2_list_node3;
    auto result2 = rotateRight(test2_list_node1, 4);
    int answer2[] {2, 0, 1};
    for (int i : answer2) {
        assert(result2->val == i);
        result2 = result2->next;
    }

    auto test3_list_node1 = new ListNode(1);
    auto test3_list_node2 = new ListNode(2);
    test3_list_node1->next = test3_list_node2;
    auto result3 = rotateRight(test3_list_node1, 2);
    int answer3[] {1, 2};
    for (int i : answer3) {
        assert(result3->val == i);
        result3 = result3->next;
    }

    cout << "rotateRight completed!" << endl;
}
