//
// Created by Фарид Абдугалыев on 22.12.2021.
//

#include "Solution.h"
#include <cmath>
#include <cassert>

int numbers_at_most_n_given_digit_set::Solution::atMostNGivenDigitSet(vector<string> &digits, int n) {
    string max_str = "";

    while (stol(max_str + digits[0]) <= n) {
        max_str += digits[0];
    }

    for (int i = 0; i < max_str.size(); i++) {
        for (int j = 0; j < digits.size(); j++) {
            string temp = max_str;
            temp[i] = digits[j][0];

            if (stol(temp) <= n) {
                max_str = temp;
            } else {
                break;
            }
        }
    }

    int answer = 0;

    for (int i = max_str.size() - 1; i >= 0; i--) {
        int count = 0;
        for (int j = 0; j < digits.size(); j++) {

            if ((max_str[i] - '0') >= stoi(digits[j])) {
                count++;
            } else {
                break;
            }
        }
        int multy = pow(digits.size(), max_str.size() - 1 - i);
        answer += count * multy;
    }

    return answer;
}

void numbers_at_most_n_given_digit_set::Solution::test() {
    vector<string> test1 {"1", "3", "5", "7"};
    assert(atMostNGivenDigitSet(test1, 100) == 20);

    vector<string> test2 {"1", "4", "9"};
    assert(atMostNGivenDigitSet(test2, 1000000000) == 29523);

    vector<string> test3 {"7"};
    assert(atMostNGivenDigitSet(test3, 8) == 1);

    cout << "atMostNGivenDigitSet completed!" << endl;
}
