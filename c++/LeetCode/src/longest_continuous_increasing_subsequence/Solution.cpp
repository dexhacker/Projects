//
// Created by dexhacker on 3/17/21.
//

#include "Solution.h"
#include <cassert>

int longest_continuous_increasing_subsequence::Solution::findLengthOfLCIS(vector<int> &nums) {
    if (nums.empty()) return 0;

    int ans = 1;
    int count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] < nums[i])
            count++;
        else
            count = 1;

        if (count > ans) ans = count;
    }
    return ans;
}

void longest_continuous_increasing_subsequence::Solution::test() {
    vector<int> test1 {1, 3, 5, 4, 7};
    assert(findLengthOfLCIS(test1) == 3);

    vector<int> test2 {2, 2, 2, 2, 2};
    assert(findLengthOfLCIS(test2) == 1);

    vector<int> test3 {1, 3, 5, 7};
    assert(findLengthOfLCIS(test3) == 4);

    vector<int> test4 {};
    assert(findLengthOfLCIS(test4) == 0);

    vector<int> test5 {1, 2, 5, 8, 0};
    assert(findLengthOfLCIS(test5) == 4);

    cout << "findLengthOfLCIS completed!" << endl;
}
