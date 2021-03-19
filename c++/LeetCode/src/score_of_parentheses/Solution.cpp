//
// Created by dexhacker on 3/12/21.
//

#include "Solution.h"
#include <cassert>

int score_of_parentheses::Solution::scoreOfParentheses(string S) {
    if (S == "()") return 1;

    int balance = 0;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(')
            balance++;
        else if (S[i] == ')')
            balance--;

        if (balance == 0 && i != S.length() - 1) {
            string left = S.substr(0, i + 1);
            string right = S.substr(i + 1, S.size() - i + 1);
            return scoreOfParentheses(left) + scoreOfParentheses(right);
        }
    }
    return 2 * scoreOfParentheses(S.substr(1, S.size() - 2));
}

void score_of_parentheses::Solution::test() {
    assert(scoreOfParentheses("()") == 1);
    assert(scoreOfParentheses("(())") == 2);
    assert(scoreOfParentheses("()()") == 2);
    assert(scoreOfParentheses("(()(()))") == 6);

    cout << "scoreOfParentheses completed!" << endl;
}
