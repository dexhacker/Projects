//
// Created by dexhacker on 6/6/21.
//

#include "Solution.h"
#include <cassert>

int minimum_number_of_flips_to_make_the_binary_string_alternating::Solution::minFlips(string s) {
    int n = s.size();
    s += s;
    string s1, s2;

    for(int i = 0; i < s.size(); i++) {
        s1 += i % 2 ? '0' : '1';
        s2 += i % 2 ? '1' : '0';
    }
    int ans1 = 0, ans2 = 0, ans = INT32_MAX;
    for(int i = 0; i < s.size(); i++) {
        if(s1[i] != s[i]) ++ans1;
        if(s2[i] != s[i]) ++ans2;
        if(i >= n) {
            if(s1[i - n] != s[i - n]) --ans1;
            if(s2[i - n] != s[i - n]) --ans2;
        }
        if(i >= n - 1)
            ans = min({ans1, ans2, ans});
    }
    return ans;
}

void minimum_number_of_flips_to_make_the_binary_string_alternating::Solution::test() {
    assert(minFlips("111000") == 2);

    cout << "minFlips completed!" << endl;
}
