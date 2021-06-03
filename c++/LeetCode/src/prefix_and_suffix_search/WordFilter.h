//
// Created by dexhacker on 6/2/21.
//

#ifndef LEETCODE_WORDFILTER_H
#define LEETCODE_WORDFILTER_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace prefix_and_suffix_search {
    class WordFilter {
    public:
        static void test();
        WordFilter(vector<string>& words);
        int f(string prefix, string suffix);

    private:
        unordered_map<string, unordered_map<string, int>> hash_map;
    };
}

#endif //LEETCODE_WORDFILTER_H
