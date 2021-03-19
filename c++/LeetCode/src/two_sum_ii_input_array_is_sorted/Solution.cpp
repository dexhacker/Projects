//
// Created by dexhacker on 3/17/21.
//

#include "Solution.h"
#include <cassert>

vector<int> two_sum_ii_input_array_is_sorted::Solution::twoSum(vector<int> &numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;

    while (l < r) {
        if (numbers[l] + numbers[r] == target)
            return {l + 1, r + 1};
        if (numbers[l] + numbers[r] > target)
            r--;
        else
            l++;
    }

    return {};
}

void two_sum_ii_input_array_is_sorted::Solution::test() {
    vector<int> test1 {2, 7, 11, 15};
    vector<int> answer1 {1, 2};
    assert(twoSum(test1, 9) == answer1);

    vector<int> test2 {2, 3, 4};
    vector<int> answer2 {1, 3};
    assert(twoSum(test2, 6) == answer2);

    vector<int> test3 {-1, 0};
    vector<int> answer3 {1, 2};
    assert(twoSum(test3, -1) == answer3);

    std::cout << "twoSum completed!" << std::endl;
}
