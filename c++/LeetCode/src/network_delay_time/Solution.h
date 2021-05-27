//
// Created by dexhacker on 5/27/21.
//

#ifndef LEETCODE_NETWORK_DELAY_TIME_H
#define LEETCODE_NETWORK_DELAY_TIME_H

#include <iostream>
#include <vector>

using namespace std;

namespace network_delay_time {
    class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k);
        void test();
    };
}

#endif //LEETCODE_NETWORK_DELAY_TIME_H
