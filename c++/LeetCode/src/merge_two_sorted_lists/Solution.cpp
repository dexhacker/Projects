//
// Created by dexhacker on 4/14/21.
//

#include "Solution.h"
#include <cassert>

ListNode* merge_two_sorted_lists::Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* head = nullptr;
    ListNode* current_node = nullptr;
    while (l1 != nullptr || l2 != nullptr) {
        if (l1 == nullptr) {
            if (current_node == nullptr) {
                head = new ListNode(l2->val);
                current_node = head;
            } else {
                auto l2_tmp = new ListNode(l2->val);
                current_node->next = l2_tmp;
                current_node = l2_tmp;
            }
            l2 = l2->next;
            continue;
        }

        if (l2 == nullptr) {
            if (current_node == nullptr) {
                head = new ListNode(l1->val);
                current_node = head;
            } else {
                auto l1_tmp = new ListNode(l1->val);
                current_node->next = l1_tmp;
                current_node = l1_tmp;
            }
            l1 = l1->next;
            continue;
        }

        if (l1->val > l2->val) {
            if (current_node == nullptr) {
                head = new ListNode(l2->val);
                current_node = head;
            } else {
                auto l2_tmp = new ListNode(l2->val);
                current_node->next = l2_tmp;
                current_node = l2_tmp;
            }
            l2 = l2->next;
            continue;
        } else if (l1->val < l2->val) {
            if (current_node == nullptr) {
                head = new ListNode(l1->val);
                current_node = head;
            } else {
                auto l1_tmp = new ListNode(l1->val);
                current_node->next = l1_tmp;
                current_node = l1_tmp;
            }
            l1 = l1->next;
            continue;
        } else {
            if (current_node == nullptr) {
                head = new ListNode(l1->val);
                current_node = head;

                auto l2_tmp = new ListNode(l2->val);
                current_node->next = l2_tmp;
                current_node = l2_tmp;
            } else {
                auto l1_tmp = new ListNode(l1->val);
                current_node->next = l1_tmp;
                current_node = l1_tmp;

                auto l2_tmp = new ListNode(l2->val);
                current_node->next = l2_tmp;
                current_node = l2_tmp;
            }
            l1 = l1->next;
            l2 = l2->next;
            continue;
        }
    }
    return head;
}

void merge_two_sorted_lists::Solution::test() {
//    TEST1
    auto test1_list_node1_node1 = new ListNode(1);
    auto test1_list_node1_node2 = new ListNode(2);
    test1_list_node1_node1->next = test1_list_node1_node2;
    auto test1_list_node1_node3 = new ListNode(4);
    test1_list_node1_node2->next = test1_list_node1_node3;

    auto test1_list_node2_node1 = new ListNode(1);
    auto test1_list_node2_node2 = new ListNode(3);
    test1_list_node2_node1->next = test1_list_node2_node2;
    auto test1_list_node2_node3 = new ListNode(4);
    test1_list_node2_node2->next = test1_list_node2_node3;

    auto result1 = mergeTwoLists(test1_list_node1_node1, test1_list_node2_node1);
    int answer1[] = { 1, 1, 2, 3, 4, 4};

    for (int i : answer1) {
        assert(result1->val == i);
        result1 = result1->next;
    }

//    TEST2
    auto test2_list_node1_node1 = nullptr;
    auto test2_list_node2_node1 = nullptr;

    auto result2 = mergeTwoLists(test2_list_node1_node1, test2_list_node2_node1);

    assert(result2 == nullptr);

//    TEST3
    auto test3_list_node1_node1 = nullptr;
    auto test3_list_node2_node1 = new ListNode(0);

    auto result3 = mergeTwoLists(test3_list_node1_node1, test3_list_node2_node1);

    int answer3[] = {0};

    for (int i : answer3) {
        assert(result3->val == i);
        result3 = result3->next;
    }

//    TEST4
    auto test4_list_node1_node1 = new ListNode(1);
    auto test4_list_node2_node1 = nullptr;

    auto result4 = mergeTwoLists(test4_list_node1_node1, test4_list_node2_node1);

    int answer4[] = {1};

    for (int i : answer4) {
        assert(result4->val == i);
        result4 = result4->next;
    }

    cout << "mergeTwoLists completed!" << std::endl;
}
