//
// Created by Фарид Абдугалыев on 10.10.2022.
//

#include "Solution.h"
#include <cassert>

string break_a_palindrome::Solution::to_a(std::string palindrome) {
    int l = 0, r = palindrome.size() - 1;
    while (l < r) {
        if (palindrome[l] != 'a') {
            palindrome[l] = 'a';
            return palindrome;
        }

        l++;
        r--;
    }

    return "";
}

string break_a_palindrome::Solution::breakPalindrome(std::string palindrome) {
    if (palindrome.size() < 2) return "";

    string result = to_a(palindrome);
    if (!result.empty()) return result;

    palindrome[palindrome.size() - 1] = 'b';

    return palindrome;
}

void break_a_palindrome::Solution::test() {
    assert(breakPalindrome("abccba") == "aaccba");

    cout << "breakPalindrome completed!" << endl;
}
