//
// Created by dexhacker on 10/14/22.
//

#include "Solution.h"
#include <vector>
#include <cassert>

ListNode *delete_the_middle_node_of_a_linked_list::Solution::deleteMiddle(ListNode *head) {
    if (head->next == nullptr) return nullptr;

    int size = 0;
    auto current = head;
    while (current) {
        current = current->next;
        size++;
    }

    int middle = size / 2;
    current = head;
    for (int i = 1; i < middle; i++) {
        current = current->next;
    }

    auto tmp = current->next;
    if (tmp) {
        current->next = tmp->next;
    } else {
        current->next = nullptr;
    }

    return head;
}

void delete_the_middle_node_of_a_linked_list::Solution::test() {
    auto node1 = new ListNode(1);
    auto node2 = new ListNode(3);
    auto node3 = new ListNode(4);
    auto node4 = new ListNode(7);
    auto node5 = new ListNode(1);
    auto node6 = new ListNode(2);
    auto node7 = new ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    auto result = deleteMiddle(node1);
    vector<int> answer {1, 3, 4, 1, 2, 6};
    int index = 0;
    while (result) {
        assert(result->val == answer[index]);
        index++;
        result = result->next;
    }

    cout << "deleteMiddle completed!" << endl;
}
