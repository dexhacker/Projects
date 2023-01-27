//
// Created by dexhacker on 1/27/23.
//

#ifndef LEETCODE_CONCATENATED_WORDS_H
#define LEETCODE_CONCATENATED_WORDS_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace concatenated_words {
    class Solution {
    private:
        unordered_map<string, bool> m;
        vector<string> answer;

    public:
        void check(string s, int i, vector<string>& words);
        vector<string> findAllConcatenatedWordsInADict(vector<string>& words);
        void test();
    };
}

#endif //LEETCODE_CONCATENATED_WORDS_H
