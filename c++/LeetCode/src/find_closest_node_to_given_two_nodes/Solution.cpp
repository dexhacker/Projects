//
// Created by dexhacker on 1/25/23.
//

#include "Solution.h"
#include <cassert>

int find_closest_node_to_given_two_nodes::Solution::closestMeetingNode(vector<int> &edges, int node1, int node2) {
    vector<int> used(edges.size(), 0);
    int answer = -1;
    while (node1 != -1 || node2 != -1) {
        if (node1 != -1) {
            if (used[node1] == 1) {
                node1 = -1;
            } else {
                if (used[node1] == 2) answer = node1;
                used[node1] = 1;
                node1 = edges[node1];
            }
        }

        if (node2 != -1) {
            if (used[node2] == 2) {
                node2 = -1;
            } else {
                if (used[node2] == 1) {
                    if (answer == -1) {
                        answer = node2;
                    } else {
                        answer = min(answer, node2);
                    }
                }
                used[node2] = 2;
                node2 = edges[node2];
            }
        }

        if (answer != -1) return answer;
    }
    return answer;
}

void find_closest_node_to_given_two_nodes::Solution::test() {
    vector<int> edges {2, 2, 3, -1};
    assert(closestMeetingNode(edges, 0, 1) == 2);

    cout << "closestMeetingNode completed!" << endl;
}
