//
// Created by dexhacker on 12/2/22.
//

#include "Solution.h"
#include <vector>
#include <cassert>

bool determine_if_two_strings_are_close::Solution::closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) return false;

    vector<int> word1_count(26, 0);
    vector<int> word2_count(26, 0);

    for (char c : word1) word1_count[c - 'a']++;
    for (char c : word2) word2_count[c - 'a']++;

    for (int i = 0; i < word1_count.size(); i++) {
        if (word1_count[i] > 0 && word2_count[i] == 0) return false;
        if (word1_count[i] == 0 && word2_count[i] > 0) return false;
    }

    vector<int> word1_used;
    vector<int> word2_used;

    for (int i : word1_count) word1_used.push_back(i);
    for (int i : word2_count) word2_used.push_back(i);

    if (word1_used.size() != word2_used.size()) return false;

    sort(word1_count.begin(), word1_count.end());
    sort(word2_count.begin(), word2_count.end());

    for (int i = 0; i< word1_used.size(); i++) if (word1_count[i] != word2_count[i]) return false;

    return true;
}

void determine_if_two_strings_are_close::Solution::test() {
    assert(closeStrings("abc", "bca") == true);

    cout << "closeStrings completed!" << endl;
}
