//
// Created by dexhacker on 4/16/21.
//

#ifndef LEETCODE_NODE_H
#define LEETCODE_NODE_H

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    vector<Node*> neighbors;

    Node* next;
    Node* random;
    Node* left;
    Node* right;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
        next = nullptr;
        random = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

#endif //LEETCODE_NODE_H
