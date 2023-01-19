//
// Created by dexhacker on 1/19/23.
//

#include "Solution.h"
#include <cassert>

int subarray_sums_divisible_by_k::Solution::subarraysDivByK(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> sums(k, 0);
    sums[0]++;
    int cnt = 0;
    int currSum = 0;
    for(int i = 0; i<n; i++) {
        currSum = (currSum + nums[i]%k + k)%k;
        cnt += sums[currSum];
        sums[currSum]++;
    }
    return cnt;
}

void subarray_sums_divisible_by_k::Solution::test() {
    vector<int> nums {4, 5, 0, -2, -3, 1};
    assert(subarraysDivByK(nums, 5) == 7);

    cout << "subarraysDivByK completed!" << endl;
}
