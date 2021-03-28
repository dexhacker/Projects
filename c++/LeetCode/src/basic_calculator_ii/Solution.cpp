//
// Created by dexhacker on 3/25/21.
//

#include "Solution.h"
#include <vector>
#include <cassert>

int basic_calculator_ii::Solution::calculate(string s) {
    vector<string> expressions;
    string current_string;
    bool number;
    int answer;
    for (char c : s) {
        if (c > 47 && c < 58) {
            if (number) {
                current_string += c;
            } else {
                number = true;
                current_string = c;
            }
        }
        if (c == 43 || c == 45 || c == 42 || c == 47) {
            expressions.push_back(current_string);
            number = false;
            current_string = c;
            expressions.push_back(current_string);
        }
    }
    expressions.push_back(current_string);

    vector<string> expressions2;
    for (int i = 0; i < expressions.size(); i++) {
        if (expressions[i] == "*") {
            int first = stoi(expressions2[expressions2.size() - 1]);
            int second = stoi(expressions[i + 1]);
            expressions2[expressions2.size() - 1] = to_string(first * second);
            i++;
            continue;
        }
        if (expressions[i] == "/") {
            int first = stoi(expressions2[expressions2.size() - 1]);
            int second = stoi(expressions[i + 1]);
            expressions2[expressions2.size() - 1] = to_string(first / second);
            i++;
            continue;
        }
        expressions2.push_back(expressions[i]);
    }

    answer = stoi(expressions2[0]);
    for (int i = 1; i < expressions2.size(); i++) {
        if (expressions2[i] == "+") {
            answer += stoi(expressions2[i + 1]);
            i++;
            continue;
        }
        if (expressions2[i] == "-") {
            answer -= stoi(expressions2[i + 1]);
            i++;
            continue;
        }
    }

    return answer;
}

void basic_calculator_ii::Solution::test() {
    assert(calculate("3+2*2") == 7);
    assert(calculate(" 3/2 ") == 1);
    assert(calculate(" 3+5 / 2 ") == 5);

    cout << "calculate completed!" << endl;
}
