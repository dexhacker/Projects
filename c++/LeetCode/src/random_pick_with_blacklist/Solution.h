//
// Created by dexhacker on 3/14/21.
//

#ifndef LEETCODE_RANDOM_PICK_WITH_BLACKLIST_H
#define LEETCODE_RANDOM_PICK_WITH_BLACKLIST_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>

using namespace std;

namespace random_pick_with_blacklist {
    class Solution {
    public:
        static void test();

        Solution(int N, vector<int>& blacklist);
        int pick();

    private:
        unordered_map<int, int> hash_map;
        int n;
        mt19937 gen;
        uniform_int_distribution<> dis;
    };
}

#endif //LEETCODE_RANDOM_PICK_WITH_BLACKLIST_H
