//
// Created by Фарид Абдугалыев on 17.12.2021.
//

#include "Solution.h"
#include <cassert>

int implement_strstr::Solution::strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;

    for (int i = 0; i <= (int)haystack.size() - (int)needle.size(); i++) {
        bool is_equal = true;
        for (int j = 0; j < needle.size(); j++) {
            if (haystack[i + j] != needle[j]) {
                is_equal = false;
                break;
            }
        }
        if (is_equal) return i;
    }

    return -1;
}

void implement_strstr::Solution::test() {
    assert(strStr("hello", "ll") == 2);
    assert(strStr("aaaaa", "bba") == -1);
    assert(strStr("", "") == 0);

    cout << "strStr completed!" << endl;
}
