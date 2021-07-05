//
// Created by dexhacker on 6/17/21.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

int roman_to_integer::Solution::romanToInt(string s) {
    unordered_map<char, int> roman {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };

    int answer = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i + 1 < s.size() and roman[s[i]] < roman[s[i + 1]]) {
            answer -= roman[s[i]];
        } else {
            answer += roman[s[i]];
        }
    }

    return answer;
}

void roman_to_integer::Solution::test() {
    assert(romanToInt("MCMXCIV") == 1994);

    cout << "romanToInt completed!" << endl;
}
