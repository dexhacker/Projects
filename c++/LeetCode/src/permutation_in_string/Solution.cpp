//
// Created by dexhacker on 3/18/21.
//

#include "Solution.h"
#include <cassert>
#include <vector>

bool permutation_in_string::Solution::checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;

    vector<int> target(26, 0);
    vector<int> current(26, 0);

    for (int i = 0; i < s1.size(); i++) {
        target[s1[i] - 'a']++;
        current[s2[i] - 'a']++;
    }

    int l = 0, r = s1.size() - 1;
    while (r < s2.size()) {
        bool is_find = true;
        for (int i = 0; i < target.size(); i++) {
            if (target[i] != current[i]) {
                is_find = false;
            }
        }
        if (is_find) return true;

        if (r + 1 >= s2.size()) break;

        current[s2[l] - 'a']--;
        l++;r++;
        current[s2[r] - 'a']++;
    }
    return false;
}

void permutation_in_string::Solution::test() {
    assert(checkInclusion("ab", "eidbaooo") == true);
    assert(checkInclusion("ab", "eidboaoo") == false);
    assert(checkInclusion("ab", "a") == false);

    std::cout << "checkInclusion completed!" << std::endl;
}
