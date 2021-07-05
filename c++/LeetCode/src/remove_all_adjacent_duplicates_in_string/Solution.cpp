//
// Created by dexhacker on 6/28/21.
//

#include "Solution.h"
#include <cassert>

string remove_all_adjacent_duplicates_in_string::Solution::removeDuplicates(string s) {
    string answer;

    for (int i = 0; i < s.size(); ++i) {
        if (!answer.empty() and answer.back() == s[i]) {
            answer.pop_back();
        } else {
            answer += s[i];
        }
    }

    return answer;
}

void remove_all_adjacent_duplicates_in_string::Solution::test() {
    assert(removeDuplicates("abbaca") == "ca");

    cout << "removeDuplicates completed!" << endl;
}
