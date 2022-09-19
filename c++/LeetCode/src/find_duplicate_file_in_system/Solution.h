//
// Created by dexhacker on 9/19/22.
//

#ifndef LEETCODE_FIND_DUPLICATE_FILE_IN_SYSTEM_H
#define LEETCODE_FIND_DUPLICATE_FILE_IN_SYSTEM_H

#include <iostream>
#include <vector>

using namespace std;

namespace find_duplicate_file_in_system {
    class Solution {
    public:
        vector<vector<string>> findDuplicate(vector<string>& paths);
        void test();
    };
}

#endif //LEETCODE_FIND_DUPLICATE_FILE_IN_SYSTEM_H
