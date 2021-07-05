//
// Created by dexhacker on 6/24/21.
//

#include "Solution.h"
#include <cassert>

ListNode * reverse_nodes_in_k_group::Solution::reverseKGroup(ListNode *head, int k) {
    if (k == 1) return head;
    if (head == nullptr or head->next == nullptr) return head;

    bool isEnough = true;
    auto prev = head;
    auto current = prev->next;
    head->next = nullptr;
    for (int i = 1; i < k; ++i) {
        if (current == nullptr) {
            isEnough = false;
            break;
        }

        auto next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    if (!isEnough) {
        current = prev->next;
        prev->next = nullptr;
        while (current) {
            cout << prev->val << endl;
            cout << current->val << endl;
            auto next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    if (current) head->next = reverseKGroup(current, k);

    return prev;
}

void reverse_nodes_in_k_group::Solution::test() {
    auto ln1 = new ListNode(1);
    auto ln2 = new ListNode(2);
    auto ln3 = new ListNode(3);
    auto ln4 = new ListNode(4);
    auto ln5 = new ListNode(5);
    ln1->next = ln2;
    ln2->next = ln3;
    ln3->next = ln4;
    ln4->next = ln5;
    auto head = reverseKGroup(ln1, 2);
    assert(head->val == 2);
    assert(head->next->val == 1);
    assert(head->next->next->val == 4);

    cout << "reverseKGroup completed!" << endl;
}
