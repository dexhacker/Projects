//
// Created by dexhacker on 3/17/21.
//

#include "Solution.h"
#include <cassert>
#include <set>

int third_maximum_number::Solution::thirdMax(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return (nums[0] > nums[1]) ? nums[0] : nums[1];

    int64_t max1 = INT64_MIN, max2 = INT64_MIN, max3 = INT64_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (max3 == nums[i] || max2 == nums[i] || max1 == nums[i])
            continue;

        if (nums[i] > max3) {
            max3 = nums[i];
            if (nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
                if (nums[i] > max1) {
                    max2 = max1;
                    max1 = nums[i];
                }
            }
        }
    }
    return (max3 == INT64_MIN) ? max1 : max3;
}

void third_maximum_number::Solution::test() {
    vector<int> test1 {3, 2, 1};
    assert(thirdMax(test1) == 1);

    vector<int> test2 {1, 2};
    assert(thirdMax(test2) == 2);

    vector<int> test3 {2, 2, 3, 1};
    assert(thirdMax(test3) == 1);

    vector<int> test4 {1, 1, 2};
    assert(thirdMax(test4) == 2);

    vector<int> test5 {1, 2, -2147483648};
    assert(thirdMax(test5) == -2147483648);

    cout << "thirdMax completed!" << endl;
}
