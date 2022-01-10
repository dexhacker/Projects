//
// Created by Фарид Абдугалыев on 10.01.2022.
//

#include "Solution.h"
#include <cassert>

string add_binary::Solution::addBinary(string a, string b) {
    string result;

    int l = a.size() - 1;
    int r = b.size() - 1;

    int has_more_one = false;

    while (l >= 0 || r >= 0) {
        int first_number = 0;
        int second_number = 0;

        if (l >= 0) {
            first_number = a[l] - '0';
        }

        if (r >= 0) {
            second_number = b[r] - '0';
        }

        int result_number = first_number + second_number;

        if (has_more_one) {
            result_number++;
            has_more_one = false;
        }

        if (result_number > 1) {
            has_more_one = true;
            result_number -= 2;
        }

        result = to_string(result_number) + result;

        l--;
        r--;
    }

    if (has_more_one) result = "1" + result;

    return result;
}

void add_binary::Solution::test() {
    assert(addBinary("11", "1") == "100");
    assert(addBinary("1010", "1011") == "10101");

    cout << "addBinary completed!" << endl;
}
