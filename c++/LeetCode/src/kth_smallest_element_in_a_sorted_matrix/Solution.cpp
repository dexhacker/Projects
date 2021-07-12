//
// Created by dexhacker on 7/8/21.
//

#include "Solution.h"
#include <cassert>

int kth_smallest_element_in_a_sorted_matrix::Solution::kthSmallest(vector<vector<int>> &matrix, int k) {
    vector<int> numbers;
    for (auto row : matrix) {
        for (auto i : row) {
            numbers.push_back(i);
        }
    }
    sort(numbers.begin(), numbers.end());
    return numbers[k - 1];
}

void kth_smallest_element_in_a_sorted_matrix::Solution::test() {
    vector<vector<int>> test {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    assert(kthSmallest(test, 8) == 13);

    cout << "kthSmallest completed!" << endl;
}
