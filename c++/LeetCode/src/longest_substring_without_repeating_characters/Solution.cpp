//
// Created by dexhacker on 1/12/21.
//

#include "Solution.h"
#include <cassert>
#include <map>

int longest_substring_without_repeating_characters::Solution::lengthOfLongestSubstring(string s) {
    int ans = 0;
    int index[128] = {};

    for (int i = 0, j = 0; j < s.length(); j++) {
        i = (index[s.at(j)] > i) ? index[s.at(j)] : i;
        ans = (ans > j - i + 1) ? ans : j - i + 1;
        index[s.at(j)] = j + 1;
    }

    return ans;
}

void longest_substring_without_repeating_characters::Solution::test() {
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("bbbbb") == 1);
    assert(lengthOfLongestSubstring("pwwkew") == 3);
    assert(lengthOfLongestSubstring("") == 0);
    assert(lengthOfLongestSubstring(" ") == 1);
    assert(lengthOfLongestSubstring("au") == 2);
    assert(lengthOfLongestSubstring("aab") == 2);
    assert(lengthOfLongestSubstring("abba") == 2);
    assert(lengthOfLongestSubstring("dvdf") == 3);

    cout << "lengthOfLongestSubstring completed!" << endl;
}
