//
// Created by dexhacker on 6/28/21.
//

#include "Solution.h"
#include <numeric>
#include <cassert>

void count_of_smaller_numbers_after_self::Solution::merge_countSmaller(vector<int> &indices, int first, int last,
                                                                       vector<int> &results, vector<int> &nums) {
    int count = last - first;
    if (count > 1) {
        int step = count / 2;
        int mid = first + step;
        merge_countSmaller(indices, first, mid, results, nums);
        merge_countSmaller(indices, mid, last, results, nums);
        vector<int> tmp;
        tmp.reserve(count);
        int idx1 = first;
        int idx2 = mid;
        int semicount = 0;
        while ((idx1 < mid) || (idx2 < last)) {
            if ((idx2 == last) || ((idx1 < mid) &&
                                   (nums[indices[idx1]] <= nums[indices[idx2]]))) {
                tmp.push_back(indices[idx1]);
                results[indices[idx1]] += semicount;
                ++idx1;
            } else {
                tmp.push_back(indices[idx2]);
                ++semicount;
                ++idx2;
            }
        }
        move(tmp.begin(), tmp.end(), indices.begin()+first);
    }
}

vector<int> count_of_smaller_numbers_after_self::Solution::countSmaller(vector<int> &nums) {
    int n = nums.size();
    vector<int> results(n, 0);
    vector<int> indices(n, 0);
    iota(indices.begin(), indices.end(), 0);
    merge_countSmaller(indices, 0, n, results, nums);
    return results;
}

void count_of_smaller_numbers_after_self::Solution::test() {
    vector<int> test {5, 2, 6, 1};
    vector<int> answer {2, 1, 1, 0};
    assert(countSmaller(test) == answer);

    cout << "countSmaller completed!" << endl;
}
