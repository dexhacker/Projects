//
// Created by Фарид Абдугалыев on 10.10.2022.
//

#ifndef LEETCODE_BREAK_A_PALINDROME_H
#define LEETCODE_BREAK_A_PALINDROME_H

#include <iostream>

using namespace std;

namespace break_a_palindrome {
    class Solution {
    public:
        string to_a(string palindrome);
        string breakPalindrome(string palindrome);
        void test();
    };
}

#endif //LEETCODE_BREAK_A_PALINDROME_H
