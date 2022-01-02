//
// Created by Фарид Абдугалыев on 02.01.2022.
//

#include "Solution.h"
#include <cassert>

void find_first_and_last_position_of_element_in_sorted_array::Solution::find(vector<int> &nums, int l, int r, int target) {
    if (r < l) return;

    int middle = (r + l) / 2;
    if (nums[middle] < target) {
        find(nums, middle + 1, r, target);
    } else if (nums[middle] > target) {
        find(nums, l, middle -1, target);
    } else {
        if (start == -1 && finish == -1) {
            start = middle;
            finish = middle;
        } else {
            if (middle < start) start = middle;
            if (middle > finish) finish = middle;
        }
        find(nums, middle + 1, r, target);
        find(nums, l, middle - 1, target);
    }
}

vector<int> find_first_and_last_position_of_element_in_sorted_array::Solution::searchRange(vector<int> &nums, int target) {
    start = -1;
    finish = -1;
    find(nums, 0, nums.size() - 1, target);

    return {start, finish};
}

void find_first_and_last_position_of_element_in_sorted_array::Solution::test() {
    vector<int> test1 {5, 7, 7, 8, 8, 10};
    vector<int> answer1 {3, 4};
    assert(searchRange(test1, 8) == answer1);

    vector<int> test2 {5, 7, 7, 8, 8, 10};
    vector<int> answer2 {-1, -1};
    assert(searchRange(test2, 6) == answer2);

    vector<int> test3 {};
    vector<int> answer3 {-1, -1};
    assert(searchRange(test3, 0) == answer3);

    cout << "searchRange completed!" << endl;
}
