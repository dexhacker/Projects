//
// Created by dexhacker on 6/2/21.
//

#ifndef LEETCODE_SUBSETS_H
#define LEETCODE_SUBSETS_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace subsets {
    class Solution {
    public:
        void push_nums(vector<int> nums);
        vector<vector<int>> subsets(vector<int>& nums);
        void test();

    private:
        vector<vector<int>> answer;
        unordered_map<int, int> hm;
        vector<int> numbers;
    };
}

#endif //LEETCODE_SUBSETS_H
