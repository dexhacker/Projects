//
// Created by Фарид Абдугалыев on 29.12.2021.
//

#include "Solution.h"
#include <stack>
#include <cassert>

int longest_valid_parentheses::Solution::longestValidParentheses(string s) {
    int answer = 0;
    stack<int> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (st.empty() || s[st.top()] == ')') {
                st.push(i);
            } else {
                st.pop();
                int index = -1;
                if (!st.empty()) index = st.top();
                answer = max(answer, i - index);
            }
        }
    }

    return answer;
}

void longest_valid_parentheses::Solution::test() {
    assert(longestValidParentheses("(()") == 2);
    assert(longestValidParentheses(")()())") == 4);
    assert(longestValidParentheses("") == 0);

    cout << "longestValidParentheses completed!" << endl;
}
