//
// Created by dexhacker on 4/16/21.
//

#include "Solution.h"
#include <cassert>
#include <unordered_map>

Node * copy_list_with_random_pointer::Solution::copyRandomList(Node *head) {
    if (head == nullptr) return nullptr;

    unordered_map<Node*, Node*> hash_map;
    auto current_node = head;
    Node* current_node_copy = nullptr;
    Node* head_copy = nullptr;
    while (current_node != nullptr) {
        if (current_node_copy == nullptr) {
            current_node_copy = new Node(current_node->val);
            head_copy = current_node_copy;
        } else {
            auto new_node = new Node(current_node->val);
            current_node_copy->next = new_node;
            current_node_copy = new_node;
        }
        hash_map[current_node] = current_node_copy;
        current_node = current_node->next;
    }

    current_node = head;
    while (current_node != nullptr) {
        if (current_node->random == nullptr) {
            hash_map[current_node]->random = nullptr;
        } else {
            hash_map[current_node]->random = hash_map[current_node->random];
        }
        current_node = current_node->next;
    }
    return head_copy;
}

void copy_list_with_random_pointer::Solution::test() {
    auto test1_node1 = new Node(7);
    auto test1_node2 = new Node(13);
    auto test1_node3 = new Node(11);
    auto test1_node4 = new Node(10);
    auto test1_node5 = new Node(1);
    test1_node1->next = test1_node2;
    test1_node2->next = test1_node3;
    test1_node3->next = test1_node4;
    test1_node4->next = test1_node5;
    test1_node2->random = test1_node1;
    test1_node3->random = test1_node5;
    test1_node4->random = test1_node3;
    test1_node5->random = test1_node1;
    auto result1 = copyRandomList(test1_node1);
    int answer1[] = {7, 13, 11, 10, 1};
    for (int i : answer1) {
        assert(result1->val == i);
        result1 = result1->next;
    }

    cout << "copyRandomList completed!" << endl;
}
