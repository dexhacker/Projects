//
// Created by dexhacker on 7/10/21.
//

#include "Solution.h"
#include <cassert>

int longest_increasing_subsequence::Solution::lengthOfLIS(vector<int> &nums) {
    vector<int> res;
    for(int i : nums) {
        auto it = lower_bound(res.begin(), res.end(), i);
        if (it == res.end()) {
            res.push_back(i);
        } else {
            *it = i;
        }
    }
    return res.size();
}

void longest_increasing_subsequence::Solution::test() {
    vector<int> test {10, 9, 2, 5, 3, 7, 101, 18};
    assert(lengthOfLIS(test) == 4);

    cout << "lengthOfLIS completed!" << endl;
}
