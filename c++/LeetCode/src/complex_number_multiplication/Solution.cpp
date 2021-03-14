//
// Created by dexhacker on 3/12/21.
//

#include "Solution.h"
#include <cassert>

string complex_number_multiplication::Solution::complexNumberMultiply(string a, string b) {
    string a_first, a_second, b_first, b_second;
    bool second = false;
    for (char i : a) {
        if (i == '+') {
            second = true;
            continue;
        }

        if (i == 'i') break;

        if (second) {
            a_second += i;
        } else {
            a_first += i;
        }
    }

    second = false;
    for (char i : b) {
        if (i == '+') {
            second = true;
            continue;
        }

        if (i == 'i') break;

        if (second) {
            b_second += i;
        } else {
            b_first += i;
        }
    }

    int a_f = stoi(a_first);
    int a_s = stoi(a_second);
    int b_f = stoi(b_first);
    int b_s = stoi(b_second);

    int ans_1 = a_f * b_f;
    int ans_2 = a_f * b_s + a_s * b_f;
    int ans_3 = a_s * b_s * (-1);
    int ans_4 = ans_1 + ans_3;

    return to_string(ans_4) + "+" + to_string(ans_2) + "i";
}

void complex_number_multiplication::Solution::test() {
    assert(complexNumberMultiply("1+1i", "1+1i") == "0+2i");
    assert(complexNumberMultiply("1+-1i", "1+-1i") == "0+-2i");

    cout << "complexNumberMultiply completed!" << endl;
}
