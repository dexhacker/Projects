//
// Created by dexhacker on 3/10/21.
//

#include "Solution.h"
#include <cassert>

void reverse_string::Solution::reverseString(vector<char>& s) {
    int l = 0, r = s.size() - 1;

    while (l < r) {
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;

        l++;
        r--;
    }
}

void reverse_string::Solution::test() {
    vector<char> s1 {'h', 'e', 'l', 'l', 'o'};
    vector<char> reversed1 {'o', 'l', 'l', 'e', 'h'};
    reverseString(s1);
    assert(s1 == reversed1);

    vector<char> s2 {'H', 'a', 'n', 'n', 'a', 'h'};
    vector<char> reversed2 {'h', 'a', 'n', 'n', 'a', 'H'};
    reverseString(s2);
    assert(s2 == reversed2);

    cout << "reverseString completed!" << endl;
}
