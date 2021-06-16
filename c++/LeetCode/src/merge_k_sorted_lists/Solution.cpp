//
// Created by dexhacker on 3/18/21.
//

#include "Solution.h"
#include <cassert>

ListNode* merge_k_sorted_lists::Solution::mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    if (lists.size() == 1 && lists[0]->next == nullptr) return nullptr;

    vector<int> numbers;
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] == nullptr) continue;

        ListNode *current = lists[i];
        numbers.push_back(current->val);
        while (current->next) {
            current = current->next;
            numbers.push_back(current->val);
        }
    }

    if (numbers.empty()) return nullptr;

    sort(numbers.begin(), numbers.end());
    ListNode *current = new ListNode(numbers[0]);
    ListNode *first = current;
    for (int i = 1; i < numbers.size(); i++) {
        current->next = new ListNode(numbers[i]);
        current = current->next;
    }
    return first;
}

void merge_k_sorted_lists::Solution::test() {
    ListNode *test1_list1 = new ListNode(1);
    ListNode *test1_list2 = new ListNode(4);
    ListNode *test1_list3 = new ListNode(5);
    test1_list2->next = test1_list3;
    test1_list1->next = test1_list2;

    ListNode *test1_list4 = new ListNode(1);
    ListNode *test1_list5 = new ListNode(3);
    ListNode *test1_list6 = new ListNode(4);
    test1_list5->next = test1_list6;
    test1_list4->next = test1_list5;

    ListNode *test1_list7 = new ListNode(2);
    ListNode *test1_list8 = new ListNode(6);
    test1_list7->next = test1_list8;

    vector<ListNode*> test1 {test1_list1, test1_list4, test1_list7};

    ListNode *test1_answer1 = new ListNode(1);
    ListNode *test1_answer2 = new ListNode(1);
    ListNode *test1_answer3 = new ListNode(2);
    ListNode *test1_answer4 = new ListNode(3);
    ListNode *test1_answer5 = new ListNode(4);
    ListNode *test1_answer6 = new ListNode(4);
    ListNode *test1_answer7 = new ListNode(5);
    ListNode *test1_answer8 = new ListNode(6);
    test1_answer7->next = test1_answer8;
    test1_answer6->next = test1_answer7;
    test1_answer5->next = test1_answer6;
    test1_answer4->next = test1_answer5;
    test1_answer3->next = test1_answer4;
    test1_answer2->next = test1_answer3;
    test1_answer1->next = test1_answer2;

    assert(mergeKLists(test1)->val == test1_answer1->val);

    cout << "mergeKLists completed!" << endl;
}
