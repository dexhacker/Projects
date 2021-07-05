//
// Created by dexhacker on 7/1/21.
//

#ifndef LEETCODE_GRAY_CODE_H
#define LEETCODE_GRAY_CODE_H

#include <iostream>
#include <vector>

using namespace std;

namespace gray_code {
    class Solution {
    public:
        int fillAnswer(int n, int number);
        vector<int> grayCode(int n);
        void test();

    private:
        vector<int> answer;
    };
}

#endif //LEETCODE_GRAY_CODE_H
