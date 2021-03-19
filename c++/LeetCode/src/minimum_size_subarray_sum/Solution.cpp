//
// Created by dexhacker on 3/17/21.
//

#include "Solution.h"
#include <cassert>

int minimum_size_subarray_sum::Solution::minSubArrayLen(int target, vector<int> &nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1 && nums[0] >= target) return 1;
    if (nums.size() == 1 && nums[0] < target) return 0;

    int l = 0;
    int r = 1;
    int answer = (nums[0] > target) ? 1 : nums.size();
    int sum = nums[0] + nums[1];
    bool has_sum = false;
    while (r < nums.size()) {
        if (sum >= target) {
            has_sum = true;
            if (answer > r - l + 1) answer = r - l + 1;
            sum -= nums[l];
            (l >= r) ? r++ : l++;
        } else {
            r++;
            if (r < nums.size()) sum += nums[r];
        }
    }
    return (has_sum) ? answer : 0;
}

void minimum_size_subarray_sum::Solution::test() {
    vector<int> test1 {2, 3, 1, 2, 4, 3};
    assert(minSubArrayLen(7, test1) == 2);

    vector<int> test2 {1, 4, 4};
    assert(minSubArrayLen(4, test2) == 1);

    vector<int> test3 {1, 1, 1, 1, 1, 1, 1, 1};
    assert(minSubArrayLen(11, test3) == 0);

    vector<int> test4 {5};
    assert(minSubArrayLen(7, test4) == 0);

    vector<int> test5 {10, 2, 3};
    assert(minSubArrayLen(6, test5) == 1);

    vector<int> test6 {2, 10, 3};
    assert(minSubArrayLen(6, test6) == 1);

    std::cout << "minSubArrayLen completed!" << std::endl;
}
