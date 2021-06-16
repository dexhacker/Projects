//
// Created by dexhacker on 3/17/21.
//

#include "Solution.h"
#include <cassert>

bool valid_palindrome::Solution::isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        char l = s[left];
        char r = s[right];
        if (l < 48 || (l > 57 && l < 65) || (l > 90 && l < 97) || l > 122) {
            left++;
            continue;
        }

        if (r < 48 || (r > 57 && r < 65) || (r > 90 && r < 97) || r > 122) {
            right--;
            continue;
        }

        if (((l > 64 && l < 91) || (l > 96 && l < 123))) {
            l = (l < 97) ? l - 'A' + 'a' : l;
        }

        if (((r > 64 && r < 91) || (r > 96 && r < 123))) {
            r = (r < 97) ? r - 'A' + 'a' : r;
        }

        if (l != r) return false;
        left++; right--;
    }
    return true;
}

void valid_palindrome::Solution::test() {
    assert(isPalindrome("A man, a plan, a canal: Panama") == true);
    assert(isPalindrome("race a car") == false);
    assert(isPalindrome("0P") == false);
    assert(isPalindrome("ab_a") == true);
    assert(isPalindrome("Marge, let's \"[went].\" I await {news} telegram.") == true);

    cout << "isPalindrome completed!" << endl;
}
