//
// Created by dexhacker on 5/19/21.
//

#ifndef LEETCODE_PERMUTATIONS_H
#define LEETCODE_PERMUTATIONS_H

#include <iostream>
#include <vector>

using namespace std;

namespace permutations {
    class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums);
        void solve(vector<int> & current_seq, int current_position);
        void test();

    private:
        int n;
        vector<vector<int>> list;
        vector<int> used;
    };
}

#endif //LEETCODE_PERMUTATIONS_H
