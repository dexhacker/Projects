//
// Created by dexhacker on 6/2/21.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

vector<string> repeated_dna_sequences::Solution::findRepeatedDnaSequences(string s) {
    if (s.size() < 11) return {};

    vector<string> answer;
    unordered_map<string, int> hm;
    for (int i = 0; i < s.size() - 9; i++) {
        string current_str = s.substr(i, 10);
        if (hm.count(current_str) > 0) {
            if (hm[current_str] == 1) answer.push_back(current_str);
            hm[current_str]++;
        }
        if (hm.count(current_str) == 0) hm[current_str] = 1;

    }
    return answer;
}

void repeated_dna_sequences::Solution::test() {
    vector<string> answer {"AAAAACCCCC", "CCCCCAAAAA"};
    assert(findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT") == answer);

    cout << "findRepeatedDnaSequences completed!" << endl;
}
