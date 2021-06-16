//
// Created by dexhacker on 6/14/21.
//

#ifndef LEETCODE_PALINDROME_PAIRS_H
#define LEETCODE_PALINDROME_PAIRS_H

#include <iostream>
#include <vector>

using namespace std;

namespace palindrome_pairs {
    class Solution {
    public:
        bool is_palindrome(string& s, int start, int end);
        vector<vector<int>> palindromePairs(vector<string>& words);
        void test();
    };
}

#endif //LEETCODE_PALINDROME_PAIRS_H
