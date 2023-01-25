//
// Created by dexhacker on 1/25/23.
//

#ifndef LEETCODE_FIND_CLOSEST_NODE_TO_GIVEN_TWO_NODES_H
#define LEETCODE_FIND_CLOSEST_NODE_TO_GIVEN_TWO_NODES_H

#include <iostream>
#include <vector>

using namespace std;

namespace find_closest_node_to_given_two_nodes {
    class Solution {
    public:
        int closestMeetingNode(vector<int>& edges, int node1, int node2);
        void test();
    };
}

#endif //LEETCODE_FIND_CLOSEST_NODE_TO_GIVEN_TWO_NODES_H
