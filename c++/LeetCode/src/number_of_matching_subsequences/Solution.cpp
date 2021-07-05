//
// Created by dexhacker on 6/22/21.
//

#include "Solution.h"
#include <cassert>

int number_of_matching_subsequences::Solution::numMatchingSubseq(string s, vector<string> &words) {
    vector<vector<int>> char_indexes(26);
    for (int i = 0; i < s.size(); ++i) char_indexes[s[i] - 'a'].push_back(i);

    int answer = 0;
    for (auto str : words) {
        int min_index = -1;
        bool isSubsequence = true;
        for (char letter : str) {
            bool isFind = false;
            for (auto index : char_indexes[letter - 'a']) {
                if (index > min_index) {
                    min_index = index;
                    isFind = true;
                    break;
                }
            }
            if (!isFind) {
                isSubsequence = false;
                break;
            }
        }
        if (isSubsequence) answer++;
    }

    return answer;
}

void number_of_matching_subsequences::Solution::test() {
    vector<string> test {"a", "bb", "acd", "ace"};
    assert(numMatchingSubseq("abcde", test) == 3);

    cout << "numMatchingSubseq completed!" << endl;
}
