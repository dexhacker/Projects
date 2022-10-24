//
// Created by dexhacker on 10/24/22.
//

#include "Solution.h"
#include <cassert>

vector<int> set_mismatch::Solution::findErrorNums(vector<int> &nums) {
    vector<bool> v(nums.size(), false);
    vector<int> answer(2, 0);

    int prev = 0;
    for (int i : nums) {
        if (prev == i) answer[0] = i;
        if (v[i - 1]) answer[0] = i;
        v[i - 1] = true;
        prev = i;
    }

    for (int i = 0; i < v.size(); i++) if (!v[i]) answer[1] = i + 1;

    return answer;
}

void set_mismatch::Solution::test() {
    vector<int> test {1, 2, 2, 4};
    vector<int> answer {2, 3};
    assert(findErrorNums(test) == answer);

    cout << "findErrorNums completed!" << endl;
}
