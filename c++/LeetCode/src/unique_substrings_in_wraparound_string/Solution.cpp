//
// Created by dexhacker on 4/30/21.
//

#include "Solution.h"
#include <cassert>
#include <unordered_map>

bool is_next(char a, char b) { return a == 'z' ? b == 'a' : a + 1 == b; }

int unique_substrings_in_wraparound_string::Solution::findSubstringInWraproundString(string p) {
    unordered_map<char, int> max_lengths;

    int max_length = 1;
    for (size_t i = 0; i < p.size(); i++) {
        if (max_lengths.find(p[i]) == max_lengths.end()) {
            max_lengths[p[i]] = max_length;
        } else {
            max_lengths[p[i]] = max(max_length, max_lengths[p[i]]);
        }

        if (i + 1 < p.size() && is_next(p[i], p[i + 1])) max_length++;
        else max_length = 1;
    }

    int res = 0;
    for (const auto & [key, value] : max_lengths) res += value;
    return res;
}

void unique_substrings_in_wraparound_string::Solution::test() {
    assert(findSubstringInWraproundString("a") == 1);
    assert(findSubstringInWraproundString("cac") == 2);
    assert(findSubstringInWraproundString("zab") == 6);
    assert(findSubstringInWraproundString("acfe") == 4);
    assert(findSubstringInWraproundString("bcdabcde") == 15);

    cout << "findSubstringInWraproundString completed!" << endl;
}
