//
// Created by dexhacker on 12/18/22.
//

#include "Solution.h"
#include <stack>
#include <cassert>

int evaluate_reverse_polish_notation::Solution::evalRPN(vector<string> &tokens) {
    stack<long> st;
    for (auto i : tokens) {
        if (i != "+" && i != "-" && i != "*" && i != "/") {
            st.push(stoi(i));
            continue;
        }

        long b = st.top();
        st.pop();
        long a = st.top();
        st.pop();

        if (i == "+") st.push(a + b);
        else if (i == "-") st.push(a - b);
        else if (i == "*") st.push(a * b);
        else if (i == "/") st.push(a / b);
    }
    return st.top();
}

void evaluate_reverse_polish_notation::Solution::test() {
    vector<string> test {"2", "1", "+", "3", "*"};
    assert(evalRPN(test) == 9);

    cout << "evalRPN completed!" << endl;
}
