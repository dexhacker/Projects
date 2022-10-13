//
// Created by dexhacker on 10/13/22.
//

#ifndef LEETCODE_GROUP_ANAGRAMS_H
#define LEETCODE_GROUP_ANAGRAMS_H

#include <iostream>
#include <vector>

using namespace std;

namespace group_anagrams {
    class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs);
        void test();
    };
}

#endif //LEETCODE_GROUP_ANAGRAMS_H
