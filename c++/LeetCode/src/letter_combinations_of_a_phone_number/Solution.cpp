//
// Created by dexhacker on 5/19/21.
//

#include "Solution.h"
#include "unordered_map"
#include <cassert>

vector<string> letter_combinations_of_a_phone_number::Solution::letterCombinations(string digits) {
    unordered_map<char, string> letters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };

    vector<string> list {""};
    vector<string> empty {};

    for (char & digit : digits) {
        auto values = letters[digit];
        vector<string> prev_list;
        copy(list.begin(), list.end(), back_inserter(prev_list));

        list = {};
        for (char & value : values)
            for (string & str : prev_list)
                list.push_back(str + value);
    }

    return (list[0].empty()) ? empty : list;
}

void letter_combinations_of_a_phone_number::Solution::test() {
    vector<string> test1 {"ad", "bd", "cd", "ae", "be", "ce", "af", "bf", "cf"};
    assert(letterCombinations("23") == test1);

    vector<string> test2 {};
    assert(letterCombinations("") == test2);

    vector<string> test3 {"a", "b", "c"};
    assert(letterCombinations("2") == test3);

    cout << "letterCombinations completed!" << endl;
}
