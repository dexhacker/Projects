//
// Created by dexhacker on 7/19/21.
//

#include "Solution.h"
#include <cassert>

vector<int> three_equal_parts::Solution::threeEqualParts(vector<int> &arr) {
    int ones = 0;
    for (auto i : arr) if (i == 1) ++ones;

    if (ones == 0) return {0, 2};
    if (ones % 3 != 0) return {-1, -1};

    int ones_per_part = ones / 3;
    vector<int> answer;

    int count = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 1) ++count;
        if (count == ones_per_part and answer.size() < 2) {
            answer.push_back(i + answer.size());
            count = 0;
        }
    }

    int right_zeros = 0;
    int index = arr.size() - 1;
    while (arr[index] == 0) {
        ++right_zeros;
        --index;
    }

    int current_right_zeros = 0;
    index = answer[1];
    while (arr[index] == 0) {
        ++current_right_zeros;
        ++index;
    }

    if (current_right_zeros >= right_zeros) {
        answer[1] += right_zeros;
    } else {
        return {-1, -1};
    }

    current_right_zeros = 0;
    index = answer[0] + 1;
    while (arr[index] == 0) {
        ++current_right_zeros;
        ++index;
    }

    if (current_right_zeros >= right_zeros) {
        answer[0] += right_zeros;
    } else {
        return {-1, -1};
    }

    int i = 0;
    while (arr[i] == 0) ++i;

    int j = answer[0] + 1;
    while (arr[j] == 0) ++j;

    int k = answer[1];
    while (arr[k] == 0) ++k;

    while (k < arr.size()) {
        if (arr[i] == arr[j] and arr[j] == arr[k]) {
            ++i;
            ++j;
            ++k;
            continue;
        }

        return {-1, -1};
    }

    return answer;
}

void three_equal_parts::Solution::test() {
    vector<int> test {1, 0, 1, 0, 1};
    vector<int> answer {0, 3};
    assert(threeEqualParts(test) == answer);

    cout << "threeEqualParts completed!" << endl;
}
