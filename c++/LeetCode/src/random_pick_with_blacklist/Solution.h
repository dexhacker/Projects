//
// Created by dexhacker on 3/14/21.
//

#ifndef LEETCODE_RANDOM_PICK_WITH_BLACKLIST_H
#define LEETCODE_RANDOM_PICK_WITH_BLACKLIST_H

#include <iostream>
#include <vector>

using namespace std;

namespace random_pick_with_blacklist {
    class Solution {
    public:
        static void test();

        Solution(int N, vector<int>& blacklist);
        int pick();

    private:
        vector<vector<int>> numbers;
    };
}

#endif //LEETCODE_RANDOM_PICK_WITH_BLACKLIST_H
