//
// Created by dexhacker on 6/4/21.
//

#ifndef LEETCODE_OPEN_THE_LOCK_H
#define LEETCODE_OPEN_THE_LOCK_H

#include <iostream>
#include <vector>

using namespace std;

namespace open_the_lock {
    class Solution {
    public:
        string modify(string s, int pos, string direction);
        int openLock(vector<string>& deadends, string target);
        void test();
    };
}

#endif //LEETCODE_OPEN_THE_LOCK_H
