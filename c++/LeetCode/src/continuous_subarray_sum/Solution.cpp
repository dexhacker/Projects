//
// Created by dexhacker on 10/26/22.
//

#include "Solution.h"
#include <unordered_map>
#include <cassert>

bool continuous_subarray_sum::Solution::checkSubarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> hashMap{{0, 0}};
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (!hashMap.count(sum % k))
            hashMap[sum % k] = i + 1;
        else if (hashMap[sum % k] < i)
            return true;
    }
    return false;
}

void continuous_subarray_sum::Solution::test() {
    vector<int> test {23, 2, 4, 6, 7};
    assert(checkSubarraySum(test, 6) == true);

    cout << "checkSubarraySum completed!" << endl;
}
