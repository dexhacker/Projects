//
// Created by dexhacker on 4/27/21.
//

#include "Solution.h"
#include <cassert>

int reverse_integer::Solution::reverse(int x) {
    string s = to_string(x);
    int l = 0, r = s.size() - 1;
    if (x < 0) l = 1;
    while (l < r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
    try {
        return stoi(s);
    } catch (const out_of_range& e) {
        return 0;
    }
}

void reverse_integer::Solution::test() {
    assert(reverse(123) == 321);
    assert(reverse(-123) == -321);
    assert(reverse(120) == 21);
    assert(reverse(0) == 0);

    cout << "reverse completed!" << endl;
}
