//
// Created by dexhacker on 9/21/22.
//

#ifndef LEETCODE_SUM_OF_EVEN_NUMBERS_AFTER_QUERIES_H
#define LEETCODE_SUM_OF_EVEN_NUMBERS_AFTER_QUERIES_H

#include <iostream>
#include <vector>

using namespace std;

namespace sum_of_even_numbers_after_queries {
    class Solution {
    public:
        vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries);
        void test();
    };
}

#endif //LEETCODE_SUM_OF_EVEN_NUMBERS_AFTER_QUERIES_H
