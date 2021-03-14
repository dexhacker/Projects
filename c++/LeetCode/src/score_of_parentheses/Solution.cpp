//
// Created by dexhacker on 3/12/21.
//

#include "Solution.h"
#include <cassert>
#include <vector>

void sum_numbers(vector<string>& array) {
    vector<string> temp;
    int sum = 0;

    for (auto & i : array) {
        if (i == "(") {
            if (sum != 0) temp.push_back(to_string(sum));
            temp.push_back(i);
            sum = 0;
        } else if (i == ")") {
            if (sum != 0) temp.push_back(to_string(sum));
            temp.push_back(i);
            sum = 0;
        } else {
            sum += stoi(i);
        }
    }
    if (sum != 0) temp.push_back(to_string(sum));
    array = temp;
}

void multiply_parentheses(vector<string>& array) {
    vector<string> temp;

    for (int i = 0; i < array.size(); i++) {
        if (i + 2 > array.size() || i + 1 > array.size()) {
            temp.push_back(array[i]);
            break;
        }

        if (array[i] == "(" && array[i + 2] == ")") {
            int num = stoi(array[i + 1]);
            string result = to_string(num * 2);
            temp.push_back(result);
            i += 2;
        } else {
            temp.push_back(array[i]);
        }
    }
    array = temp;
}

int score_of_parentheses::Solution::scoreOfParentheses(string S) {
    vector<string> array;

    for (int i = 0; i < S.size(); i++) {
        if (i + 1 >= S.size()) {
            array.emplace_back(string(1, S[i]));
            break;
        }

        if (S[i] == '(' && S[i + 1] == ')') {
            array.emplace_back("1");
            i++;
        } else {
            array.emplace_back(string(1, S[i]));
        }
    }

    while (array.size() > 1) {
        sum_numbers(array);
        multiply_parentheses(array);
    }

    return stoi(array[0]);
}

void score_of_parentheses::Solution::test() {
    assert(scoreOfParentheses("()") == 1);
    assert(scoreOfParentheses("(())") == 2);
    assert(scoreOfParentheses("()()") == 2);
    assert(scoreOfParentheses("(()(()))") == 6);

    cout << "scoreOfParentheses completed!" << endl;
}
