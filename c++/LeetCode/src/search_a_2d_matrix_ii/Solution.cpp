//
// Created by dexhacker on 4/21/21.
//

#include "Solution.h"
#include <cassert>

bool binary_search(vector<int> &nums, int start, int finish, int target) {
    int middle = (start + finish) / 2;
    if (nums[middle] == target) return true;
    if (start >= finish) return false;
    if (nums[middle] < target)
        return binary_search(nums, middle + 1, finish, target);
    else
        return binary_search(nums, start, middle - 1, target);
}

bool search_a_2d_matrix_ii::Solution::searchMatrix(vector<vector<int>> &matrix, int target) {
    for (auto & row : matrix) if (binary_search(row, 0, row.size() - 1, target)) return true;
    return false;
}

void search_a_2d_matrix_ii::Solution::test() {
    vector<vector<int>> test1 {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    assert(searchMatrix(test1, 5) == true);

    vector<vector<int>> test2 {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    assert(searchMatrix(test2, 20) == false);

    cout << "searchMatrix completed!" << endl;
}
