//
// Created by dexhacker on 4/29/21.
//

#ifndef LEETCODE_RANGE_SUM_QUERY_IMMUTABLE_H
#define LEETCODE_RANGE_SUM_QUERY_IMMUTABLE_H

#include <iostream>
#include <vector>

using namespace std;

namespace range_sum_query_immutable {
    class NumArray {
    public:
        static void test();
        NumArray(vector<int>& nums);
        int sumRange(int left, int right);

    private:
        vector<int> prefix;
    };
}

#endif //LEETCODE_RANGE_SUM_QUERY_IMMUTABLE_H
