//
// Created by dexhacker on 11/3/22.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

int longest_palindrome_by_concatenating_two_letter_words::Solution::longestPalindrome(vector<std::string> &words) {
    unordered_map<string, int> m;
    int length = 0;
    for (auto w : words) {
        string r = string() + w[1] + w[0];
        if (m.count(r) > 0 && m[r] > 0) {
            length += 4;
            m[r]--;
            continue;
        }

        m[w]++;
    }

    for (auto p : m) {
        if (p.first[0] == p.first[1] && p.second > 0) {
            length += 2;
            break;
        }
    }

    return length;
}

void longest_palindrome_by_concatenating_two_letter_words::Solution::test() {
    vector<string> test {"ab", "ty", "yt", "lc", "cl", "ab"};
    assert(longestPalindrome(test) == 8);

    cout << "longestPalindrome completed!" << endl;
}
