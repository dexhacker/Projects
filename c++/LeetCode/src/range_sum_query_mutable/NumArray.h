//
// Created by dexhacker on 6/18/21.
//

#ifndef LEETCODE_RANGE_SUM_QUERY_MUTABLE_H
#define LEETCODE_RANGE_SUM_QUERY_MUTABLE_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace range_sum_query_mutable {
    struct Node {
        int start;
        int finish;
        int sum;
        Node* left;
        Node* right;
        Node(int start, int finish, int sum, Node* left, Node* right): start(start), finish(finish), sum(sum), left(left), right(right) {}
    };

    class NumArray {
    public:
        static void test();
        Node* getRoot(vector<int>& nums, int start, int finish);
        NumArray(vector<int>& nums);
        void update(int index, int val);
        int sumRange(int left, int right);

    private:
        Node* head;
    };
}

#endif //LEETCODE_RANGE_SUM_QUERY_MUTABLE_H
