//
// Created by dexhacker on 7/15/21.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

string custom_sort_string::Solution::customSortString(string order, string str) {
    unordered_map<char, int> letters;

    for (auto c : order) letters[c] = 0;

    string other_letters;
    for (auto c : str) {
        if (letters.count(c) > 0) {
            ++letters[c];
        } else {
            other_letters += c;
        }
    }

    string answer;
    for (auto c : order) {
        for (int i = 0; i < letters[c]; ++i) {
            answer += c;
        }
    }
    return answer + other_letters;
}

void custom_sort_string::Solution::test() {
    assert(customSortString("cba", "abcd") == "cbad");

    cout << "customSortString completed!" << endl;
}
