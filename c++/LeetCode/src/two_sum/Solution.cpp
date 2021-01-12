//
// Created by dexhacker on 1/12/21.
//

#include "Solution.h"
#include <cassert>
#include <map>

vector<int> two_sum::Solution::twoSum(vector<int> &nums, int target) {
    vector<int> result;
    map<int, int> numsMap;
    for (int i = 0; i < nums.size(); i++) {
        if (numsMap.find(nums[i]) == numsMap.end()) {
            numsMap[target - nums[i]] = i;
        } else {
            result.push_back(numsMap[nums[i]]);
            result.push_back(i);
        }
    }
    return result;
}

void two_sum::Solution::test() {
    vector<int> nums1 {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 {0, 1};
    assert(twoSum(nums1, target1) == result1);

    vector<int> nums2 {3,2,4};
    int target2 = 6;
    vector<int> result2 {1, 2};
    assert(twoSum(nums2, target2) == result2);

    vector<int> nums3 {3,3};
    int target3 = 6;
    vector<int> result3 {0, 1};
    assert(twoSum(nums3, target3) == result3);

    std::cout << "twoSum completed!" << std::endl;
}
