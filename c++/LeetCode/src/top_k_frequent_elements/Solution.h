//
// Created by dexhacker on 4/16/21.
//

#ifndef LEETCODE_TOP_K_FREQUENT_ELEMENTS_H
#define LEETCODE_TOP_K_FREQUENT_ELEMENTS_H

#include <iostream>
#include <vector>

using namespace std;

namespace top_k_frequent_elements {
    class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k);
        void test();
    };
}

#endif //LEETCODE_TOP_K_FREQUENT_ELEMENTS_H
