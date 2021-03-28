//
// Created by dexhacker on 3/28/21.
//

#ifndef LEETCODE_WORD_LADDER_H
#define LEETCODE_WORD_LADDER_H

#include <iostream>
#include <vector>

using namespace std;

namespace word_ladder {
    class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList);
        void test();
    };
}

#endif //LEETCODE_WORD_LADDER_H
