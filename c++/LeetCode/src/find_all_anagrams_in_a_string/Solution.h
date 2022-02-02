//
// Created by Фарид Абдугалыев on 02.02.2022.
//

#ifndef LEETCODE_FIND_ALL_ANAGRAMS_IN_A_STRING_H
#define LEETCODE_FIND_ALL_ANAGRAMS_IN_A_STRING_H

#include <iostream>
#include <vector>

using namespace std;

namespace find_all_anagrams_in_a_string {
    class Solution {
    public:
        bool equal(vector<int>& current, vector<int>& target);
        vector<int> findAnagrams(string s, string p);
        void test();
    };
}

#endif //LEETCODE_FIND_ALL_ANAGRAMS_IN_A_STRING_H
