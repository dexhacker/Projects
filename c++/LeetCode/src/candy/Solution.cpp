//
// Created by dexhacker on 6/28/21.
//

#include "Solution.h"
#include <cassert>

int candy::Solution::candy(vector<int> &ratings) {
    int len = ratings.size(), res = 0, i;
    if (len > 0) {
        vector<int> number(len, 0);
        number[0] = 1;
        for(i = 1; i < len; ++i) number[i] = (ratings[i] > ratings[i - 1]) ? number[i - 1] + 1 : 1;

        for (i = len - 2, res = number[len - 1]; i >= 0; --i) {
            if ((ratings[i] > ratings[i + 1]) && number[i] < (number[i + 1] + 1)) number[i] = number[i + 1] + 1;
            res += number[i];
        }
    }
    return res;
}

void candy::Solution::test() {
    vector<int> test {1, 0, 2};
    assert(candy(test) == 5);

    cout << "candy completed!" << endl;
}
