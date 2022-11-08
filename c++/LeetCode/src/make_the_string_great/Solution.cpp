//
// Created by dexhacker on 11/8/22.
//

#include "Solution.h"
#include <stack>
#include <cassert>

string make_the_string_great::Solution::makeGood(std::string s) {
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (!st.empty()) {
            if (st.top() - 'a' == s[i] - 'A' || st.top() - 'A' == s[i] - 'a') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        } else {
            st.push(s[i]);
        }
    }
    string answer;
    while(!st.empty()) {
        answer = st.top() + answer;
        st.pop();
    }
    return answer;
}

void make_the_string_great::Solution::test() {
    assert(makeGood("leEeetcode") == "leetcode");

    cout << "makeGood completed!" << endl;
}
