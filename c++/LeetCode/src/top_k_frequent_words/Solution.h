//
// Created by dexhacker on 10/19/22.
//

#ifndef LEETCODE_TOP_K_FREQUENT_WORDS_H
#define LEETCODE_TOP_K_FREQUENT_WORDS_H

#include <iostream>
#include <vector>

using namespace std;

namespace top_k_frequent_words {
    class Solution {
    public:
        vector<string> topKFrequent(vector<string>& words, int k);
        void test();
    };
}

#endif //LEETCODE_TOP_K_FREQUENT_WORDS_H
