//
// Created by dexhacker on 12/30/22.
//

#ifndef LEETCODE_SINGLE_THREADED_CPU_H
#define LEETCODE_SINGLE_THREADED_CPU_H

#include <iostream>
#include <vector>

using namespace std;

namespace single_threaded_cpu {
    class Solution {
    public:
        vector<int> getOrder(vector<vector<int>>& tasks);
        void test();
    };
}

#endif //LEETCODE_SINGLE_THREADED_CPU_H
