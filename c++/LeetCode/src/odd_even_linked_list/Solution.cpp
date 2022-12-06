//
// Created by dexhacker on 12/6/22.
//

#include "Solution.h"
#include <cassert>

ListNode *odd_even_linked_list::Solution::oddEvenList(ListNode *head) {
    if (head == nullptr) return nullptr;

    auto even_head = head->next;

    if (even_head == nullptr || even_head->next == nullptr) return head;

    auto current_odd = head;
    auto current_even = head->next;
    while (true) {
        if (current_even->next == nullptr) {
            current_odd->next = even_head;
            break;
        }

        current_odd->next = current_even->next;
        current_odd = current_odd->next;

        if (current_odd->next == nullptr) {
            current_odd->next = even_head;
            current_even->next = nullptr;
            break;
        }

        current_even->next = current_odd->next;
        current_even = current_even->next;
    }

    return head;
}

void odd_even_linked_list::Solution::test() {
    auto list_node_1 = new ListNode(1);
    auto list_node_2 = new ListNode(2);
    auto list_node_3 = new ListNode(3);
    auto list_node_4 = new ListNode(4);
    auto list_node_5 = new ListNode(5);
    list_node_1->next = list_node_2;
    list_node_2->next = list_node_3;
    list_node_3->next = list_node_4;
    list_node_4->next = list_node_5;

    auto result = oddEvenList(list_node_1);
    assert(result->val == 1);
    assert(result->next->val == 3);
    assert(result->next->next->val == 5);
    assert(result->next->next->next->val == 2);
    assert(result->next->next->next->next->val == 4);

    cout << "oddEvenList completed!" << endl;
}
