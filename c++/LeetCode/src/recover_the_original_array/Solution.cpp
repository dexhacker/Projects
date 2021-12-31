//
// Created by Фарид Абдугалыев on 31.12.2021.
//

#include "Solution.h"
#include <cassert>

vector<int> recover_the_original_array::Solution::recoverArray(vector<int> &nums) {
    const int n = nums.size() / 2;
    sort(nums.begin(), nums.end());
    for (int ii = 1; ii < 2 * n; ++ii) {
        int k = nums[ii] - nums[0];
        if (k % 2 != 0 || k == 0)
            continue;
        k /= 2;
        vector<int> res;
        vector<bool> used(2 * n);
        int j = 1;
        bool fail = false;
        for (int i = 0; i < 2 * n; ++i) {
            if (used[i])
                continue;
            res.push_back(nums[i] + k);
            used[i] = true;
            for ( ; j < 2 * n; ++j) {
                if (used[j])
                    continue;
                if (nums[j] >= nums[i] + 2 * k)
                    break;
            }
            if (j >= 2 * n || nums[j] > nums[i] + 2 * k) {
                fail = true;
                break;
            }
            used[j] = true;
        }
        if (!fail)
            return res;
    }
    return {};
}

void recover_the_original_array::Solution::test() {
    vector<int> test1 {2, 10, 6, 4, 8, 12};
    vector<int> answer1 {3, 7, 11};
    assert(recoverArray(test1) == answer1);

    vector<int> test2 {1, 1, 3, 3};
    vector<int> answer2 {2, 2};
    assert(recoverArray(test2) == answer2);

    vector<int> test3 {5, 435};
    vector<int> answer3 {220};
    assert(recoverArray(test3) == answer3);

    cout << "recoverArray completed!" << endl;
}
