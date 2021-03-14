//
// Created by dexhacker on 3/13/21.
//

#ifndef LEETCODE_CAN_MAKE_PALINDROME_FROM_SUBSTRING_H
#define LEETCODE_CAN_MAKE_PALINDROME_FROM_SUBSTRING_H

#include <iostream>
#include <vector>

using namespace std;

namespace can_make_palindrome_from_substring {
    class Solution {
    public:
        vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries);
        void test();
    };
}

#endif //LEETCODE_CAN_MAKE_PALINDROME_FROM_SUBSTRING_H
