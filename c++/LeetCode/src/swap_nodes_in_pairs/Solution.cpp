//
// Created by dexhacker on 6/23/21.
//

#include "Solution.h"
#include <cassert>

ListNode * swap_nodes_in_pairs::Solution::swapPairs(ListNode *head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    auto temp = head->next->next;
    head->next->next = head;
    head = head->next;
    head->next->next = swapPairs(temp);

    return head;
}

void swap_nodes_in_pairs::Solution::test() {
    auto ln1 = new ListNode(1);
    auto ln2 = new ListNode(2);
    auto ln3 = new ListNode(3);
    auto ln4 = new ListNode(4);
    ln1->next = ln2;
    ln2->next = ln3;
    ln3->next = ln4;
    auto answer = swapPairs(ln1);
    assert(answer->val == 2);
    assert(answer->next->val == 1);

    cout << "swapPairs completed!" << endl;
}
