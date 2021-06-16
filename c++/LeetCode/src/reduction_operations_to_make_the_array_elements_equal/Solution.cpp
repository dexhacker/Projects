//
// Created by dexhacker on 6/6/21.
//

#include "Solution.h"
#include <cassert>

int reduction_operations_to_make_the_array_elements_equal::Solution::reductionOperations(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int answer = 0;
    int count = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) count++;
        answer += count;
    }
    return answer;
}

void reduction_operations_to_make_the_array_elements_equal::Solution::test() {
    vector<int> test {1, 1, 2, 2, 3};
    assert(reductionOperations(test) == 4);

    cout << "reductionOperations completed!" << endl;
}
