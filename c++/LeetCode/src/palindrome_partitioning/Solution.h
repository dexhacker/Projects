//
// Created by Фарид Абдугалыев on 05.01.2022.
//

#ifndef LEETCODE_PALINDROME_PARTITIONING_H
#define LEETCODE_PALINDROME_PARTITIONING_H

#include <iostream>
#include <vector>

using namespace std;

namespace palindrome_partitioning {
    class Solution {
    public:
        bool isPalindrome(string s);
        void dfs(int index, vector<string> sub_answer);
        vector<vector<string>> partition(string s);
        void test();

    private:
        string str;
        vector<vector<string>> answer;
    };
}

#endif //LEETCODE_PALINDROME_PARTITIONING_H
