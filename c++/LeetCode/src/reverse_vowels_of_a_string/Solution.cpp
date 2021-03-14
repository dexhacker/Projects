//
// Created by dexhacker on 3/10/21.
//

#include "Solution.h"
#include <cassert>

bool isVowel(char letter) {
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U');
}

string reverse_vowels_of_a_string::Solution::reverseVowels(string s) {
    int l = 0, r = s.size() - 1;

    while (l < r) {
        if (!isVowel(s[l])) {
            l++;
            continue;
        }

        if (!isVowel(s[r])) {
            r--;
            continue;
        }

        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;

        l++;
        r--;
    }
    return s;
}

void reverse_vowels_of_a_string::Solution::test() {
    assert("hello" == reverseVowels("holle"));
    assert("leetcode" == reverseVowels("leotcede"));
    assert("aA" == reverseVowels("Aa"));

    cout << "reverseVowels completed!" << endl;
}
