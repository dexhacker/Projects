//
// Created by dexhacker on 6/16/21.
//

#include "Solution.h"
#include <cassert>

void generate_parentheses::Solution::dfs(string s, int open, int close) {
    if (open == 0  and close == 0) {
        answer.push_back(s);
        return;
    }
    if (open > 0) dfs(s + '(', open - 1, close);
    if (open < close) dfs(s + ')', open, close - 1);
}

vector<string> generate_parentheses::Solution::generateParenthesis(int n) {
    dfs("", n, n);
    return answer;
}

void generate_parentheses::Solution::test() {
    vector<string> result {"((()))", "(()())", "(())()", "()(())", "()()()"};
    assert(generateParenthesis(3) == result);

    cout << "generateParenthesis completed!" << endl;
}
