//
// Created by dexhacker on 12/18/22.
//

#ifndef LEETCODE_EVALUATE_REVERSE_POLISH_NOTATION_H
#define LEETCODE_EVALUATE_REVERSE_POLISH_NOTATION_H

#include <iostream>
#include <vector>

using namespace std;

namespace evaluate_reverse_polish_notation {
    class Solution {
    public:
        int evalRPN(vector<string>& tokens);
        void test();
    };
}

#endif //LEETCODE_EVALUATE_REVERSE_POLISH_NOTATION_H
