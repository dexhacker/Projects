//
// Created by dexhacker on 2/1/23.
//

#include "Solution.h"
#include <cassert>

string greatest_common_divisor_of_strings::Solution::gcdOfStrings(string str1, string str2) {
    string min_str = (str2.size() < str1.size()) ? str2 : str1;
    string max_str = (min_str == str2) ? str1 : str2;

    for (int i = 1; i <= min_str.size(); i++) {
        if (min_str.size() % i == 0 && max_str.size() % (min_str.size() / i) == 0) {
            string sub = min_str.substr(0, min_str.size() / i);

            string sub1, sub2;
            while (sub2.size() < str2.size()) sub2 += sub;
            if (str2 != sub2) continue;

            while (sub1.size() < str1.size()) sub1 += sub;
            if (str1 != sub1) continue;

            return sub;
        }
    }

    return "";
}

void greatest_common_divisor_of_strings::Solution::test() {
    assert(gcdOfStrings("ABCABC", "ABC") == "ABC");

    cout << "gcdOfStrings completed!" << endl;
}
