//
// Created by dexhacker on 3/17/21.
//

#include "Solution.h"
#include <cassert>

vector<int> product_of_array_except_self::Solution::productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    int left = 1, right = 1;
    vector<int> result(n, 1);
    for(int i = 0; i < n; i++){
        result[i] *= left;
        result[n - 1 - i] *= right;
        left *= nums[i];
        right *= nums[n - 1 - i];
    }
    return result;
}

void product_of_array_except_self::Solution::test() {
    vector<int> test1 {1, 2, 3, 4};
    vector<int> answer1 {24, 12, 8, 6};
    assert(productExceptSelf(test1) == answer1);

    vector<int> test2 {-1, 1, 0, -3, 3};
    vector<int> answer2 {0, 0, 9, 0, 0};
    assert(productExceptSelf(test2) == answer2);

    cout << "productExceptSelf completed!" << endl;
}
