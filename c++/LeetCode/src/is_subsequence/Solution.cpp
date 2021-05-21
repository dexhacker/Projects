//
// Created by dexhacker on 4/29/21.
//

#include "Solution.h"
#include <cassert>

bool is_subsequence::Solution::isSubsequence(string s, string t) {
    if (s.empty() || s == t) return true;

    int l = 0, r = 0;
    while (r < t.size()) {
        if (s[l] == t[r]) l++;
        if (l == s.size()) return true;
        r++;
    }

    return false;
}

void is_subsequence::Solution::test() {
    assert(isSubsequence("abc", "ahbgdc") == true);
    assert(isSubsequence("axc", "ahbgdc") == false);
    assert(isSubsequence("", "") == true);
    assert(isSubsequence("", "w") == true);

    cout << "isSubsequence completed!" << endl;
}