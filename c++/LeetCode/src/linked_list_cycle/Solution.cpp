//
// Created by dexhacker on 4/15/21.
//

#include "Solution.h"
#include <cassert>
#include <unordered_map>

bool linked_list_cycle::Solution::hasCycle(ListNode *head) {
    unordered_map<ListNode*,bool> hash_map;
    while (head != nullptr) {
        if (hash_map[head]) return true;
        hash_map[head] = true;
        head = head->next;
    }
    return false;
}

void linked_list_cycle::Solution::test() {
    auto test1_list_node1 = new ListNode(3);
    auto test1_list_node2 = new ListNode(2);
    test1_list_node1->next = test1_list_node2;
    auto test1_list_node3 = new ListNode(0);
    test1_list_node2->next = test1_list_node3;
    auto test1_list_node4 = new ListNode(-4);
    test1_list_node3->next = test1_list_node4;
    test1_list_node4->next = test1_list_node2;
    assert(hasCycle(test1_list_node1) == true);


    auto test2_list_node1 = new ListNode(1);
    auto test2_list_node2 = new ListNode(2);
    test2_list_node1->next = test2_list_node2;
    test2_list_node2->next = test2_list_node1;
    assert(hasCycle(test2_list_node1) == true);


    auto test3_list_node1 = new ListNode(1);
    assert(hasCycle(test3_list_node1) == false);

    cout << "hasCycle completed!" << std::endl;
}
