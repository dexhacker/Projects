//
// Created by dexhacker on 9/26/22.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

bool satisfiability_of_equality_equations::Solution::equationsPossible(vector<std::string> &equations) {
    unordered_map<char, int> m;
    int index = 0;

    for (int i = 0; i < equations.size(); i++) {
        char c1 = equations[i][0];
        char c2 = equations[i][3];
        char c3 = equations[i][1];

        if (c3 == '=') {
            if (m.count(c1) == 0 && m.count(c2) == 0) {
                m[c1] = index;
                m[c2] = index;
                index++;
            }

            if (m.count(c2) == 0) m[c2] = m[c1];
            if (m.count(c1) == 0) m[c1] = m[c2];

            index++;

            for (int j = i + 1; j < equations.size(); j++) {
                char c21 = equations[j][0];
                char c22 = equations[j][3];
                char c23 = equations[j][1];

                if (c23 == '=') {
                    if (c21 == c1) m[c22] = m[c1];
                    if (c21 == c2) m[c22] = m[c2];
                    if (c22 == c1) m[c21] = m[c1];
                    if (c22 == c2) m[c21] = m[c2];
                }
            }
        }
    }

    for (int i = 0; i < equations.size(); i++) {
        char c1 = equations[i][0];
        char c2 = equations[i][3];
        char c3 = equations[i][1];

        if (c3 == '!') {
            if (m.count(c1) == 0) {
                m[c1] = index;
                index++;
            }

            if (m.count(c2) == 0) {
                m[c2] = index;
                index++;
            }

            if (m[c1] == m[c2]) return false;
        }
    }

    return true;
}

void satisfiability_of_equality_equations::Solution::test() {
    vector<string> test {"a==b", "b!=a"};
    assert(equationsPossible(test) == false);

    cout << "equationsPossible completed!" << endl;
}
