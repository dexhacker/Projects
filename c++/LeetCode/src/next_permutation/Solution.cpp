//
// Created by Фарид Абдугалыев on 25.12.2021.
//

#include "Solution.h"
#include <cassert>

void next_permutation::Solution::nextPermutation(vector<int> &nums) {
    if (nums.size() < 2) return;

    int max = nums.back();
    int index = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] >= max) {
            max = nums[i];
            index = i;
        } else {
            break;
        }
    }

    if (index == nums.size() - 1) {
        int tmp = nums.back();
        nums[nums.size() - 1] = nums[nums.size() - 2];
        nums[nums.size() - 2] = tmp;
    } else {
        int prev_index = index - 1;
        if (prev_index < 0) {
            sort(nums.begin(), nums.end());
        } else {
            int index_to_swap = index;
            int min = max;
            for (int i = index; i < nums.size(); i++) {
                if (nums[i] > nums[prev_index] && nums[i] < min) {
                    index_to_swap = i;
                    min = nums[i];
                }
            }

            int tmp = nums[prev_index];
            nums[prev_index] = nums[index_to_swap];
            nums[index_to_swap] = tmp;
            sort(nums.begin() + index, nums.end());
        }
    }
}

void next_permutation::Solution::test() {
    vector<int> test1 {1,2,3};
    vector<int> answer1 {1,3,2};
    nextPermutation(test1);
    assert(test1 == answer1);

    vector<int> test2 {3,2,1};
    vector<int> answer2 {1,2,3};
    nextPermutation(test2);
    assert(test2 == answer2);

    vector<int> test3 {1,1,5};
    vector<int> answer3 {1,5,1};
    nextPermutation(test3);
    assert(test3 == answer3);

    cout << "nextPermutation completed!" << endl;
}
