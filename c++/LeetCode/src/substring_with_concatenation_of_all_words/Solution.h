//
// Created by Фарид Абдугалыев on 24.12.2021.
//

#ifndef LEETCODE_SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_H
#define LEETCODE_SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_H

#include <iostream>
#include <vector>

using namespace std;

namespace substring_with_concatenation_of_all_words {
    class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words);
        void test();
    };
}

#endif //LEETCODE_SUBSTRING_WITH_CONCATENATION_OF_ALL_WORDS_H
