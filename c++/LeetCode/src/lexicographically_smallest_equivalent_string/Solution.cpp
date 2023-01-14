//
// Created by dexhacker on 1/14/23.
//

#include "Solution.h"
#include <vector>
#include <cassert>

string lexicographically_smallest_equivalent_string::Solution::smallestEquivalentString(string s1, string s2, string baseStr) {
    vector<vector<int>> arrays;
    vector<int> letterToArrays(26, -1);
    for (int i = 0; i < s1.size(); i++) {
        if (letterToArrays[s1[i] - 'a'] >= 0 && letterToArrays[s2[i] - 'a'] >= 0) {
            int index_s1 = letterToArrays[s1[i] - 'a'];
            int index_s2 = letterToArrays[s2[i] - 'a'];

            if (index_s1 == index_s2) continue;

            for (int j : arrays[index_s2]) {
                arrays[index_s1].push_back(j);
                letterToArrays[j] = index_s1;
            }

            arrays[index_s2].clear();
            continue;
        }

        if (letterToArrays[s1[i] - 'a'] >= 0) {
            int index_s1 = letterToArrays[s1[i] - 'a'];
            arrays[index_s1].push_back(s2[i] - 'a');
            letterToArrays[s2[i] - 'a'] = index_s1;
            continue;
        }

        if (letterToArrays[s2[i] - 'a'] >= 0) {
            int index_s2 = letterToArrays[s2[i] - 'a'];
            arrays[index_s2].push_back(s1[i] - 'a');
            letterToArrays[s1[i] - 'a'] = index_s2;
            continue;
        }

        arrays.push_back({s1[i] - 'a', s2[i] - 'a'});
        int index = arrays.size() - 1;
        letterToArrays[s1[i] - 'a'] = index;
        letterToArrays[s2[i] - 'a'] = index;
    }

    for (int i = 0; i < arrays.size(); i++) {
        auto v = arrays[i];
        sort(v.begin(), v.end());
        arrays[i] = v;
    }

    string answer;
    for (char c : baseStr) {
        if (letterToArrays[c - 'a'] >= 0) {
            answer.push_back(arrays[letterToArrays[c - 'a']][0] + 'a');
        } else {
            answer.push_back(c);
        }
    }

    return answer;
}

void lexicographically_smallest_equivalent_string::Solution::test() {
    assert(smallestEquivalentString("parker", "morris", "parser") == "makkek");

    cout << "smallestEquivalentString completed!" << endl;
}
