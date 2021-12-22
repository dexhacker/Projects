//
// Created by Фарид Абдугалыев on 22.12.2021.
//

#include "Solution.h"
#include <vector>
#include <cassert>

void reorder_list::Solution::reorderList(ListNode *head) {
    vector<ListNode*> nodes;
    ListNode* current = head;
    while (current) {
        nodes.push_back(current);
        current = current->next;
    }

    int l = 0, r = nodes.size() - 1;
    current = nullptr;
    while (l <= r) {
        if (current == nullptr) {
            current = nodes[l];
        } else {
            current->next = nodes[l];
            current = current->next;
        }

        if (l != r) {
            current->next = nodes[r];
            current = current->next;
        }

        l++;
        r--;
    }

    current->next = nullptr;
}

void reorder_list::Solution::test() {
    auto l1 = new ListNode(1);
    auto l2 = new ListNode(2);
    auto l3 = new ListNode(3);
    auto l4 = new ListNode(4);
    auto l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    reorderList(l1);

    assert(l1->val == 1);
    assert(l1->next->val == 5);
    assert(l1->next->next->val == 2);

    cout << "reorderList completed!" << endl;
}
