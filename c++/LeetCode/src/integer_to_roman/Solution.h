//
// Created by dexhacker on 6/16/21.
//

#ifndef LEETCODE_INTEGER_TO_ROMAN_H
#define LEETCODE_INTEGER_TO_ROMAN_H

#include <iostream>
#include <vector>

using namespace std;

namespace integer_to_roman {
    class Solution {
    public:
        string intToRoman(int num);
        void test();

    private:
        vector<vector<string>> r {
                {"I", "V", "X"},
                {"X", "L", "C"},
                {"C", "D", "M"},
                {"M"}
        };
    };
}

#endif //LEETCODE_INTEGER_TO_ROMAN_H
