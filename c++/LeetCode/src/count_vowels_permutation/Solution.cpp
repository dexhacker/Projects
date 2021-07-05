//
// Created by dexhacker on 7/5/21.
//

#include "Solution.h"
#include <unordered_map>
#include <vector>
#include <cassert>

int count_vowels_permutation::Solution::countVowelPermutation(int n) {
    const int MOD = 1e9 + 7;
    unordered_map<char, long> letters {
            {'a', 1},
            {'e', 1},
            {'i', 1},
            {'o', 1},
            {'u', 1}
    };

    unordered_map<char, vector<char>> char_map {
            {'a', {'e', 'i', 'u'}},
            {'e', {'a', 'i'}},
            {'i', {'e', 'o'}},
            {'o', {'i'}},
            {'u', {'i', 'o'}}
    };

    for (int i = 1; i < n; ++i) {
        unordered_map<char, long> new_letters {
                {'a', 0},
                {'e', 0},
                {'i', 0},
                {'o', 0},
                {'u', 0}
        };

        for (const auto& [key, value] : letters) {
            for (auto c : char_map[key]) {
                new_letters[c] += value;
                new_letters[c] = (new_letters[c] % MOD);
            }
        }

        letters = new_letters;
    }

    long answer = 0;
    for (const auto& [key, value] : letters) {
        answer += value;
    }

    return answer % MOD;
}

void count_vowels_permutation::Solution::test() {
    assert(countVowelPermutation(5) == 68);

    cout << "countVowelPermutation completed!" << endl;
}
