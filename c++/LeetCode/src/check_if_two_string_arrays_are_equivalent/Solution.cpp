//
// Created by dexhacker on 10/25/22.
//

#include "Solution.h"
#include <cassert>

bool check_if_two_string_arrays_are_equivalent::Solution::arrayStringsAreEqual(vector<std::string> &word1, vector<std::string> &word2) {
    string s1, s2;

    for (auto s : word1) s1 += s;
    for (auto s : word2) s2 += s;

    return s1 == s2;
}

void check_if_two_string_arrays_are_equivalent::Solution::test() {
    vector<string> test1 {"ab", "c"};
    vector<string> test2 {"a", "bc"};
    assert(arrayStringsAreEqual(test1, test2) == true);

    cout << "arrayStringsAreEqual completed!" << endl;
}
