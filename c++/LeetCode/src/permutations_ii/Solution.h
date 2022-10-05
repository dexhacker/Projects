//
// Created by dexhacker on 10/5/22.
//

#ifndef LEETCODE_PERMUTATIONS_II_H
#define LEETCODE_PERMUTATIONS_II_H

#include <iostream>
#include <vector>

using namespace std;

namespace permutations_ii {
    class Solution {
    public:
        void reс(vector<int>& nums, vector<int> permutation, bool used[8]);
        vector<vector<int>> permuteUnique(vector<int>& nums);
        void test();

    private:
        vector<vector<int>> answer;
    };
}

#endif //LEETCODE_PERMUTATIONS_II_H
