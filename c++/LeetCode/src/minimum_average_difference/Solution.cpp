//
// Created by dexhacker on 12/4/22.
//

#include "Solution.h"
#include <climits>
#include <cassert>

int minimum_average_difference::Solution::minimumAverageDifference(vector<int> &nums) {
    long sum = 0, n = nums.size(), prev_sum = 0, answer = 0, minimum = INT_MAX;
    for (long i : nums) sum += i;
    for (long i = 0; i < n; i++) {
        prev_sum += nums[i];
        sum -= nums[i];
        long result = prev_sum / (i + 1);

        if (n - (i + 1) > 0) result = abs(prev_sum / (i + 1) - sum / (n - (i + 1)));

        if (minimum > result) {
            minimum = result;
            answer = i;
        }
    }

    return answer;
}

void minimum_average_difference::Solution::test() {
    vector<int> test {2, 5, 3, 9, 5, 3};
    assert(minimumAverageDifference(test) == 3);

    cout << "minimumAverageDifference completed!" << endl;
}
