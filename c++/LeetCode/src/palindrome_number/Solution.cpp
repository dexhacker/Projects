//
// Created by dexhacker on 6/9/21.
//

#include "Solution.h"
#include <vector>
#include <cassert>

bool palindrome_number::Solution::isPalindrome(int x) {
    if (x < 0) return false;

    vector<int> numbers;
    while (x > 0) {
        numbers.push_back(x % 10);
        x /= 10;
    }
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
        if (numbers[l] != numbers[r]) return false;

        l++;
        r--;
    }
    return true;
}

void palindrome_number::Solution::test() {
    assert(isPalindrome(121) == true);

    cout << "isPalindrome completed!" << endl;
}
