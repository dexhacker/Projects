//
// Created by dexhacker on 6/17/21.
//

#include "Solution.h"
#include <cassert>

string longest_common_prefix::Solution::longestCommonPrefix(vector<string> &strs) {
    string answer;

    for (int i = 0; i < 200; ++i) {
        if (strs[0].size() <= i) return answer;
        for (int j = 1; j < strs.size(); ++j) {
            if (strs[j].size() <= i) return answer;
            if (strs[j][i] != strs[0][i]) return answer;
        }
        answer += strs[0][i];
    }

    return answer;
}

void longest_common_prefix::Solution::test() {
    vector<string> test {"flower", "flow", "flight"};
    assert(longestCommonPrefix(test) == "fl");

    cout << "longestCommonPrefix completed!" << endl;
}
