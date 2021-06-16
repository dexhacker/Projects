//
// Created by dexhacker on 6/8/21.
//

#include "Solution.h"
#include <cmath>
#include <cassert>

int string_to_integer_atoi::Solution::myAtoi(string s) {
    string tmp;
    bool negative = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-' and tmp.empty()) negative = true;
        if (s[i] > 47 and s[i] < 58) {
            tmp += s[i];
        } else {
            if (!tmp.empty()) break;
            if (s[i] == '+' and (s[i + 1] <= 47 or s[i + 1] >= 58)) break;
            if (s[i] == '-' and (s[i + 1] <= 47 or s[i + 1] >= 58)) break;
            if ((s[i] > 64 and s[i] < 91) or (s[i] > 96 and s[i] < 123) or s[i] == '.') break;
        }
    }
    if (tmp.size() == 0) return 0;

    string tmp_with_out_zero;
    bool number = false;
    for (char i : tmp) {
        if (i == '0' and !number) continue;
        number = true;
        tmp_with_out_zero += i;
    }
    tmp = tmp_with_out_zero;

    long long answer = 0;
    if (tmp.size() > 10) {
        return (negative) ? INT32_MIN : INT32_MAX;
    }

    for (int i = tmp.size() - 1; i >= 0; i--) {
        answer += (tmp[i] - '0') * pow(10, (tmp.size() - 1 - i));
    }
    if (negative) {
        if (-answer < INT32_MIN) return INT32_MIN;
        return -answer;
    } else {
        if (answer > INT32_MAX) return INT32_MAX;
        return answer;
    }
}

void string_to_integer_atoi::Solution::test() {
    assert(myAtoi("  0000000000012345678") == 12345678);

    cout << "myAtoi completed!" << endl;
}
