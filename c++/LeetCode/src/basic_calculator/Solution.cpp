//
// Created by dexhacker on 11/21/22.
//

#include "Solution.h"
#include <cassert>

int basic_calculator::Solution::calculate(std::string s) {
    bool has_first_number = false;
    char prev = '#';
    int answer = 0;
    string number;
    while (i < s.size()) {
        if (s[i] == '(') {
            i++;
            number = to_string(calculate(s));
        }
        if (s[i] == ')') {
            i++;
            if (number != "") {
                if (has_first_number) {
                    if (prev == '+') {
                        answer += stoi(number);
                    } else {
                        answer += stoi(number) * -1;
                    }
                } else {
                    answer = stoi(number);
                    if (prev == '-') answer *= -1;
                }
            }
            return answer;
        }
        if (s[i] == ' ') {
            i++;
            continue;
        }
        if (s[i] == '+') {
            if (has_first_number) {
                if (prev == '+') {
                    answer += stoi(number);
                } else {
                    answer += stoi(number) * -1;
                }
            } else {
                if (number != "") answer = stoi(number);
                has_first_number = true;
            }
            prev = '+';
            number = "";
            i++;
            continue;
        }
        if (s[i] == '-') {
            if (has_first_number) {
                if (prev == '+') {
                    answer += stoi(number);
                } else {
                    answer += stoi(number) * -1;
                }
            } else {
                if (number != "") answer = stoi(number);
                has_first_number = true;
            }
            prev = '-';
            number = "";
            i++;
            continue;
        }

        number += s[i];
        i++;
    }

    if (number != "") {
        if (has_first_number) {
            if (prev == '+') {
                answer += stoi(number);
            } else {
                answer += stoi(number) * -1;
            }
        } else {
            answer = stoi(number);
            if (prev == '-') answer *= -1;
        }
    }

    return answer;
}

void basic_calculator::Solution::test() {
    assert(calculate("(1+(4+5+2)-3)+(6+8)") == 23);

    cout << "calculate completed!" << endl;
}
