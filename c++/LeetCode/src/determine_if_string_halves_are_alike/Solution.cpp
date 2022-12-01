//
// Created by dexhacker on 12/1/22.
//

#include "Solution.h"
#include <cassert>

bool determine_if_string_halves_are_alike::Solution::isVowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool determine_if_string_halves_are_alike::Solution::halvesAreAlike(string s) {
    int l = 0, r = s.size() - 1, s1 = 0, s2 = 0;
    while (l < r) {
        if (isVowel(s[l])) s1++;
        if (isVowel(s[r])) s2++;
        l++;
        r--;
    }
    return s1 == s2;
}

void determine_if_string_halves_are_alike::Solution::test() {
    assert(halvesAreAlike("book") == true);

    cout << "halvesAreAlike completed!" << endl;
}
