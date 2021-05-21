//
// Created by dexhacker on 4/29/21.
//

#ifndef LEETCODE_WORD_SEARCH_H
#define LEETCODE_WORD_SEARCH_H

#include <iostream>
#include <vector>

using namespace std;

namespace word_search {
    class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word);
        void test();
    };
}

#endif //LEETCODE_WORD_SEARCH_H
