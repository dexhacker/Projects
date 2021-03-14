//
// Created by dexhacker on 3/13/21.
//

#include "Solution.h"
#include <cassert>

vector<bool> can_make_palindrome_from_substring::Solution::canMakePaliQueries(string s, vector<vector<int>> &queries) {
    vector<bool> answer;

    vector<vector<int>> prefix;
    vector<int> tmp(26,0);
    prefix.push_back(tmp);

    for (int i = 0; i < s.size(); i++) {
        tmp[s[i] - 'a']++;
        prefix.push_back(tmp);
    }

    for (int i = 0; i < queries.size(); i++) {
        int finish = queries[i][1];
        int start = queries[i][0];
        if (finish - start < 1) {
            answer.push_back(true);
            continue;
        }

        int odd_count = 0;
        for (int j = 0; j < 26; j++) {
            int finish_odd_count = prefix[finish + 1][j];
            int start_odd_count = prefix[start][j];
            if ((finish_odd_count - start_odd_count) % 2 != 0) {
                odd_count++;
            }
        }

        int attempt = queries[i][2] * 2;
        if (finish - start % 2 != 0) attempt++;
        answer.push_back(attempt >= odd_count);
    }

    return answer;
}

void can_make_palindrome_from_substring::Solution::test() {
    vector<vector<int>> test1 {{3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};
    vector<bool> answer1 {true, false, false, true, true};
    vector<bool> result1 = canMakePaliQueries("abcda", test1);

    assert(result1 == answer1);

    vector<vector<int>> test2 {{1, 1, 1}, {2, 3, 0}, {3, 3, 1}, {0, 3, 2}, {1, 3, 3}, {2, 3, 1}, {3, 3, 1}, {0, 3, 0}, {1, 1, 1}, {2, 3, 0}, {3, 3, 1}, {0, 3, 1}, {1, 1, 1}};
    vector<bool> answer2 {true, false, true, true, true, true, true, false, true, false, true, true, true};
    vector<bool> result2 = canMakePaliQueries("hunu", test2);

    assert(result2 == answer2);

    vector<vector<int>> test3 {{1, 14, 5}, {14, 15, 1}, {15, 15, 1}};
    vector<bool> answer3 {true, true, true};
    vector<bool> result3 = canMakePaliQueries("pqtadspgvinafefk", test3);

    assert(result3 == answer3);

    vector<vector<int>> test4 {{5, 8, 0}, {7, 9, 1}, {3, 6, 4}, {5, 5, 1}, {8, 10, 0}, {3, 9, 5}, {0, 10, 10}, {6, 8, 3}};
    vector<bool> answer4 {false, true, true, true, false, true, true, true};
    vector<bool> result4 = canMakePaliQueries("rkzavgdmdgt", test4);

    assert(result4 == answer4);

    cout << "canMakePaliQueries completed!" << endl;
}