//
// Created by dexhacker on 6/16/21.
//

#include "Solution.h"
#include <cassert>

string integer_to_roman::Solution::intToRoman(int num) {
    vector<int> nums;
    string str;
    while(num > 0) {
        nums.push_back(num % 10);
        num /= 10;
    }
    for (int i = 0; i < nums.size(); ++i) {
        string tmp;
        if (nums[i] == 0) {
            continue;
        } else if (nums[i] < 4) {
            for (int j = 0; j < nums[i]; ++j) {
                tmp += r[i][0];
            }
        } else if (nums[i] < 5) {
            tmp = r[i][0] + r[i][1];
        } else if (nums[i] < 9) {
            tmp += r[i][1];
            for (int j = 0; j < nums[i] - 5; ++j) {
                tmp += r[i][0];
            }
        } else {
            tmp = r[i][0] + r[i][2];
        }

        str = tmp + str;
    }
    return str;
}

void integer_to_roman::Solution::test() {
    assert(intToRoman(1994) == "MCMXCIV");

    cout << "intToRoman completed!" << endl;
}
