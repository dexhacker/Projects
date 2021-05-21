//
// Created by dexhacker on 3/24/21.
//

#include "Solution.h"
#include <stack>
#include <cassert>

bool valid_parentheses::Solution::isValid(string s) {
    stack<char> char_stack;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
            char_stack.push(c);
        if (c == ')' || c == ']' || c == '}') {
            if (char_stack.empty()) return false;

            char current = char_stack.top();
            if (current == '(' && c == ')') {
                char_stack.pop();
                continue;
            }
            if (current == '[' && c == ']') {
                char_stack.pop();
                continue;
            }
            if (current == '{' && c == '}') {
                char_stack.pop();
                continue;
            }
            return false;
        }
    }
    return char_stack.empty();
}

void valid_parentheses::Solution::test() {
    assert(isValid("()") == true);
    assert(isValid("()[]{}") == true);
    assert(isValid("(]") == false);
    assert(isValid("([)]") == false);
    assert(isValid("{[]}") == true);
    assert(isValid("[") == false);
    assert(isValid("]") == false);

    cout << "isValid completed!" << endl;
}
