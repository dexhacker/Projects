//
// Created by dexhacker on 7/25/21.
//

#ifndef LEETCODE_WORD_LADDER_II_H
#define LEETCODE_WORD_LADDER_II_H

#include <iostream>
#include <vector>

using namespace std;

namespace word_ladder_ii {
    struct WordParent {
        WordParent *parent;
        string word;
        WordParent(WordParent *a, string b) : parent(a), word(b) {}
    };

    class Solution {
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
        void test();
    };
}

#endif //LEETCODE_WORD_LADDER_II_H
