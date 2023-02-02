//
// Created by dexhacker on 2/2/23.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

bool verifying_an_alien_dictionary::Solution::isAlienSorted(vector<string> &words, string order) {
    unordered_map<char, int> m;
    for (int i = 0; i < order.size(); i++) m[order[i]] = i;
    string current_word = words[0];
    for (int i = 1; i < words.size(); i++) {
        for (int j = 0; j < current_word.size(); j++) {
            if (words[i].size() == j) return false;
            if (m[current_word[j]] > m[words[i][j]]) return false;
            if (m[current_word[j]] < m[words[i][j]]) break;
        }
        current_word = words[i];
    }

    return true;
}

void verifying_an_alien_dictionary::Solution::test() {
    vector<string> words {"hello","leetcode"};
    assert(isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz") == true);

    cout << "isAlienSorted completed!" << endl;
}
