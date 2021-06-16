//
// Created by dexhacker on 6/16/21.
//

#ifndef LEETCODE_GENERATE_PARENTHESES_H
#define LEETCODE_GENERATE_PARENTHESES_H

#include <iostream>
#include <vector>

using namespace std;

namespace generate_parentheses {
    class Solution {
    public:
        void dfs(string s, int open, int close);
        vector<string> generateParenthesis(int n);
        void test();

    private:
        vector<string> answer;
    };
}

#endif //LEETCODE_GENERATE_PARENTHESES_H
