//
// Created by Фарид Абдугалыев on 01.01.2022.
//

#include "Solution.h"
#include <cassert>

int search_in_rotated_sorted_array::Solution::find_rotated_index(vector<int> &nums) {
    int min_index = nums.size() - 1;
    int max_index = 0;

    while (max_index + 1 < min_index) {
        int middle_index = (min_index + max_index) / 2;
        if (nums[middle_index] > nums[max_index]) max_index = middle_index;
        if (nums[middle_index] < nums[min_index]) min_index = middle_index;
    }

    return max_index;
}

int search_in_rotated_sorted_array::Solution::find_target(vector<int> &nums, int l, int r, int target) {
    if (nums[l] == target) return l;
    if (nums[r] == target) return r;
    int middle = (l + r) / 2;
    if (middle == l) return -1;
    if (nums[middle] == target) return middle;
    if (nums[middle] > target) {
        return find_target(nums, l, middle, target);
    } else {
        return find_target(nums, middle, r, target);
    }
}

int search_in_rotated_sorted_array::Solution::search(vector<int> &nums, int target) {
    if (nums[0] > nums.back()) {
        int rotated_index = find_rotated_index(nums);
        if (nums[0] <= target && target <= nums[rotated_index]) {
            return find_target(nums, 0, rotated_index, target);
        }

        if (nums[rotated_index + 1] <= target && target <= nums.back()) {
            return find_target(nums, rotated_index + 1, nums.size() - 1, target);
        }

        return -1;
    } else {
        return find_target(nums, 0, nums.size() - 1, target);
    }
}

void search_in_rotated_sorted_array::Solution::test() {
    vector<int> test1 {4, 5, 6, 7, 0, 1, 2};
    assert(search(test1, 0) == 4);

    vector<int> test2 {4, 5, 6, 7, 0, 1, 2};
    assert(search(test2, 3) == -1);

    vector<int> test3 {1};
    assert(search(test3, 0) == -1);

    cout << "search completed!" << endl;
}
