//
// Created by Фарид Абдугалыев on 15.12.2021.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

ListNode *insertion_sort_list::Solution::insertionSortList(ListNode *head) {
    unordered_map<ListNode*, ListNode*> back;
    ListNode* previous = nullptr;
    ListNode* current = head;
    while(current) {
        back[current] = previous;
        previous = current;
        current = current->next;
    }

    current = head->next;
    while(current) {
        previous = back[current];
        bool is_continue = true;
        ListNode* next = current->next;
        while (is_continue) {
            if (previous == nullptr) {
                ListNode* prev = back[current];
                prev->next = current->next;
                back[current->next] = prev;

                current->next = head;
                back[head] = current;
                back[current] = nullptr;
                head = current;
                is_continue = false;
                continue;
            }

            if (previous->val < current->val) {
                if (previous->next == current) {
                    is_continue = false;
                    continue;
                }

                ListNode* prev = back[current];
                prev->next = current->next;
                back[current->next] = prev;

                current->next = previous->next;
                back[previous->next] = current;
                previous->next = current;
                back[current] = previous;
                is_continue = false;
                continue;
            }
            previous = back[previous];
        }
        current = next;
    }

    return head;
}

void insertion_sort_list::Solution::test() {
    auto l1 = new ListNode(6);
    auto l2 = new ListNode(5);
    auto l3 = new ListNode(3);
    auto l4 = new ListNode(1);
    auto l5 = new ListNode(8);
    auto l6 = new ListNode(7);
    auto l7 = new ListNode(2);
    auto l8 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;

    auto result = insertionSortList(l1);
    for (int i = 1; i <= 8; i++) {
        assert(result->val == i);
        result = result->next;
    }

    cout << "insertionSortList completed!" << endl;
}
