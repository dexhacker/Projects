//
// Created by dexhacker on 3/19/21.
//

#include "Solution.h"
#include <cassert>
#include <unordered_map>

string minimum_window_substring::Solution::minWindow(string s, string t) {
    if (t.size() > s.size()) return "";
    if (t == s) return t;

    unordered_map<char,int> target_map;

    for (int i = 0; i < t.size(); i++)
        target_map[t[i]]++;

    unordered_map<char,int> current_map;
    int l = 0, r = 0;
    int start_position = 0;
    int min_length = s.size();
    bool has_substring = false;
    current_map[s[r]]++;
    while (r < s.size()) {
        bool is_valid = true;
        for (auto const & [key, value] : target_map) {
            if (current_map[key] < value){
                is_valid = false;
                break;
            }
        }

        if (is_valid && min_length >= r - l + 1) {
            min_length = r - l + 1;
            start_position = l;
            has_substring = true;
        }

        if (is_valid) {
            current_map[s[l]]--;
            l++;
        } else {
            r++;
            if (r < s.size()) {
                current_map[s[r]]++;
            }
        }
    }
    return (has_substring) ? s.substr(start_position, min_length) : "";
}

void minimum_window_substring::Solution::test() {
    assert(minWindow("ADOBECODEBANC", "ABC") == "BANC");
    assert(minWindow("a", "a") == "a");
    assert(minWindow("a", "b") == "");
    assert(minWindow("abc", "ac") == "abc");

    cout << "minWindow completed!" << endl;
}
