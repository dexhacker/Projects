//
// Created by dexhacker on 6/22/21.
//

#ifndef LEETCODE_NUMBER_OF_MATCHING_SUBSEQUENCES_H
#define LEETCODE_NUMBER_OF_MATCHING_SUBSEQUENCES_H

#include <iostream>
#include <vector>

using namespace std;

namespace number_of_matching_subsequences {
    class Solution {
    public:
        int numMatchingSubseq(string s, vector<string>& words);
        void test();
    };
}

#endif //LEETCODE_NUMBER_OF_MATCHING_SUBSEQUENCES_H
