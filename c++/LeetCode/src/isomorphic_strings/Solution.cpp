//
// Created by dexhacker on 3/10/21.
//

#include "Solution.h"
#include <cassert>
#include <vector>

bool isomorphic_strings::Solution::isIsomorphic(string s, string t) {
    vector<char> a(128);
    vector<char> b(128);

    for (int i = 0; i < s.length(); i++) {
        if (a[s[i]]) {
            if (a[s[i]] != t[i]) return false;
        } else if (b[t[i]]) {
            if (b[t[i]] != s[i]) return false;
        } else {
            a[s[i]] = t[i];
            b[t[i]] = s[i];
        }
    }
    return true;
}

void isomorphic_strings::Solution::test() {
    assert(isIsomorphic("egg", "add"));
    assert(!isIsomorphic("foo", "bar"));
    assert(isIsomorphic("paper", "title"));
    assert(!isIsomorphic("badc", "baba"));
    assert(isIsomorphic("13", "42"));

    cout << "isIsomorphic completed!" << endl;
}
