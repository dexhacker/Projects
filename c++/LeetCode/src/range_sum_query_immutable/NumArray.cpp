//
// Created by dexhacker on 4/29/21.
//

#include "NumArray.h"
#include <cassert>

range_sum_query_immutable::NumArray::NumArray(vector<int> &nums) {
    int sum = 0;
    for (auto number : nums) prefix.push_back(sum += number);
}

int range_sum_query_immutable::NumArray::sumRange(int left, int right) {
    if (left - 1 < 0) return prefix[right];

    return prefix[right] - prefix[left - 1];
}

void range_sum_query_immutable::NumArray::test() {
    vector<int> vector1 {-2, 0, 3, -5, 2, -1};
    auto *test1 = new NumArray(vector1);
    assert(test1->sumRange(0, 2) == 1);
    assert(test1->sumRange(2, 5) == -1);
    assert(test1->sumRange(0, 5) == -3);

    cout << "sumRange completed!" << endl;
}
